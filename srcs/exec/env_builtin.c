/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:25:47 by juochen           #+#    #+#             */
/*   Updated: 2018/12/11 21:25:49 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	env_builtin(t_exec *exec, char **arg)
{
	t_list *cur;

	if (arg[0] != NULL)
	{
		cur = exec->env_list;
		while (cur)
		{
			printf("%s=%s\n", ((t_env *)cur->content)->name,
				((t_env *)cur->content)->value);
			cur = cur->next;
		}
	}
	else
		ft_putendl("No arguments");
}
