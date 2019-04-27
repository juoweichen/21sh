/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_variable_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:04:27 by kblack            #+#    #+#             */
/*   Updated: 2019/04/26 18:04:29 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void		intern_variable_init(t_sh *sh)
{
	t_list	*enviter;
	char	*tmp;

	sh->iv_dict = dict_init();
	enviter = sh->env_dict->iter;
	while (enviter)
	{
		tmp = dict_get(sh->env_dict, enviter->content);
		dict_add(sh->iv_dict, enviter->content, tmp, ft_strlen(tmp));
		enviter = enviter->next;
	}
	quick_sort_str_list(&sh->iv_dict->iter);
}
