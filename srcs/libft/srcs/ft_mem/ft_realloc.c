/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:34:21 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 17:36:54 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*mem;
	size_t	ptrlen;

	if (ptr != NULL)
	{
		ptrlen = ft_strlen((char *)ptr);
		if (size < ptrlen)
			size = ptrlen;
		mem = ft_memalloc(size);
		ft_memcpy(mem, ptr, ptrlen);
		ft_memdel(&ptr);
	}
	else
		mem = ft_memalloc(size);
	ptr = mem;
	return (ptr);
}
