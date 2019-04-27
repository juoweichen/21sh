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

void	set_builtin(t_exec *exec, char **arg)
{
	t_list	*iv_iter;

	if (arg[1] == NULL)
	{
		iv_iter = exec->iv_dict->iter;
		while (iv_iter)
		{
			ft_printf("%s=%s\n", iv_iter->content,
				dict_get(exec->iv_dict, iv_iter->content));
			iv_iter = iv_iter->next;
		}
	}
}
