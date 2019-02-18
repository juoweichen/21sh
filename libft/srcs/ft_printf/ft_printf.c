/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:57:59 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:10:05 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		handle_arg(int fd, va_list args, const char **format)
{
	t_arg	*modifier;
	int		arg_chr;

	modifier = (t_arg *)ft_memalloc(sizeof(t_arg));
	modifier->fd = fd;
	if (*(++*format) == '\0')
		return (0);
	while (**format)
	{
		if (parse_flag(format, modifier) == NULL)
			return (-1);
		if (parse_width(format, modifier, args) == NULL)
			return (-1);
		if (parse_precision(format, modifier, args) == NULL)
			return (-1);
		if (parse_length(format, modifier) == NULL)
			return (-1);
		if ((arg_chr = conversion_handler(args, format, modifier)) >= 0)
			break ;
	}
	free(modifier);
	return (arg_chr);
}

int		read_format(int fd, va_list args, const char *format, size_t ret_chr)
{
	char	*next_arg;
	size_t	handle_len;

	next_arg = ft_strchr(format, '%');
	if (*format == '\0')
		return (ret_chr);
	if (next_arg == NULL)
	{
		print_color(&format, next_arg, fd);
		return (ret_chr + ft_strlen(format));
	}
	if (next_arg > format)
	{
		print_color(&format, next_arg, fd);
		return (read_format(fd, args, next_arg, ret_chr + next_arg - format));
	}
	else
		return ((handle_len = handle_arg(fd, args, &format)) == -1 ?
		-1 : read_format(fd, args, format, ret_chr + handle_len));
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	if (format)
	{
		va_start(args, format);
		ret = read_format(fd, args, format, 0);
		va_end(args);
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	if (format)
	{
		va_start(args, format);
		ret = read_format(1, args, format, 0);
		va_end(args);
	}
	return (ret);
}
