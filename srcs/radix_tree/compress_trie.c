/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_trie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 01:48:00 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/21 01:48:02 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/radix_tree.h"

void	clean_radix_chain(t_trie *node)
{
	int i;

	i = 0;
	while (node->chain[i] != -1)
	{
		node->chain[i] = -1;
		i++;
	}
}

t_trie	*rdx_compress_nodes(t_trie *node, t_trie *chain)
{
	int i;

	i = 0;
	if (is_trie_leaf(chain) == 0)
	{
		clean_radix_chain(node);
		return (node);
	}
	node->eow = 1;
	clean_trie(node->alphabet[node->chain[0]]);
	return (node);
}
