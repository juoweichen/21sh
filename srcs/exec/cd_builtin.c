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
	char	*pwd;
	char	*oldpwd;

	if ((pwd = dict_get(exec->com_dict, "PWD")) == NULL ||
		(oldpwd = dict_get(exec->com_dict, "OLDPWD")) == NULL ||
		next_dir == NULL)
		return ;
	dict_add(exec->com_dict, "OLDPWD", pwd, ft_strlen(pwd));
	dict_add(exec->com_dict, "PWD", next_dir, ft_strlen(next_dir));
}

void	cd_builtin(t_exec *exec, char **arg)
{
	char	*next_dir;
	char	*com_path;

	if (arg[1] == NULL && (com_path = dict_get(exec->com_dict, "HOME")) != NULL)
		next_dir = ft_strdup(com_path);
	else if (arg[2] == NULL)
	{
		if (ft_strequ(arg[1], "-") &&
			(com_path = dict_get(exec->com_dict, "OLDPWD")) != NULL)
			next_dir = ft_strdup(com_path);
		else if (arg[1][0] == '/')
			next_dir = ft_strdup(arg[1]);
		else
			next_dir = ft_strjoin_btw(getcwd(NULL, 0), arg[1], '/');
	}
	else
		return ;
	chdir(next_dir) != -1 ?
		update_pwd(exec, next_dir) : ft_printf("cd: no such directory\n");
	ft_strdel(&next_dir);
}
