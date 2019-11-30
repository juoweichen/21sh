/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_trie_children.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:45:06 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/20 16:45:07 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prefix_tree.h"

int		count_trie_children(t_trie *root)
{
	int i;
	int child;

	i = 0;
	child = 0;
	if (root == NULL)
		return (-1);
	while (i < ALPHABET)
	{
		if (root->alphabet[i] != NULL)
			child++;
		i++;
	}
	return (child);
}

