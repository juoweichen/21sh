/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:23:44 by juochen           #+#    #+#             */
/*   Updated: 2019/02/09 13:23:46 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/astree.h"
#include "../../includes/exec.h"

void execute_command(t_astnode *astree, t_exec *exec, int piperead, int pipewrite)
{
	execute_simple_command(astree, exec, piperead, pipewrite);
}

void execute_pipe_sequence(t_astnode *astree, t_exec *exec, int prevread, int prevwrite)
{
	int fd[2];
	pid_t pid;

	if (astree == NULL)
		return ;
	if (astree->type != NODE_PIPE_SEQUENCE)	//last or only command
	{
		close(prevwrite);
		execute_command(astree, exec, prevread, -1);
		close(prevread);
		return ;
	}
	if (prevwrite != -1)
		close(prevwrite);
	if (pipe(fd) < 0 || (pid = fork()) < 0)
	{
		perror("pipe_sequence failed");
		exit(1);
	}
	if (pid == 0) //child process	
	{
		if (prevread == -1 && prevwrite == -1)	//first command
		{
			execute_command(astree->left, exec, -1, fd[1]);
		}
		else 	//middle
		{
			close(prevwrite);
			execute_command(astree->left, exec, prevread, fd[1]);
			close(prevread);
		}
		exit(0);
	}
	else	//parent process
	{
		execute_pipe_sequence(astree->right, exec, fd[0], fd[1]);
	}
}

/* 
void execute_pipe_sequence(t_astnode *astree, int prevread, int prevwrite)
{
//for recursive
prevread = 0;
prevwrite = 0;

	int fd[2];
 	//pid_t pid;

	if (astree == NULL)
 		return ;
	if (pipe(fd) < 0)
	{
		perror("pipe");
		exit(1);
	}

	int pipewrite = fd[1];
    int piperead = fd[0];

	// if ((pid = fork()) < 0)
	// {
	// 	perror("fork");
	// 	exit(1);
	// }
	execute_command(astree->left, -1, pipewrite);
	astree = astree->right;
	while (astree != NULL && astree->type == NODE_PIPE_SEQUENCE)
	{
		close(pipewrite);
		if (pipe(fd) < 0)
		{
			perror("pipe in middle");
			exit(1);
		}
		pipewrite = fd[1];
		execute_command(astree->left, piperead, pipewrite);
		close(piperead);
        piperead = fd[0];
		astree = astree->right;
	}
	piperead = fd[0];
    close(pipewrite);

	execute_command(astree, piperead, -1);
	close(piperead);
}
*/
void execute_pipeline(t_astnode *astree, t_exec *exec)
{
	execute_pipe_sequence(astree, exec, -1, -1);
}

void execute_and_or(t_astnode *astree, t_exec *exec)
{
	execute_pipeline(astree, exec);
}

void execute_list(t_astnode *astree, t_exec *exec)
{
	if (ft_strequ(astree->data, ";") == 1)
	{
		execute_and_or(astree->left, exec);
		execute_list(astree->right, exec);
	}
	else
		execute_and_or(astree, exec);
}

void execute_complete_command(t_astnode *astree, t_exec *exec)
{
	if (astree == NULL)
		return ;
	if (astree->type == NODE_PIPE_SEQUENCE)
		execute_pipe_sequence(astree, exec, -1, -1);
	else if (astree->type == NODE_LIST)
		execute_list(astree, exec);
	else
		execute_simple_command(astree, exec, -1, -1);
}

void execute_astree(t_astnode *astree)
{
	t_exec exec;

	ft_bzero(&exec, sizeof(t_exec));
	create_env_list(&exec);
/*
//test
	printf("%zu\n", exec.env_num);
	t_list *ptr;
	ptr = exec.env_list;
	while (ptr)
	{
		printf("%s==>%s\n", ((t_env *)ptr->content)->name, ((t_env *)ptr->content)->value);
		ptr = ptr->next;
	}
//test end
*/
	execute_complete_command(astree, &exec);
	free_env_list(&exec.env_list);
}
