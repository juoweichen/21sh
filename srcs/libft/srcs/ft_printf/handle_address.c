/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:26:35 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:32:43 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		handle_address(va_list args, t_arg *modi)
{
	uintmax_t	value;
	char		*res;
	int			ret_len;

	value = (uintmax_t)va_arg(args, void*);
	res = ft_itoa_base_uint_lower(value, 16);
	ret_len = print_all_int(modi, res);
	free(res);
	return (ret_len);
}
