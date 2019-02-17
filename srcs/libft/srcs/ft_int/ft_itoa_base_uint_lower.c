/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:30:43 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 21:58:30 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	aux_uint_lower(uintmax_t n, uintmax_t b, char *ans, int *p)
{
	char	*base;

	base = "0123456789abcdef";
	if (b <= n)
		aux_uint_lower(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

char	*ft_itoa_base_uint_lower(uintmax_t value, uintmax_t base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base ||
		!(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	aux_uint_lower(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
