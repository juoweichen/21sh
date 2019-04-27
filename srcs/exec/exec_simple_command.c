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

void	handle_redirect(t_exec_sc *exec_sc)
{
	if (exec_sc->redirect_op == NULL || exec_sc->redirect_des == NULL)
		return ;
	if (ft_strequ(exec_sc->redirect_op, ">") == 1)
		redirect_great(exec_sc);
	else if (ft_strequ(exec_sc->redirect_op, "<") == 1)
		redirect_less(exec_sc);
	else if (ft_strequ(exec_sc->redirect_op, ">>") == 1)
		redirect_dgreat(exec_sc);
	else if (ft_strequ(exec_sc->redirect_op, ">&") == 1)
		redirect_greatand(exec_sc);
	else if (ft_strequ(exec_sc->redirect_op, "<&") == 1)
		redirect_lessand(exec_sc);
}

void	run(t_exec *exec, t_exec_sc *exec_sc)
{
	if (check_built_in(exec, exec_sc) == 1)
		return ;
	if (fork() == 0)
	{
		if (exec_sc->redirect_op != NULL)
			handle_redirect(exec_sc);
		if (exec_sc->piperead != -1)
			dup2(exec_sc->piperead, STDIN_FILENO);
		if (exec_sc->pipewrite != -1)
			dup2(exec_sc->pipewrite, STDOUT_FILENO);
		if (run_command(exec, exec_sc->argv[0], exec_sc->argv) < 0)
			exit(1);
		exit(0);
	}
	else
		wait(NULL);
}

void	init_run(t_astnode *astree, t_exec_sc *exec_sc,
	int piperead, int pipewrite)
{
	if (astree->type == NODE_SIMPLE_COMMAND)
	{
		init_run_count_argv(astree, exec_sc);
		exec_sc->argv = (char **)ft_memalloc((exec_sc->argc + 1) *
			sizeof(char *));
		init_run_store_argv(astree, exec_sc);
	}
	else
	{
		exec_sc->argc = 1;
		exec_sc->argv = (char **)ft_memalloc((exec_sc->argc + 1) *
			sizeof(char *));
		exec_sc->argv[0] = ft_strdup(astree->data);
		exec_sc->argv[1] = NULL;
	}
	exec_sc->piperead = piperead;
	exec_sc->pipewrite = pipewrite;
}

void	execute_simple_command(t_astnode *astree, t_exec *exec,
	int piperead, int pipewrite)
{
	t_exec_sc exec_sc;

	if (astree == NULL)
		return ;
	ft_bzero(&exec_sc, sizeof(t_exec_sc));
	init_run(astree, &exec_sc, piperead, pipewrite);
	run(exec, &exec_sc);
	ft_mstrdel_rows(&exec_sc.argv, exec_sc.argc);
	ft_strdel(&exec_sc.redirect_op);
	ft_strdel(&exec_sc.redirect_src);
	ft_strdel(&exec_sc.redirect_des);
}
