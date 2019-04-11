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

int		find_fullpath(char **cmd, char **environ)
{
	int			status;

	// signal(2, exec_signal_handler);
	if (fork() == 0)
	{
		if (execve(cmd[0], cmd, environ) < 0)
			exit(1);
		exit(0);
	}
	else
	{
		wait(&status);
		if (status == 0 || status == 2)
			return (1);
	}
	return (0);
}

int run_command(t_exec *exec, char *cmd_name, char **cmd_line)
{
	extern char	**environ;
	char		*full_path;

	//try if user input full path
	if (find_fullpath(cmd_line, environ) == 1)
		return (1);
	//find command name from com_dict
	if ((full_path = dict_get(exec->com_dict, cmd_name)) != NULL)
	{
		// signal(2, exec_signal_handler);
		if (fork() == 0)
		{
			if (execve(full_path, cmd_line, environ) < 0)
				perror("execve failed");
			exit(0);
		}
		else
			wait(NULL);
		return (1);
	}
	ft_printf("Command not found: \'%s\'\n", cmd_name);
	return (-1);
}