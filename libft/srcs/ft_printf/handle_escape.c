/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:26:35 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:07:10 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		handle_escape(va_list args, t_arg *modi)
{
	int	ret_len;

	args = NULL;
	ret_len = print_char(modi, '%');
	return (ret_len);
}
