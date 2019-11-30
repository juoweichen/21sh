/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:00:06 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/18 18:00:07 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prefix_tree.h"

t_trie	*prefix_tree(char **dictionary)
{
	int             i;
	t_trie			*root;

	//dictionary = low_case(dictionary);
	root = make_trie_node();
	i = 0;
	while (dictionary[i] != NULL)
	{
	    if (insert_word_trie(root, dictionary[i]) == 0)
	    {
            clean_trie(root);
            return (NULL);
        }
		i++;
	}
	return (root);
}