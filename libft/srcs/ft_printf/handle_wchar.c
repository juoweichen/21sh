/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:29:07 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:20:18 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		handle_wchar(va_list args, t_arg *modi)
{
	wchar_t	value;
	int		ret_len;

	value = va_arg(args, wchar_t);
	ret_len = print_wchar(modi, value);
	return (ret_len);
}
