/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdx_reduntant_chain.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:00:36 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/20 17:00:38 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/radix_tree.h"

t_trie *get_only_child(t_trie *node)
{
	int i;

	i = 0;
	while (i < ALPHABET)
	{
		if (node->alphabet[i] != NULL)
			return (node->alphabet[i]);
		i++;
	}
	return (NULL);
}

/*
** rdx_redundant_chain starts from a node and returns the last redundant node of the chain
** a chain of edges is (v0,v1), (v1,v2), ..., (vk−1,vk)
** Nodes   v1, v2, ..., vk−1   are redundant
** //Nodes   v0   and   vk   are not redundant --so you shouldt input the root --
*/

t_trie	*rdx_redundant_chain(t_trie *node)
{
	int i;
	int j;
	t_trie *first;

	i = -1;
	j = 0;
	first = node;
	if (node == NULL || node->eow == 1)
		return (node);
	while (node->eow == 0)
	{
		if (rdx_isredundant(node) == 1)
		{
			while (i++ < ALPHABET)
			{
				if (node->alphabet[i] != NULL)
				{
					first->chain[j] = i;
					node = node->alphabet[i];
					j++;
					break ;
				}
			}
			if (node->eow == 0)
				i = -1;
		}
		else
			return (node);
	}
	while (i < ALPHABET)
	{
		if (node->alphabet[i] != NULL)
		{
			first->chain[j] = i;
			node = node->alphabet[i];
			j++;
			break ;
		}
		i++;
	}
	return (node);
}
