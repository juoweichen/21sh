/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_trie_leaf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 01:32:32 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/21 01:32:33 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prefix_tree.h"

int	is_trie_leaf(t_trie *node)
{
	int i;

	i = 0;
	while (i < ALPHABET)
	{
		if (node->alphabet[i] != NULL)
			return (0);
		i++;
	}
	return (1);
}
