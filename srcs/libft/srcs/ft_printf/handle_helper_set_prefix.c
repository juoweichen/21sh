/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_helper_prefix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:25:07 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:26:18 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	set_prefix_hex(t_arg *modi, t_print *tp)
{
	if (modi->flag_hash == 1 || modi->conv_chr == 'p')
	{
		tp->prefix = (char *)ft_memalloc(sizeof(char) * 2 + 1);
		tp->prefix[0] = '0';
		tp->prefix_len += 1;
		if (modi->conv_chr == 'x' || modi->conv_chr == 'X' ||
				modi->conv_chr == 'p')
		{
			tp->prefix[1] = (modi->conv_chr == 'p' ? 'x' : modi->conv_chr);
			tp->prefix_len += 1;
		}
	}
}

void	set_prefix_int(t_arg *modi, t_print *tp)
{
	tp->prefix = (char *)ft_memalloc(sizeof(char) + 1);
	if (tp->res[0] != '-' && modi->flag_plus == 1)
		tp->prefix[0] = '+';
	else if (tp->res[0] == '-')
	{
		tp->prefix[0] = '-';
		tp->res += 1;
		tp->res_len -= 1;
	}
	else if (modi->flag_space == 1)
		tp->prefix[0] = ' ';
	else
		tp->prefix_len -= 1;
	tp->prefix_len += 1;
}

void	set_prefix(t_arg *modi, t_print *tp)
{
	if (modi->conv_chr == 'p')
		set_prefix_hex(modi, tp);
	else if (modi->conv_chr == 'x' || modi->conv_chr == 'X' ||
			modi->conv_chr == 'o' || modi->conv_chr == 'O')
	{
		if (tp->res[0] != '0' && tp->res[0] != '\0')
			set_prefix_hex(modi, tp);
	}
	else if (modi->conv_chr == 'd' || modi->conv_chr == 'i')
		set_prefix_int(modi, tp);
}
