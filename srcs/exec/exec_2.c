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

void	execute_command(t_astnode *astree, t_exec *exec,\
	int piperead, int pipewrite)
{
	execute_simple_cmd(astree, exec, piperead, pipewrite);
}

void	execute_pipe_sequence_pipe_and_fork(t_astnode *astree, t_exec *exec,\
	int prevread, int prevwrite)
{
	int fd[2];

	if (pipe(fd) < 0)
		exit(1);
	if (fork() == 0)
	{
		if (prevread == -1 && prevwrite == -1)
			execute_command(astree->left, exec, -1, fd[1]);
		else
		{
			close(prevwrite);
			execute_command(astree->left, exec, prevread, fd[1]);
			close(prevread);
		}
		exit(0);
	}
	else
	{
		execute_pipe_sequence(astree->right, exec, fd[0], fd[1]);
		wait(NULL);
	}
}

void	execute_pipe_sequence(t_astnode *astree, t_exec *exec,\
	int prevread, int prevwrite)
{
	if (astree == NULL)
		return ;
	if (astree->type != NODE_PIPE_SEQUENCE)
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
