/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_radix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:59:33 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/22 17:59:35 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/radix_tree.h"

static int	check_chain(char *key, int *chain, int i)
{
	int j;

	j = 0;
	while (key[i] != '\0')
	{
		if (key[i] != ((char)chain[j] + START_ALPHA))
			return (1);
		i++;
		j++;
	}
	return (0);

}

t_trie	*search_radix(t_trie *root, char *key)
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
		else if (tmp->chain[0] == -1)
			tmp = tmp->alphabet[where];
		else if (check_chain(key, tmp->chain, i) == 0)
			return (tmp);
		i++;
	}
	if (tmp == root)
		return (NULL);
	return (tmp);
}
