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

void	update_pwd(t_exec *exec, char *next_dir)
{
	t_env	*pwd;
	t_env	*oldpwd;
	char	*tmp;

	if ((pwd = get_env(exec, "PWD")) == NULL ||
		(oldpwd = get_env(exec, "OLDPWD")) == NULL ||
		next_dir == NULL)
		return ;
	tmp = ft_strdup(next_dir);
	ft_strdel(&oldpwd->value);
	oldpwd->value = ft_strdup(pwd->value);
	ft_strdel(&pwd->value);
	pwd->value = tmp;
}

void	cd_builtin(t_exec *exec, char **arg)
{
	char	*next_dir;
	char	*cwd;
	t_env	*env;

	cwd = NULL;
	if (arg[1] == NULL && (env = get_env(exec, "HOME")) != NULL)
		next_dir = ft_strdup(env->value);
	else if (arg[2] == NULL)
	{
		cwd = getcwd(cwd, 0);
		if (ft_strequ(arg[1], "-") && (env = get_env(exec, "OLDPWD")) != NULL)
			next_dir = ft_strdup(env->value);
		else if (arg[1][0] == '/')
			next_dir = ft_strdup(arg[1]);
		else
			next_dir = ft_strjoin_btw(cwd, arg[1], '/');
		ft_strdel(&cwd);
	}
	else
		return ;
	printf("%s\n", next_dir);
	chdir(next_dir) != -1 ?
		update_pwd(exec, next_dir) : ft_printf("cd: no such directory\n");
	ft_strdel(&next_dir);
}
