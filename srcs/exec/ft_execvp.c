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

int		run_executable(char **cmd, char *exec_path)
{
	extern char **environ;
	pid_t		pid;
	char		*full_path;

	full_path = ft_strjoin_btw(exec_path, cmd[0], '/');
	pid = fork();
	// signal(2, exec_signal_handler);
	if (pid == 0)
	{
		if (execve(full_path, cmd, environ) < 0)
			perror("execve failed");
		exit(0);
	}
	else
		wait(NULL);
	ft_strdel(&full_path);
	return (1);
}

int		find_fullpath(char **cmd)
{
	extern char	**environ;
	pid_t		pid;
	int			status;

	pid = fork();
	// signal(2, exec_signal_handler);
	if (pid == 0)
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

int ft_execvp(char *cmd_name, char **cmd_line)
{
	extern char **environ;
	int i;
	char **path_arr = NULL;

	DIR			*dirptr;
	struct		dirent	*entry;
	int 		res;

	//grab path in environ
	i = -1;
	while (environ[++i] != NULL)
	{
		if (ft_strncmp(environ[i], "PATH=", 5) == 0)
			path_arr = ft_strsplit(environ[i] + 5, ':');
	}
	//if couldn't found from path
	if (path_arr == NULL)
		return (-1);
	//try if user input full path
	if (find_fullpath(cmd_line) == 1)
		return (1);
	//find if cmd exist in $(path)
	i = 0;
	while (path_arr[i])
	{
		if ((dirptr = opendir(path_arr[i])) == NULL)
			return (-1);
		while ((entry = readdir(dirptr)))
			if (ft_strequ(entry->d_name, cmd_name))
				res = run_executable(cmd_line, path_arr[i]);
		closedir(dirptr);
		i++;
	}
	return (res);
}