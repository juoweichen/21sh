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

void 	env_init(t_sh *sh)
{
	extern char	**environ;
	char		**env_split;

	sh->env_dict = dict_init();
	while (environ[sh->env_dict->size])
	{
		env_split = ft_strsplit(environ[sh->env_dict->size], '=');
		dict_add(sh->env_dict, env_split[0], env_split[1],
			ft_strlen(env_split[1]));
		ft_mstrdel_rows(&env_split, 2);
	}
}