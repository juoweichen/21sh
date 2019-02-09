/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:35:33 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 21:41:13 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	j;
	int				tmp;
	int				is_sorted_flag;

	if (!tab || size == 0)
		return ;
	while (1)
	{
		j = 0;
		is_sorted_flag = 1;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				is_sorted_flag = 0;
			}
			j++;
		}
		if (is_sorted_flag)
			return ;
	}
}
