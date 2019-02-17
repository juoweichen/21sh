/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:15:22 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 17:58:57 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_itoa(int n)
{
	char	*s;
	int		slen;
	long	ln;

	ln = (long)n;
	slen = ft_numlen(ln);
	s = ft_strnew(slen);
	if (!s)
		return (NULL);
	if (ln == 0)
		s[0] = '0';
	if (ln < 0)
	{
		ln = ln * -1;
		s[0] = '-';
	}
	while (ln > 0)
	{
		s[--slen] = ln % 10 + '0';
		ln = ln / 10;
	}
	return (s);
}
