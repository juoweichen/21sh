/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_helper_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:24:52 by juochen           #+#    #+#             */
/*   Updated: 2018/09/12 08:41:58 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_all_int(t_arg *modi, char *res)
{
	t_print *tp;
	char	*m;

	tp = (t_print *)ft_memalloc(sizeof(t_print));
	tp->res = res;
	tp->res_len = ft_strlen(res);
	set_prefix(modi, tp);
	set_precision(modi, tp);
	set_padding(modi, tp);
	if (modi->flag_zero == 1 && modi->got_precision == 0)
		m = merge_in_sequence(tp->prefix, tp->padding, tp->res, NULL);
	else if (modi->flag_minus == 1)
		m = merge_in_sequence(tp->prefix, tp->precision, tp->res, tp->padding);
	else
		m = merge_in_sequence(tp->padding, tp->prefix, tp->precision, tp->res);
	ft_putstr_fd(m, modi->fd);
	ft_strdel(&m);
	free_tp(tp);
	return (tp->prefix_len + tp->precision_len + tp->padding_len + tp->res_len);
}

int	print_char(t_arg *modi, char res)
{
	t_print *tp;

	tp = (t_print *)ft_memalloc(sizeof(t_print));
	tp->res_len = 1;
	tp->is_str = 1;
	set_padding(modi, tp);
	if (modi->flag_minus == 1)
	{
		ft_putchar_fd(res, modi->fd);
		if (tp->padding)
			ft_putstr_fd(tp->padding, modi->fd);
	}
	else
	{
		if (tp->padding)
			ft_putstr_fd(tp->padding, modi->fd);
		ft_putchar_fd(res, modi->fd);
	}
	free_tp(tp);
	return (tp->padding_len + tp->res_len);
}

int	print_str(t_arg *modi, char *res)
{
	t_print *tp;
	char	*m;

	tp = (t_print *)ft_memalloc(sizeof(t_print));
	tp->res = res;
	tp->res_len = ft_strlen(res);
	set_res(modi, tp);
	tp->is_str = 1;
	set_padding(modi, tp);
	if (modi->flag_minus == 1)
		m = merge_in_sequence(tp->res, tp->padding, NULL, NULL);
	else
		m = merge_in_sequence(tp->padding, tp->res, NULL, NULL);
	ft_putstr_fd(m, modi->fd);
	ft_strdel(&m);
	free_tp(tp);
	return (tp->padding_len + tp->res_len);
}

int	print_wstr(t_arg *modi, wchar_t *wres)
{
	t_print *tp;

	tp = (t_print *)ft_memalloc(sizeof(t_print));
	tp->wres = wres;
	tp->res_len = ft_wstrlen(wres);
	set_wres(modi, tp);
	tp->is_str = 1;
	set_padding(modi, tp);
	if (modi->flag_minus == 1)
	{
		ft_putwstr_fd(tp->wres, modi->fd);
		if (tp->padding)
			ft_putstr_fd(tp->padding, modi->fd);
	}
	else
	{
		if (tp->padding)
			ft_putstr_fd(tp->padding, modi->fd);
		ft_putwstr_fd(tp->wres, modi->fd);
	}
	free_tp(tp);
	return (tp->padding_len + tp->res_len);
}

int	print_wchar(t_arg *modi, wchar_t wres)
{
	t_print *tp;

	tp = (t_print *)ft_memalloc(sizeof(t_print));
	tp->res_len = 1;
	tp->is_str = 1;
	set_padding(modi, tp);
	if (modi->flag_minus == 1)
	{
		ft_putwchar_fd(wres, modi->fd);
		if (tp->padding)
			ft_putstr_fd(tp->padding, modi->fd);
	}
	else
	{
		if (tp->padding)
			ft_putstr_fd(tp->padding, modi->fd);
		ft_putwchar_fd(wres, modi->fd);
	}
	free_tp(tp);
	return (tp->padding_len + tp->res_len);
}
