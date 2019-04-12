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

void	type_builtin(t_exec *exec, char **arg)
{
	int		i;
	char	*statement;

	i = 1;
	while (arg[i] != NULL)
	{
		if (is_builtin(arg[i]) == 1)
			statement = "a shell builtin";
		else if ((statement = dict_get(exec->com_dict, arg[i])) == NULL)
			statement = "\b\b\bnot found";
		ft_printf("%s is %s\n", arg[i], statement);
		i++;
	}
}