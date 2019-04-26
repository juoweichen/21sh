/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:44:24 by juochen           #+#    #+#             */
/*   Updated: 2019/04/25 21:34:26 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int				ft_words(char const *str, const char ch)
{
	const char	*string;
	int			i;
	int			wc;

	string = str;
	i = 0;
	wc = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ch)
			i++;
		if (string[i] != ch && string[i])
		{
			wc++;
			while (string[i] != ch && string[i])
				i++;
		}
	}
	return (wc);
}

static int		ft_wordlen(char const *str, char c)
{
	int				len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**splits;
	int				word_count;
	int				i;
	int				j;

	if (s == NULL)
		return (0);
	word_count = ft_words(s, c);
	if (!(splits = (char **)malloc((sizeof(char *) * (word_count + 1)))))
		return (NULL);
	splits[word_count] = NULL;
	i = -1;
	j = 0;
	while (++i < word_count)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		splits[i] = ft_strsub(s + j, 0, ft_wordlen(s + j, c));
		j += ft_wordlen(s + j, c);
	}
	return (splits);
}
