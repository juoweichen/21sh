/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 20:43:00 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:18:18 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	set_dptable(t_func *dptable)
{
	dptable['d'] = &handle_int;
	dptable['D'] = &handle_int;
	dptable['i'] = &handle_int;
	dptable['s'] = &handle_str;
	dptable['S'] = &handle_wstr;
	dptable['c'] = &handle_char;
	dptable['C'] = &handle_wchar;
	dptable['p'] = &handle_address;
	dptable['x'] = &handle_hex;
	dptable['X'] = &handle_hex;
	dptable['o'] = &handle_oct;
	dptable['O'] = &handle_oct;
	dptable['u'] = &handle_unsigned;
	dptable['U'] = &handle_unsigned;
	dptable['%'] = &handle_escape;
}

int		conversion_handler(va_list args, const char **format, t_arg *modi)
{
	static	t_func	dptable[256] = {NULL};
	char			*conv_arr;
	int				arg_len;
	char			*ptr;

	arg_len = 0;
	conv_arr = "%sSpdDioOuUxXcC";
	set_dptable(dptable);
	ptr = ft_strchr(conv_arr, **format);
	if (ptr != NULL && *ptr != '\0')
	{
		modi->conv_chr = **format;
		arg_len = dptable[(int)modi->conv_chr](args, modi);
		(*format)++;
		return (arg_len);
	}
	conv_arr = "+-0 #.hljz";
	ptr = ft_strchr(conv_arr, **format);
	if (ptr != NULL && *ptr != '\0' && !ft_isdigit(**format))
		return (-1);
	return (0);
}
