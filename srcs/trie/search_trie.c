/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_trie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:40:01 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/19 11:40:02 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prefix_tree.h"

t_trie *search_trie(t_trie *root, char *key)
{
    t_trie  *tmp;
    int     i;
    int     where;

    tmp = root;
    i = 0;

    while (key[i] != '\0')
    {
        where = key[i] - START_ALPHA;
        if (!tmp->alphabet[where])
            return (0);
        tmp = tmp->alphabet[where];
        i++;
    }
    return (tmp);
}
