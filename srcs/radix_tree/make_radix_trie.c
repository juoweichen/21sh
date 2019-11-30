/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_radix_trie.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:28:42 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/21 02:28:44 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/radix_tree.h"

static t_trie	*process_node(t_trie *node)
{
	t_trie *end_of_chain;

	end_of_chain = rdx_redundant_chain(node);
	if (end_of_chain == node)
		return (node);
	else
		return (rdx_compress_nodes(node, end_of_chain));
}

t_trie	*make_radix_tree(t_trie *root)
{
	int i;
	t_trie *new;
	t_trie *begin;

	i = 0;
	begin = root;
	while (i < ALPHABET)
	{
		if (root->alphabet[i] != NULL)
		{
			new = root->alphabet[i];
			if (rdx_isredundant(root->alphabet[i]) == 1)	// if only child
				new = process_node(root->alphabet[i]);	// check and compress if the chain is redundant
			if (root->alphabet[i] == new)				// if not compressed
				make_radix_tree(root->alphabet[i]);
			else	// if compressed
				root->alphabet[i] = new;
		}
		i++;
	}
	return (begin);
}
