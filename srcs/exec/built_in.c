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

int is_builtin(char *com_name)
{
	if (ft_strequ(com_name, "echo") == 1 ||
		ft_strequ(com_name, "cd") == 1 ||
		ft_strequ(com_name, "env") == 1 ||
		ft_strequ(com_name, "set") == 1 ||
		ft_strequ(com_name, "unset") == 1 ||
		ft_strequ(com_name, "hash") == 1 ||
		ft_strequ(com_name, "type") == 1 ||
		ft_strequ(com_name, "exit") == 1 ||
		ft_strequ(com_name, "export") == 1)
		return (1);
	return (0);
}

int check_built_in(t_exec *exec, t_exec_sc *exec_sc)
{
	if (ft_strequ(exec_sc->argv[0], "echo") == 1)
		echo_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "cd") == 1)
		cd_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "env") == 1)
		env_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "set") == 1)
		set_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "unset") == 1)
		unset_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "hash") == 1)
		hash_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "type") == 1)
		type_builtin(exec, exec_sc->argv);
	else if (ft_strequ(exec_sc->argv[0], "exit") == 1)
		exit_builtin(exec, exec_sc->argv  );
	else if (ft_strequ(exec_sc->argv[0], "export") == 1)
		export_builtin(exec, exec_sc->argv  );
	else
		return (0);
	return (1);
}
