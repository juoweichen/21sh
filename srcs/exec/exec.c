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

void execute_command(t_astnode *astree, int piperead, int pipewrite)
{
	execute_simple_command(astree, piperead, pipewrite);
}

void execute_pipe_sequence(t_astnode *astree, int lastread, int lastwrite)
{
	int fd[2];
	pid_t pid;

	if (astree == NULL)
		return ;
	if (astree->type != NODE_PIPE_SEQUENCE)	//last or only command
	{
		close(lastwrite);
		execute_command(astree, lastread, -1);
		close(lastread);
		return ;
	}
	if (pipe(fd) < 0 || (pid = fork()) < 0)
	{
		perror("pipe_sequence failed");
		exit(1);
	}
	if (pid == 0) //child process	
	{
		if (lastread == -1 && lastwrite == -1)	//first command
			execute_command(astree->left, -1, fd[1]);
		else 	//middle
		{
			close(lastwrite);
			execute_command(astree->left, lastread, fd[1]);
			close(lastread);
		}
		exit(0);
	}
	else	//parent process
	{
		if (astree->type == NODE_PIPE_SEQUENCE)
			execute_pipe_sequence(astree->right, fd[0], fd[1]);
	}
}

void execute_pipeline(t_astnode *astree)
{
	execute_pipe_sequence(astree, -1 , -1);
}

void execute_and_or(t_astnode *astree)
{
	execute_pipeline(astree);
}

void execute_list(t_astnode *astree)
{
	if (ft_strcmp(astree->data, ";") == 0)
	{
		execute_and_or(astree->left);
		execute_list(astree->right);
	}
	else
		execute_and_or(astree);
}

void execute_complete_command(t_astnode *astree)
{
	if (astree == NULL)
		return ;
	if (astree->type == NODE_PIPE_SEQUENCE)
		execute_pipe_sequence(astree, -1, -1);
	if (astree->type == NODE_LIST)
		execute_list(astree);
	else
		execute_simple_command(astree, -1, -1);
}

void execute_astree(t_astnode *astree)
{
	execute_complete_command(astree);
}