/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:28:17 by juochen           #+#    #+#             */
/*   Updated: 2018/04/19 01:08:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_itoa_base_uint_lower(uintmax_t value, uintmax_t base);
char		*ft_itoa_base_uint_upper(uintmax_t value, uintmax_t base);
char		*ft_itoa_base_lower(intmax_t value, intmax_t base);
char		*ft_itoa_base_upper(intmax_t value, intmax_t base);
void		ft_swap_int(int *x, int *y);
void		ft_swap_double(double *x, double *y);
void		ft_sort_double_tab(double *tab, unsigned int size);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		ft_sort_int_tab(int *tab, unsigned int size);
int			ft_numlen(int n);

#endif
