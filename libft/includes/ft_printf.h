/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define COLOR_SIGN			'^'

# define M_RED 				"\033[0;31m"
# define M_GREEN 			"\033[0;32m"
# define M_YELLOW 			"\033[0;33m"
# define M_BLUE				"\033[0;34m"
# define M_MAGENTA 			"\033[0;35m"
# define M_CYAN 			"\033[0;36m"

# define M_BOLD_RED 		"\033[1;31m"
# define M_BOLD_GREEN 		"\033[1;32m"
# define M_BOLD_YELLOW 		"\033[1;33m"
# define M_BOLD_BLUE 		"\033[1;34m"
# define M_BOLD_MAGENTA 	"\033[1;35m"
# define M_BOLD_CYAN 		"\033[1;36m"

# define M_FAINT_RED 		"\033[2;31m"
# define M_FAINT_GREEN 		"\033[2;32m"
# define M_FAINT_YELLOW 	"\033[2;33m"
# define M_FAINT_BLUE 		"\033[2;34m"
# define M_FAINT_MAGENTA	"\033[2;35m"
# define M_FAINT_CYAN 		"\033[2;36m"

# define M_RESET 			"\033[0m"

/*
**	store argument info
**	must NOT change enum's order
*/
typedef struct	s_arg
{
	int			fd;
	int			flag_hash;
	int			flag_zero;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			width_value;
	int			got_precision;
	int			precision_value;
	enum		{null, hh, h, l, ll, j, z} length;
	char		conv_chr;
}				t_arg;
/*
**	store printing info
*/
typedef struct	s_printf
{
	char		*res;
	int			free_res;
	wchar_t		*wres;
	int			free_wres;
	int			res_len;
	char		*prefix;
	int			prefix_len;
	char		*precision;
	int			precision_len;
	char		*padding;
	int			padding_len;
	int			is_str;
}				t_print;
/* 
**	dispatcher
*/
typedef	int		(*t_func)(va_list, t_arg *);
/*
**	ft_printf.c
*/
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);
/*
**	parse_func.c
*/
const char		*parse_flag(const char **format, t_arg *narg);
const char		*parse_width(const char **format, t_arg *narg, va_list args);
const char		*parse_precision(const char **format, t_arg *narg, va_list args);
const char		*parse_length(const char **format, t_arg *narg);
/*
**	conversion.c
*/
int				conversion_handler(va_list args, const char **format, t_arg *modi);
/*
**	color.c
*/
void			print_color(const char **str, char *next_arg, int fd);
/*
**	handle_helper.c
*/
intmax_t 		get_signed_length(t_arg *modi, intmax_t value);
uintmax_t		get_unsigned_length(t_arg *modi, uintmax_t value);
char			*merge_in_sequence(char *str1, char *str2, char *str3, char *str4);
void			free_tp(t_print *tp);
/*
**	handle_helper_set.c
*/
void			set_precision(t_arg *modi, t_print *tp);
void			set_padding(t_arg *modi, t_print *tp);
void			set_res(t_arg *modi, t_print *tp);
void			set_wres(t_arg *modi, t_print *tp);
/*
**	handle_helper_set_prefix.c
*/
void			set_prefix(t_arg *modi, t_print *tp);
/*
**	handle_helper_print.c
*/
int				print_all_int(t_arg *modi, char *res);
int				print_char(t_arg *modi, char res);
int				print_str(t_arg *modi, char *res);
int				print_wstr(t_arg *modi, wchar_t *wres);
int				print_wchar(t_arg *modi, wchar_t wres);
/*
**	handlers
*/
int				handle_int(va_list args, t_arg *modi);
int				handle_str(va_list args, t_arg *modi);
int				handle_char(va_list args, t_arg *modi);
int				handle_hex(va_list args, t_arg *modi);
int				handle_oct(va_list args, t_arg *modi);
int				handle_unsigned(va_list args, t_arg *modi);
int				handle_address(va_list args, t_arg *modi);
int				handle_escape(va_list args, t_arg *modi);
int				handle_wchar(va_list args, t_arg *modi);
int				handle_wstr(va_list args, t_arg *modi);

#endif
