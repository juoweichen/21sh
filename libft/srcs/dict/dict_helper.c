/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned	dict_hash(char *s)
{
	unsigned hashval;

	hashval = 0;
	while (*s != '\0')
		hashval = *(s++) + HASHNUMBER * hashval;
	return (hashval % HASHSIZE);
}

t_dict		*dict_find(t_dict **dict, char *s)
{
	t_dict *np;

	np = dict[dict_hash(s)];
	while (np != NULL)
	{
		if (ft_strcmp(s, np->key) == 0)
			return (np);
		np = np->next;
	}
	return (NULL);
}

void		dict_free_elem(t_dict **elem)
{
	ft_memdel((void **)&(*elem)->value);
	ft_strdel(&(*elem)->key);
	ft_memdel((void **)&(*elem));
}
