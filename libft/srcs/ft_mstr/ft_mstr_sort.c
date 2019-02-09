/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 21:59:03 by juochen           #+#    #+#             */
/*   Updated: 2018/09/12 08:16:06 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_mstr_sort(char **mstr)
{
	int		i;
	int		swapped;
	char	*tmp;

	if (mstr == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = -1;
		while (mstr[i + 1])
		{
			if (ft_strcmp(mstr[i], mstr[i + 1]) > 0)
			{
				tmp = mstr[i];
				mstr[i] = mstr[i + 1];
				mstr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}
