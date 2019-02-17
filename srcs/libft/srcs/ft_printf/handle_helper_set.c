/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_helper_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:26:53 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:41:35 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	set_precision(t_arg *modi, t_print *tp)
{
	int		i;

	tp->precision_len = modi->precision_value - tp->res_len;
	if (tp->precision_len > 0)
	{
		tp->precision = (char *)ft_memalloc(sizeof(char) *
				tp->precision_len + 1);
		i = 0;
		while (i < tp->precision_len)
			tp->precision[i++] = '0';
		return ;
	}
	tp->precision = NULL;
	tp->precision_len = 0;
}

void	set_padding(t_arg *modi, t_print *tp)
{
	char	padding_char;
	int		i;

	padding_char = '\0';
	tp->padding_len = modi->width_value - tp->prefix_len -
		tp->precision_len - tp->res_len;
	if (tp->padding_len > 0)
	{
		tp->padding = (char *)ft_memalloc(sizeof(char) * tp->padding_len + 1);
		if (modi->flag_zero == 1)
		{
			if (modi->got_precision == 1 && tp->is_str == 0)
				padding_char = ' ';
			else
				padding_char = '0';
		}
		else
			padding_char = ' ';
		i = -1;
		while (++i < tp->padding_len)
			tp->padding[i] = padding_char;
		return ;
	}
	tp->padding = NULL;
	tp->padding_len = 0;
}

void	set_res(t_arg *modi, t_print *tp)
{
	char	*tmp;

	tmp = NULL;
	if (modi->got_precision && modi->precision_value < tp->res_len)
	{
		tp->res_len = modi->precision_value;
		tmp = ft_strnew(tp->res_len);
		tmp = ft_strncpy(tmp, tp->res, tp->res_len);
		tp->res = tmp;
		tp->free_res = 1;
	}
}

void	set_wres(t_arg *modi, t_print *tp)
{
	wchar_t	*tmp;

	tmp = NULL;
	if (modi->got_precision && modi->precision_value < tp->res_len)
	{
		tp->res_len = modi->precision_value;
		tmp = (wchar_t *)ft_memalloc(sizeof(wchar_t) * tp->res_len + 1);
		tmp = ft_memcpy(tmp, tp->wres, sizeof(wchar_t) * tp->res_len);
		tp->wres = tmp;
		tp->free_wres = 1;
	}
}
