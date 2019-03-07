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

void	echo_builtin(char **arg)
{
	int	n_flag;
	int i;

	i = 0;
	n_flag = 0;
	if (arg[i] && ft_strequ(arg[i], "-n"))
	{
		n_flag = 1;
		i++;
	}
	while (arg[i])
	{
		ft_putstr(arg[i++]);
		if (arg[i] != NULL)
			ft_putchar(' ');
	}
	if (n_flag == 0)
		ft_putchar('\n');
	else
		ft_putstr("\033[0;30;47m%\033[0m\n");
}

int check_built_in(t_exec_sc *exec_sc)
{
	if (ft_strequ(exec_sc->argv[0], "echo"))
		echo_builtin(exec_sc->argv);
	else
		return (0);
	return (1);
}

/*
	if (ft_strequ(cmd[0], "echo"))
		echo_builtin(m, ++cmd);
	else if (ft_strequ(cmd[0], "cd"))
		cd_builtin(m, ++cmd);
	else if (ft_strequ(cmd[0], "env"))
		env_builtin(m, ++cmd);
	else if (ft_strequ(cmd[0], "setenv"))
		setenv_builtin(m, ++cmd);
	else if (ft_strequ(cmd[0], "unsetenv"))
		unsetenv_builtin(m, ++cmd);
	else if (ft_strequ(cmd[0], "exit"))
		exit_builtin(m);
	else
		return (0);
	return (1);
*/