/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:04:12 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 21:09:26 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			*ft_words_pos(const char *str, char c, int wcount)
{
	int		*pos_tab;
	int		flag;
	int		i;
	int		j;

	flag = 1;
	pos_tab = (int *)malloc(sizeof(int) * wcount * 2 + 1);
	i = -1;
	j = 0;
	while (j <= wcount * 2)
	{
		if (str[++i] == c)
		{
			if (!flag)
				pos_tab[j++] = i;
			flag = 1;
		}
		else
		{
			if (flag || str[i] == '\0')
				pos_tab[j++] = i;
			flag = 0;
		}
	}
	return (pos_tab);
}
