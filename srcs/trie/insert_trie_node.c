/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_trie_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:50:18 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/18 17:50:20 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prefix_tree.h"

int	insert_word_trie(t_trie *root, char *word)
{
	int		where;
	int     i;

	i = 0;
	if (root == NULL || word[i] == '\0')
		return (0);
	while (word[i] != '\0')
	{
		where = word[i] - '+';
		if (where < 0 || where > ALPHABET)
		{
			ft_printf("Char %c not supported!\n", word[i]);
			return (0);
		}
		if (root->alphabet[where] == NULL)
			root->alphabet[where] = make_trie_node();
		i++;
		root = root->alphabet[where];
	}
	root->eow = 1;
	return (1);
}
