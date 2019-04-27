/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:09:17 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/18 15:09:17 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	looking for $(*) in str
**	assuming *str == '$'
**	returns the length of the argument between parenthesis
*/

#include "../../includes/42sh.h"

int				has_valid_command_sub(char *str)
{
	int			has_command_sub;
	int			i;
	int			j;

	has_command_sub = 0;
	i = -1;
	j = ft_strlen(str);
	while (i < j)
	{
		if (str[i] == '$' && str[i + 1] == '(')
		{
			has_command_sub = 1;
			while (str[--j] != ')')
				if (i == j)
					return (0);
		}
		i++;
	}
	return (has_command_sub);
}

/*
**	Take a string such as "ABC$(echo "123")DEF"
**	and end with: ABC123DEF
**	Command subbing can exist within a command sub
*/

void			run_exe(const char *exe_path, char **args, char **envs)
{
	pid_t		child;

	child = fork();
	if (child < 0)
		ft_printf("error: fork()\n");
	else if (child == 0)
	{
		execve(exe_path, args, envs);
		exit(0);
	}
	else
		wait(&child);
}

char			*execute_command_sub(char *str)
{
	char		*temp;
	char		**command_and_args;
	int			i;

	i = 0;
	while (str[i] != ')' && str[i] != '\0')
		i++;
	temp = ft_strndup(str, i);
	ft_printf("temp: %s\n", temp);
	command_and_args = ft_strsplit(temp, ' ');
	free(temp);
	temp = NULL;
	run_exe(*command_and_args, command_and_args + 1, NULL);
	return (ft_strdup("|||"));
}

char			*expand_command_sub(char *str)
{
	char		*temp;
	char		*ret;
	int			i;

	temp = NULL;
	ret = NULL;
	i = ft_strlen(str);
	while (str[--i] >= 0)
	{
		ft_printf("%c", str[i]);
		if (str[i] == '$' && str[i + 1] == '(')
		{
			ft_printf("\nqwer\n");
			temp = ft_strjoin_free(ft_strdup(str + i + 2),
				execute_command_sub(str + i + 2));
			if (ret == NULL)
				ret = temp;
			else
				ret = ft_strjoin_free(temp, ret);
		}
	}
	ft_printf("\n");
	return (ret);
}
