/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:18:43 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:23:20 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		handle_int(va_list args, t_arg *modi)
{
	intmax_t	value;
	char		*res;
	int			ret_len;

	value = va_arg(args, intmax_t);
	value = get_signed_length(modi, value);
	res = ft_itoa_base_lower(value, 10);
	if (res[0] == '0' && res[1] == '\0' && modi->got_precision &&
			modi->precision_value == 0)
		res[0] = '\0';
	ret_len = print_all_int(modi, res);
	free(res);
	return (ret_len);
}
