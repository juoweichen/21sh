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

void	hash_builtin(t_exec *exec)
{
	t_list *iter;

	iter = exec->com_dict->iter;
	while (iter)
	{
		ft_printf("%s=%s\n", iter->content,
			dict_get(exec->com_dict, iter->content));
		iter = iter->next;
	}
}
