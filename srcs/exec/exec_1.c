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

void	execute_pipeline(t_astnode *astree, t_exec *exec)
{
	execute_pipe_sequence(astree, exec, -1, -1);
}

void	execute_and_or(t_astnode *astree, t_exec *exec)
{
	execute_pipeline(astree, exec);
}

void	execute_list(t_astnode *astree, t_exec *exec)
{
	if (ft_strequ(astree->data, ";") == 1)
	{
		execute_and_or(astree->left, exec);
		execute_list(astree->right, exec);
	}
	else
		execute_and_or(astree, exec);
}

void	execute_complete_command(t_astnode *astree, t_exec *exec)
{
	if (astree == NULL)
		return ;
	if (astree->type == NODE_PIPE_SEQUENCE)
		execute_pipe_sequence(astree, exec, -1, -1);
	else if (astree->type == NODE_LIST)
		execute_list(astree, exec);
	else
		execute_simple_cmd(astree, exec, -1, -1);
}

void	execute_astree(t_astnode *astree, t_sh *sh)
{
	t_exec exec;

	ft_bzero(&exec, sizeof(t_exec));
	exec.env_dict = sh->env_dict;
	exec.com_dict = sh->com_dict;
	exec.iv_dict = sh->iv_dict;
	execute_complete_command(astree, &exec);
}
