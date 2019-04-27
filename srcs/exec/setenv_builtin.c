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

#include "../../includes/exec.h"

void	setenv_builtin(t_exec *exec, char **arg)
{
	char	**split;

	if (arg[1] && ft_strchr(arg[1], '=') != NULL && !arg[2])
	{
		split = ft_strsplit(arg[1], '=');
		dict_add(exec->env_dict, split[0], split[1], ft_strlen(split[1]));
		ft_mstrdel_rows(&split, 2);
	}
	else if ((arg[1] && ft_strchr(arg[1], '=') == NULL) &&
		(arg[2] && ft_strchr(arg[2], '=') == NULL) && !arg[3])
		dict_add(exec->env_dict, arg[1], arg[2], ft_strlen(arg[2]));
	else
		ft_putendl("wrong arguments");
}