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

void 	print_export(t_exec *exec, int is_option_p)
{
	char *arr[exec->env_dict->size];

	ft_bzero(arr, sizeof(char *) * exec->env_dict->size);
	//store 
	is_option_p = 1;
}

void	export_builtin(t_exec *exec, char **arg)
{
	//if add new PATH, re-build com_dict
	if (arg[1] == NULL)
	{
		print_export(exec, 0);
	}
}
