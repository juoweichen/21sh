/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint_upper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:54:59 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 21:57:54 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	aux_uint_upper(uintmax_t n, uintmax_t b, char *ans, int *p)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (b <= n)
		aux_uint_upper(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

char	*ft_itoa_base_uint_upper(uintmax_t value, uintmax_t base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base || !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	aux_uint_upper(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
