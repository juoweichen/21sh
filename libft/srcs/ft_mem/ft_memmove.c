/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:21:46 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 16:54:12 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cd;
	const unsigned char	*cs;
	size_t				i;

	cd = dst;
	cs = src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			cd[i] = cs[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len--)
			cd[len] = cs[len];
	}
	return (dst);
}
