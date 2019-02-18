/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_dict		**dict_create(void)
{
	static t_dict	**hashtab;

	if ((hashtab = (t_dict **)ft_memalloc(sizeof(t_dict *) * HASHSIZE)) == NULL)
		return (NULL);
	return (hashtab);
}

int			dict_add(t_dict **dict, char *key, void *value, size_t value_size)
{
	t_dict		*np;
	unsigned	hashval;

	if (dict == NULL)
		return (0);
	if (!(np = dict_find(dict, key)))
	{
		np = (t_dict *)ft_memalloc(sizeof(t_dict));
		if (np == NULL || (np->key = ft_strdup(key)) == NULL)
			return (0);
		hashval = dict_hash(key);
		np->next = dict[hashval];
		dict[hashval] = np;
	}
	else
		free((void *)np->value);
	if ((np->value = ft_memalloc(value_size)) == NULL)
		return (0);
	ft_memcpy(np->value, value, value_size);
	return (1);
}

void		*dict_get(t_dict **dict, char *s)
{
	t_dict *np;

	if (dict == NULL)
		return (NULL);
	np = dict[dict_hash(s)];
	while (np != NULL)
	{
		if (ft_strcmp(s, np->key) == 0)
			return (np->value);
		np = np->next;
	}
	return (NULL);
}

int			dict_remove(t_dict **dict, char *s)
{
	t_dict *cur;
	t_dict *pre;

	if (dict == NULL)
		return (0);
	pre = NULL;
	cur = dict[dict_hash(s)];
	while (cur != NULL)
	{
		if (ft_strcmp(s, cur->key) == 0)
		{
			if (pre == NULL)
				dict[dict_hash(s)] = cur->next;
			else
				pre->next = cur->next;
			dict_free_elem(&cur);
			return (1);
		}
		pre = cur;
		cur = cur->next;
	}
	return (0);
}

void		dict_destory(t_dict ***dict)
{
	int		i;
	t_dict	*cur;
	t_dict	*next;

	if (*dict == NULL)
		return ;
	i = 0;
	while (i < HASHSIZE)
	{
		cur = (*dict)[i];
		while (cur)
		{
			next = cur->next;
			dict_free_elem(&cur);
			cur = next;
		}
		(*dict)[i] = NULL;
		i++;
	}
	free(*dict);
	*dict = NULL;
}
