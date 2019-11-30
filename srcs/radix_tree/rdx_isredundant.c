/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdx_isredundant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:42:45 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/20 16:42:47 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/radix_tree.h"

/*
** Rules to know if a internal node is Redundant:
** [ Node is not the root node ] -- so you shouldnt input the root --  and [ Node has only 1 child node ]
*/

int	rdx_isredundant(t_trie *node)
{
	if (count_trie_children(node) == 1 && node->eow == 0)
		return (1);
	return (0);
}

