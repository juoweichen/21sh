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

void	find_repeat_env(t_exec *exec, char *new_name, char *new_value)
{
	t_env	*env;

	if ((env = get_env(exec, new_name)) != NULL)
	{
		ft_strdel(&env->value);
		env->value = new_value;
		ft_strdel(&new_name);
	}
	else
	{
		env = (t_env *)ft_memalloc(sizeof(t_env));
		env->name = new_name;
		env->value = new_value;
		ft_lstaddend(&exec->env_list, ft_lstnew(env, sizeof(t_env)));
		ft_memdel((void **)&env);
	}
}

void	setenv_builtin(t_exec *exec, char **arg)
{
	char	*new_name;
	char	*new_value;
	char	**split;

	split = NULL;
	if (arg[1] && ft_strchr(arg[1], '=') != NULL && !arg[2])
	{
		split = ft_strsplit(arg[1], '=');
		new_name = ft_strdup(split[1]);
		new_value = ft_strdup(split[2]);
		ft_mstrdel_rows(&split, 2);
		find_repeat_env(exec, new_name, new_value);
	}
	else if ((arg[1] && ft_strchr(arg[1], '=') == NULL) &&
		(arg[2] && ft_strchr(arg[2], '=') == NULL) && !arg[2])
	{
		new_name = ft_strdup(arg[1]);
		new_value = ft_strdup(arg[2]);
		find_repeat_env(exec, new_name, new_value);
	}
	else
		ft_putendl("wrong arguments");
}
