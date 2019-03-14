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

void	unset_from_env_list(t_list **cur, t_list **pre, t_exec *exec)
{
	if (*pre == NULL)
	{
		exec->env_list = exec->env_list->next;
		ft_strdel(&((t_env *)(*cur)->content)->name);
		ft_strdel(&((t_env *)(*cur)->content)->value);
		ft_lstdelone(cur, ft_lstdel_content);
		*cur = exec->env_list;
	}
	else
	{
		(*pre)->next = (*cur)->next;
		ft_strdel(&((t_env *)(*cur)->content)->name);
		ft_strdel(&((t_env *)(*cur)->content)->value);
		ft_lstdelone(cur, ft_lstdel_content);
		*cur = (*pre)->next;
	}
}

void	unsetenv_builtin(t_exec *exec, char **arg)
{
	t_list	*cur;
	t_list	*pre;

	if (arg[1] && !arg[2])
	{
		pre = NULL;
		cur = exec->env_list;
		while (cur)
		{
			if (ft_strequ(((t_env *)cur->content)->name, arg[1]))
			{
				unset_from_env_list(&cur, &pre, exec);
				return ;
			}
			pre = cur;
			cur = cur->next;
		}
		ft_printf("%s: environments not found\n", arg[1]);
	}
	else
		ft_putendl("wrong arguments");
}
