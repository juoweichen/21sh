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

void	env_builtin(t_exec *exec, char **arg)
{
	t_list *ptr;

	arg = NULL;
	ptr = exec->env_dict->iter;
	while (ptr)
	{
		ft_printf("%s=%s\n", ptr->content,
			dict_get(exec->env_dict, ptr->content));
		ptr = ptr->next;
	}
}
