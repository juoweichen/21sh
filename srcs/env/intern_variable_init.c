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

#include "../../includes/env.h"

void 	intern_variable_init(t_sh *sh)
{
	t_list	*enviter;
	char	*tmp;

	sh->iv_dict = dict_init();
	//Store env variable to iv_dict
	enviter = sh->env_dict->iter;
	while (enviter)
	{
		tmp = dict_get(sh->env_dict, enviter->content);
		dict_add(sh->iv_dict, enviter->content, tmp, ft_strlen(tmp));
		enviter = enviter->next;
	}
	quick_sort_str_list(&sh->iv_dict->iter);
}