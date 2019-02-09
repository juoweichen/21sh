/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:00:40 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:44:07 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		handle_hex(va_list args, t_arg *modi)
{
	uintmax_t	value;
	char		*res;
	int			ret_len;

	value = va_arg(args, uintmax_t);
	value = get_unsigned_length(modi, value);
	res = (modi->conv_chr == 'X' ? ft_itoa_base_uint_upper(value, 16) :
			ft_itoa_base_uint_lower(value, 16));
	if (res[0] == '0' && res[1] == '\0' &&
		modi->got_precision && modi->precision_value == 0)
		res[0] = '\0';
	ret_len = print_all_int(modi, res);
	free(res);
	return (ret_len);
}
