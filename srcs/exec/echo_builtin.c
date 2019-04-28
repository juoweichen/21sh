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

void	echo_builtin(t_exec *exec, char **arg)
{
	int	n_flag;
	int i;

	exec = NULL;
	i = 1;
	n_flag = 0;
	if (arg[i] && ft_strequ(arg[i], "-n") == 1)
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
