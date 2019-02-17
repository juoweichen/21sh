/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:20:58 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:31:28 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

intmax_t	get_signed_length(t_arg *modi, intmax_t value)
{
	if (modi->length == h && modi->conv_chr != 'D')
		value = (short int)value;
	else if (modi->length == l || modi->conv_chr == 'D')
		value = (long int)value;
	else if (modi->length == hh)
		value = (signed char)value;
	else if (modi->length == ll)
		value = (long long int)value;
	else if (modi->length == j)
		value = (intmax_t)value;
	else if (modi->length == z)
		value = (size_t)value;
	else
		value = (int)value;
	return (value);
}

uintmax_t	get_unsigned_length(t_arg *modi, uintmax_t value)
{
	if (modi->length == h && modi->conv_chr != 'U')
		value = (unsigned short int)value;
	else if (modi->length == l || modi->conv_chr == 'O' ||
			modi->conv_chr == 'U')
		value = (unsigned long int)value;
	else if (modi->length == hh)
		value = (unsigned char)value;
	else if (modi->length == ll)
		value = (unsigned long long int)value;
	else if (modi->length == j)
		value = (uintmax_t)value;
	else if (modi->length == z)
		value = (size_t)value;
	else
		value = (unsigned int)value;
	return (value);
}

char		*merge_in_sequence(char *str1, char *str2, char *str3, char *str4)
{
	char	*merged;
	int		len;

	len = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) +
	ft_strlen(str4);
	if ((merged = (char *)ft_memalloc(len)) == NULL)
		return (NULL);
	merged = ft_strcat(merged, str1);
	merged = ft_strcat(merged, str2);
	merged = ft_strcat(merged, str3);
	merged = ft_strcat(merged, str4);
	return (merged);
}

void		free_tp(t_print *tp)
{
	if (tp->free_res == 1)
		free(tp->res);
	if (tp->free_wres == 1)
		free(tp->wres);
	if (tp->prefix != NULL)
		free(tp->prefix);
	if (tp->precision != NULL)
		free(tp->precision);
	if (tp->padding != NULL)
		free(tp->padding);
	free(tp);
}
