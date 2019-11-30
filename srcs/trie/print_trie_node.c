/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_trie_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:41:06 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/20 17:41:09 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prefix_tree.h"

void	print_chain_node(t_trie *root, t_trie *node)
{
	int i;

	i = 0;
	while (i < ALPHABET)
	{
		if (root == node)
		{
			ft_printf("%c", ((char)i + START_ALPHA));
			return ;
		}
		
	}
}

