/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:11:26 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/25 21:11:26 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin_free_s1(char *s1, const char *s2)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_strnew(len);
	i = -1;
	while (s1[++i] != '\0')
		new_str[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new_str[i + j] = s2[j];
	free(s1);
	s1 = NULL;
	return (new_str);
}
