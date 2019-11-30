/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:09:50 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/21 02:09:51 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/radix_tree.h"

void	print_radix(t_trie *root, char *matching, int level, char *match)
{
	int		i;

	i = 0;
	if (root->eow == 1 && root->chain[0] == -1)	// when is the eow and doesn't have compression
	{
		matching[level] = '\0';
		ft_printf("%s%s\n", match, matching);
	}
	else if (root->chain[0] != -1)	// compressed final node
	{
		matching[level] = '\0';
		ft_printf("%s%s", match, matching);
		while (root->chain[i] != -1 && root->chain[i] != '\0')
		{
			ft_printf("%c", (root->chain[i] + (char)START_ALPHA));
			i++;
		}
		ft_printf("\n");
		return ;
	}
	while (i < ALPHABET)
	{
		if (root->alphabet[i] != NULL)
		{
			matching[level] = (char)i + START_ALPHA;
			print_radix(root->alphabet[i], matching, level + 1, match);
		}
		i++;
	}
}