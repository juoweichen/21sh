/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:37:39 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:43:01 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		handle_char(va_list args, t_arg *modi)
{
	char	value;
	int		ret_len;

	if (modi->length == l)
	{
		ret_len = handle_wchar(args, modi);
		return (ret_len);
	}
	value = va_arg(args, int);
	ret_len = print_char(modi, value);
	return (ret_len);
}
