/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_trie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:15:21 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/19 13:15:23 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prefix_tree.h"

void    clean_trie(t_trie *trie)
{
    int i;

    i = 0;
    if (trie == NULL)
        return ;
    while (i < ALPHABET)
    {
    	if (trie->alphabet[i] != NULL)
        	clean_trie(trie->alphabet[i]);
        i++;
    }
    ft_memdel((void*)trie);
}
