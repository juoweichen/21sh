/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:18:53 by juochen           #+#    #+#             */
/*   Updated: 2018/02/25 14:57:46 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	size_t	s1_len;
	char	*s2;
	size_t	s2_len;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = (s1_len < n ? s1_len : n);
	s2 = (char *)malloc(sizeof(char) * s2_len + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < s2_len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
