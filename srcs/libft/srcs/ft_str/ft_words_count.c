/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:03:08 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 21:03:57 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_words_count(const char *str, char c)
{
	int		count;
	int		flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (*str == c)
			flag = 1;
		else
		{
			if (flag)
				count++;
			flag = 0;
		}
		str++;
	}
	return (count);
}
