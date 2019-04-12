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

t_dict		*dict_init(void)
{
	t_dict				*dict;

	if ((dict = (t_dict *)ft_memalloc(sizeof(t_dict))) == NULL)
		return (NULL);
	if ((dict->tb = (t_dict_tab **)ft_memalloc(sizeof(t_dict_tab *)
		* HASHSIZE)) == NULL)
		return (NULL);
	dict->iter = NULL;
	dict->size = 0;
	return (dict);
}

int			dict_add(t_dict *dict, char *key, void *value, size_t value_size)
{
	t_dict_tab	*np;
	unsigned	hashval;

	if (dict == NULL)
		return (0);
	if (!(np = dict_find(dict, key)))
	{
		np = (t_dict_tab *)ft_memalloc(sizeof(t_dict_tab));
		if (np == NULL || (np->key = ft_strdup(key)) == NULL)
			return (0);
		hashval = dict_hash(key);
		np->next = dict->tb[hashval];
		dict->tb[hashval] = np;
		dict_iter_add(dict, key);
	}
	else
		free((void *)np->value);
	if ((np->value = ft_memalloc(value_size)) == NULL)
		return (0);
	ft_memcpy(np->value, value, value_size);
	return (1);
}

void		*dict_get(t_dict *dict, char *key)
{
	t_dict_tab *np;

	if (dict == NULL)
		return (NULL);
	np = dict->tb[dict_hash(key)];
	while (np != NULL)
	{
		if (ft_strcmp(key, np->key) == 0)
			return (np->value);
		np = np->next;
	}
	return (NULL);
}

int			dict_remove(t_dict *dict, char *key)
{
	t_dict_tab *cur;
	t_dict_tab *pre;

	if (dict == NULL)
		return (0);
	pre = NULL;
	cur = dict->tb[dict_hash(key)];
	while (cur != NULL)
	{
		if (ft_strcmp(key, cur->key) == 0)
		{
			if (pre == NULL)
				dict->tb[dict_hash(key)] = cur->next;
			else
				pre->next = cur->next;
			dict_free_elem(&cur);
			dict_iter_remove(dict, key);
			return (1);
		}
		pre = cur;
		cur = cur->next;
	}
	return (0);
}

void		dict_destory(t_dict **dict)
{
	int			i;
	t_dict_tab	*cur;
	t_dict_tab	*next;

	if (*dict == NULL)
		return ;
	i = 0;
	while (i < HASHSIZE)
	{
		cur = (*dict)->tb[i];
		while (cur)
		{
			next = cur->next;
			dict_free_elem(&cur);
			cur = next;
		}
		(*dict)->tb[i] = NULL;
		i++;
	}
	ft_lstdel(&(*dict)->iter, ft_lstdel_content);
	ft_memdel((void **)&(*dict)->tb);
	ft_memdel((void **)&dict);
}
