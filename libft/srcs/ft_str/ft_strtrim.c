/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:27:38 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 20:47:09 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ns;
	int		start;
	int		end;
	int		slen;
	int		i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	ns = ft_strnew(slen);
	if (!ns)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = slen - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	i = 0;
	while (start <= end)
		ns[i++] = s[start++];
	return (ns);
}
