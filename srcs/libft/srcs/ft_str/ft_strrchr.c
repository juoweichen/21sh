/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:43:13 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 20:57:09 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ns;

	ns = NULL;
	while (1)
	{
		if (*s == (char)c)
			ns = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (ns);
}
