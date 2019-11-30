/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_trie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:43:47 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/18 21:43:49 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prefix_tree.h"

void    print_trie(t_trie *root, char *matching, int level, char *match)
{
	int		i;

	i = 0;
    if (root->eow == 1)
    {
        matching[level] = '\0';
        printf("%s%s\n", match, matching);
    }
    while (i < ALPHABET)
    {
        if (root->alphabet[i] != NULL)
        {
            matching[level] = (char)i + START_ALPHA;
            print_trie(root->alphabet[i], matching, level + 1, match);
        }
        i++;
    }
}

