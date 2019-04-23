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

void execute_command(t_astnode *astree, t_exec *exec,
	int piperead, int pipewrite)
{
	execute_simple_command(astree, exec, piperead, pipewrite);
}

void execute_pipe_sequence_pipe_and_fork(t_astnode *astree, t_exec *exec, 
	int prevread, int prevwrite)
{
	int fd[2];
	
	if (pipe(fd) < 0)
		exit(1);
	if (fork() == 0) //child process	
	{
		if (prevread == -1 && prevwrite == -1)	//first command
			execute_command(astree->left, exec, -1, fd[1]);
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
		wait(NULL);
	}
}

void execute_pipe_sequence(t_astnode *astree, t_exec *exec, 
	int prevread, int prevwrite)
{
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
	execute_pipe_sequence_pipe_and_fork(astree, exec, prevread, prevwrite);
}

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

void execute_astree(t_astnode *astree, t_sh *sh)
{
	t_exec exec;

	ft_bzero(&exec, sizeof(t_exec));
	exec.env_dict = sh->env_dict;
	exec.com_dict = sh->com_dict;
	exec.iv_dict = sh->iv_dict;
	execute_complete_command(astree, &exec);
}
