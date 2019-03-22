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

t_env	*get_env(t_exec *exec, char *name)
{
	t_list *cur;

	cur = exec->env_list;
	while (cur)
	{
		if (ft_strequ(((t_env *)cur->content)->name, name))
			return (cur->content);
		cur = cur->next;
	}
	return (NULL);
}

void	create_env_list(t_exec *exec)
{
	extern char **environ;
	char		**env_split;
	t_env		new_env;

	exec->env_num = 0;
	while (environ[exec->env_num])
	{
		env_split = ft_strsplit(environ[exec->env_num], '=');
		new_env.name = ft_strdup(env_split[0]);
		new_env.value = ft_strdup(env_split[1]);
		if (exec->env_list == NULL)
			exec->env_list = ft_lstnew(&new_env, sizeof(t_env));
		else
			ft_lstaddend(&exec->env_list, ft_lstnew(&new_env, sizeof(t_env)));
		ft_mstrdel_rows(&env_split, 2);
		exec->env_num++;
	}
}

void free_env_list(t_list **env_list)
{
	t_list *next;

	if (*env_list == NULL)
		return ;
	while (*env_list)
	{
		next = (*env_list)->next;
		ft_strdel(&((t_env *)((*env_list)->content))->name);
		ft_strdel(&((t_env *)((*env_list)->content))->value);
		ft_memdel((void **)&(*env_list)->content);
		ft_memdel((void **)&(*env_list));
		(*env_list) = next;
	}
}