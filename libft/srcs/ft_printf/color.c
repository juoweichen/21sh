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

int			color_faint(const char *arg_start, int fd)
{
	int	offset;

	if (!ft_strncmp(arg_start, "FAINT_RED", offset = 9))
		ft_putstr_fd(M_FAINT_RED, fd);
	else if (!ft_strncmp(arg_start, "FAINT_GREEN", offset = 11))
		ft_putstr_fd(M_FAINT_GREEN, fd);
	else if (!ft_strncmp(arg_start, "FAINT_YELLOW", offset = 12))
		ft_putstr_fd(M_FAINT_YELLOW, fd);
	else if (!ft_strncmp(arg_start, "FAINT_BLUE", offset = 10))
		ft_putstr_fd(M_FAINT_BLUE, fd);
	else if (!ft_strncmp(arg_start, "FAINT_MAGENTA", offset = 13))
		ft_putstr_fd(M_FAINT_MAGENTA, fd);
	else if (!ft_strncmp(arg_start, "FAINT_CYAN", offset = 10))
		ft_putstr_fd(M_FAINT_CYAN, fd);
	else
		offset = 0;
	return (offset + 1);
}

int			color_bold(const char *arg_start, int fd)
{
	int	offset;

	if (!ft_strncmp(arg_start, "BOLD_RED", offset = 8))
		ft_putstr_fd(M_BOLD_RED, fd);
	else if (!ft_strncmp(arg_start, "BOLD_GREEN", offset = 10))
		ft_putstr_fd(M_BOLD_GREEN, fd);
	else if (!ft_strncmp(arg_start, "BOLD_YELLOW", offset = 11))
		ft_putstr_fd(M_BOLD_YELLOW, fd);
	else if (!ft_strncmp(arg_start, "BOLD_BLUE", offset = 9))
		ft_putstr_fd(M_BOLD_BLUE, fd);
	else if (!ft_strncmp(arg_start, "BOLD_MAGENTA", offset = 12))
		ft_putstr_fd(M_BOLD_MAGENTA, fd);
	else if (!ft_strncmp(arg_start, "BOLD_CYAN", offset = 9))
		ft_putstr_fd(M_BOLD_CYAN, fd);
	else
		offset = 0;
	return (offset + 1);
}

int			color_normal(const char *arg_start, int fd)
{
	int	offset;

	if (!ft_strncmp(arg_start, "RED", offset = 3))
		ft_putstr_fd(M_RED, fd);
	else if (!ft_strncmp(arg_start, "GREEN", offset = 5))
		ft_putstr_fd(M_GREEN, fd);
	else if (!ft_strncmp(arg_start, "YELLOW", offset = 6))
		ft_putstr_fd(M_YELLOW, fd);
	else if (!ft_strncmp(arg_start, "BLUE", offset = 4))
		ft_putstr_fd(M_BLUE, fd);
	else if (!ft_strncmp(arg_start, "MAGENTA", offset = 7))
		ft_putstr_fd(M_MAGENTA, fd);
	else if (!ft_strncmp(arg_start, "CYAN", offset = 4))
		ft_putstr_fd(M_CYAN, fd);
	else if (!ft_strncmp(arg_start, "RESET", offset = 5))
		ft_putstr_fd(M_RESET, fd);
	else
		offset = 0;
	return (offset + 1);
}

const char	*change_color(const char *arg_start, int fd)
{
	int	tmp;
	int	offset;

	offset = 1;
	if ((tmp = color_normal(arg_start + 1, fd)) != 1)
		offset = tmp;
	else if ((tmp = color_bold(arg_start + 1, fd)) != 1)
		offset = tmp;
	else if ((tmp = color_faint(arg_start + 1, fd)) != 1)
		offset = tmp;
	else if (offset == 1)
		ft_putchar_fd(COLOR_SIGN, fd);
	return (arg_start + offset);
}

void		print_color(const char **str, char *next_arg, int fd)
{
	char	*color_arg;

	if (next_arg)
	{
		while ((color_arg = ft_strchr(*str, COLOR_SIGN)) &&
			next_arg > color_arg)
		{
			ft_putnstr_fd(*str, color_arg - (*str), fd);
			*str = color_arg;
			*str = change_color(*str, fd);
		}
		ft_putnstr_fd(*str, next_arg - (*str), fd);
	}
	else
	{
		while ((color_arg = ft_strchr(*str, COLOR_SIGN)))
		{
			ft_putnstr_fd(*str, color_arg - (*str), fd);
			*str = color_arg;
			*str = change_color(*str, fd);
		}
		ft_putstr_fd(*str, fd);
	}
}
