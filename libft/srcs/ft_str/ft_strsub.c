/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:51:03 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 19:38:18 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	int		j;
	char	*ns;

	if (s == NULL)
		return (NULL);
	ns = ft_strnew(len);
	if (!ns)
		return (NULL);
	i = 0;
	j = start;
	while (i < len && s[j])
		ns[i++] = s[j++];
	ns[i] = '\0';
	return (ns);
}
