/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:56:49 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 17:37:20 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)ft_memalloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, sizeof(char) * size + 1);
	return (str);
}
