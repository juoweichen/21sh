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

void delete_run(t_comp *comp)
{
	
}

void run(t_comp *comp)
{
	pid_t pid;

	if ((pid = fork()) == 0)
	{
		//child process
		//should use execve in here, but we need enviroment
		if (execvp(comp->argv[0], comp->argv) == -1)
		{
			printf("Command not found: \'%s\'\n", comp->argv[0]);
			exit(1);
		}
		exit(0);
	}
	else
	{
		//parent process
		waitpid(pid, NULL, 0);
	}
}

void init_run(t_astnode *astree, t_comp *comp)
{
	t_astnode *astptr;
	int i;

	if (astree->type == NODE_SIMPLE_COMMAND)
	{
		//count argc
		astptr = astree;
		while (astptr)
		{				
			comp->argc += 1;
			astptr = astptr->right;
		}
		comp->argv = (char **)ft_memalloc(comp->argc * sizeof(char *) + 1);
		//store to argv
		astptr = astree;
		i = 0;
		while (astptr)
		{
			if (astptr->left != NULL)
				comp->argv[i] = ft_strdup(astptr->left->data);
			else
				comp->argv[i] = ft_strdup(astptr->data);
			astptr = astptr->right;
			i++;
		}
		comp->argv[i] = NULL;
	}
	else
	{
		//only cmd_name
		comp->argc = 1;
		comp->argv = (char **)ft_memalloc(comp->argc * sizeof(char *) + 1);
		comp->argv[0] = ft_strdup(astree->data);
		comp->argv[1] = NULL;
	}
}

void execute_simple_command(t_astnode *astree, t_comp *comp)
{
	if (astree == NULL)
		return ;
	init_run(astree, comp);
	run(astree, comp);
	delete_run(astree, comp);
}

void execute_complete_command(t_astnode *astree, t_comp *comp)
{
	if (astree == NULL)
		return ;
	// //lol
	// if (astree->type == NODE_COMPLETE_COMMAND)
	// 	execute_list();
	// else
	// 	execute_list();s
	execute_simple_command(astree, comp);
}

void execute_astree(t_astnode *astree)
{
	t_comp comp;

	ft_bzero((void *)&comp, sizeof(t_comp));
	execute_complete_command(astree, &comp);
}