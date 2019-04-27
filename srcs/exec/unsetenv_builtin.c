/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:23:44 by juochen           #+#    #+#             */
/*   Updated: 2019/04/27 00:01:21 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	unsetenv_builtin(t_exec *exec, char **arg)
{
	if (arg[1] && !arg[2])
	{
		if (dict_remove(exec->env_dict, arg[1]) == 0)
			ft_printf("%s: environments not found\n", arg[1]);
	}
	else
		ft_putendl("wrong arguments");
}
