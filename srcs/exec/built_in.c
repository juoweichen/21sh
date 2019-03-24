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

int check_built_in(t_exec *exec, t_exec_sc *exec_sc)
{
	if (ft_strequ(exec_sc->argv[0], "echo") == 1)
		echo_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "cd") == 1)
		cd_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "env") == 1)
		env_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "setenv"))
		setenv_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "unsetenv"))
		unsetenv_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "exit"))
		exit_builtin(exec);
	else
		return (0);
	return (1);
}
