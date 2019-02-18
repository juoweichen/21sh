/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:10:41 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:47:53 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

const char	*parse_flag(const char **format, t_arg *narg)
{
	while (**format == '#' || **format == '0' || **format == '-' ||
			**format == '+' || **format == ' ')
	{
		if (**format == '#')
			narg->flag_hash = 1;
		else if (**format == '0' && narg->flag_minus != 1)
			narg->flag_zero = 1;
		else if (**format == '-')
			narg->flag_minus = 1;
		else if (**format == '-' && narg->flag_zero == 1)
			narg->flag_zero = 0;
		else if (**format == ' ' && narg->flag_plus != 1)
			narg->flag_space = 1;
		else if (**format == '+')
			narg->flag_plus = 1;
		else if (**format == '+' && narg->flag_space == 1)
			narg->flag_space = 0;
		(*format)++;
	}
	return (*format);
}

const char	*parse_width(const char **format, t_arg *narg, va_list args)
{
	if (**format != '.')
	{
		if (**format == '*')
		{
			narg->width_value = va_arg(args, int);
			(*format)++;
		}
		else
			while (ft_isdigit(**format))
			{
				narg->width_value = narg->width_value * 10 + (**format - '0');
				(*format)++;
			}
	}
	return (*format);
}

const char	*parse_precision(const char **format, t_arg *narg, va_list args)
{
	while (**format == '.')
	{
		narg->got_precision = 1;
		(*format)++;
		if (**format == '*')
		{
			narg->precision_value = va_arg(args, int);
			(*format)++;
		}
		else
			while (ft_isdigit(**format))
			{
				narg->precision_value = narg->precision_value * 10 +
					(**format - '0');
				(*format)++;
			}
	}
	return (*format);
}

const char	*parse_length(const char **format, t_arg *narg)
{
	while (**format == 'h' || **format == 'l' ||
			**format == 'j' || **format == 'z')
	{
		if (**format == 'h' && narg->length < 3)
			if (narg->length == h)
				narg->length = hh;
			else
				narg->length = h;
		else if (**format == 'l')
			if (narg->length == l)
				narg->length = MAX(narg->length, ll);
			else
				narg->length = MAX(narg->length, l);
		else if (**format == 'j')
			narg->length = MAX(narg->length, j);
		else if (**format == 'z')
			narg->length = MAX(narg->length, z);
		(*format)++;
	}
	return (*format);
}
