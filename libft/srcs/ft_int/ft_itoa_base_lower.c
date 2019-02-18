/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:59:09 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:01:06 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	aux_lower(intmax_t n, intmax_t b, char *ans, int *p)
{
	char	*base;

	base = "0123456789abcdef";
	if (n <= -b || b <= n)
		aux_lower(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

char	*ft_itoa_base_lower(intmax_t value, intmax_t base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	aux_lower(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
