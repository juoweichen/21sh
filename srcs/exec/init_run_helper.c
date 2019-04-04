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

void init_run_store_argv(t_astnode *astree, t_exec_sc *exec_sc)
{
	t_astnode *astptr;
	int i;

	//store to argv
	astptr = astree;
	i = 0;
	while (i < exec_sc->argc)
	{
		if (astptr->left != NULL)
			exec_sc->argv[i] = ft_strdup(astptr->left->data);
		else
			exec_sc->argv[i] = ft_strdup(astptr->data);
		astptr = astptr->right;
		i++;
	}
	exec_sc->argv[i] = NULL;
}

void init_run_count_argv(t_astnode *astree, t_exec_sc *exec_sc)
{
	t_astnode *astptr;

	astptr = astree;
	while (astptr)
	{
		if (astptr->type == NODE_IO_FILE)
		{
			exec_sc->redirect_op = ft_strdup(astptr->data);
			exec_sc->redirect_des = ft_strdup(astptr->right->data);
			break ;
		}
		if (astptr->type == NODE_IO_REDIRECT)
		{
			exec_sc->redirect_src = ft_strdup(astptr->data);
			exec_sc->redirect_op = ft_strdup(astptr->right->data);
			exec_sc->redirect_des = ft_strdup(astptr->right->right->data);
			break ;
		}
		exec_sc->argc += 1;
		astptr = astptr->right;
	}
}