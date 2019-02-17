/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:34:21 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 17:36:54 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size + 1);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}
