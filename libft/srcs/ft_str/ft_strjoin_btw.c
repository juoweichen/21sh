/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_btw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:05:40 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 20:46:11 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin_btw(char const *s1, char const *s2, char btw)
{
	char	*ns;
	int		i;
	int		j;

	ns = ft_strnew(ft_strlen(s1) + 1 + ft_strlen(s2));
	if (!ns)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		ns[i++] = s1[j++];
	ns[i++] = btw;
	j = 0;
	while (s2[j])
		ns[i++] = s2[j++];
	return (ns);
}
