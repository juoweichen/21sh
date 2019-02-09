/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:16:49 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:31:16 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		handle_str(va_list args, t_arg *modi)
{
	char	*value;
	int		ret_len;

	if (modi->length == l)
	{
		ret_len = handle_wstr(args, modi);
		return (ret_len);
	}
	value = va_arg(args, char*);
	if (value == NULL)
		value = "(null)";
	ret_len = print_str(modi, value);
	return (ret_len);
}
