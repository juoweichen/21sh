/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:44:24 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 21:13:26 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		*pos;
	int		wcount;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	wcount = ft_words_count(s, c);
	words = (char **)malloc(sizeof(char *) * wcount + 1);
	if (!words)
		return (NULL);
	pos = ft_words_pos(s, c, wcount);
	i = -1;
	while (++i < wcount)
	{
		words[i] = ft_strnew(pos[i * 2 + 1] - pos[i * 2]);
		j = -1;
		while (++j + pos[i * 2] < pos[i * 2 + 1])
			words[i][j] = s[j + pos[i * 2]];
	}
	words[i] = NULL;
	free(pos);
	return (words);
}
