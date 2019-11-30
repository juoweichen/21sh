/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_prefix_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:04:33 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/18 16:04:34 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prefix_tree.h"

t_trie	*make_trie_node()
{
	t_trie	*new_node;
	int		i;

	i = 0;
	new_node = ft_memalloc(sizeof(t_trie));
	while (i < ALPHABET)
	{
		new_node->alphabet[i] = NULL;
		i++;
	}
	i = 0;
	new_node->eow = 0;
	while (i < MAX_CHAIN)
	{
		new_node->chain[i] = -1;
		i++;
	}
	return (new_node);
}
