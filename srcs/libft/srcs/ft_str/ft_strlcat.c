/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:13:50 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 13:13:42 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dp;
	const char	*sp;
	size_t		lp;
	size_t		length;

	dp = dst;
	sp = src;
	lp = dstsize;
	while (lp-- != 0 && *dp != '\0')
		dp++;
	length = dp - dst;
	lp = dstsize - length;
	if (lp == 0)
		return (length + ft_strlen(sp));
	while (*sp != '\0')
	{
		if (lp != 1)
		{
			*dp++ = *sp;
			lp--;
		}
		sp++;
	}
	*dp = '\0';
	return (length + (sp - src));
}
