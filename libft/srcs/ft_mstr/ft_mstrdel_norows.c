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

void	ft_mstrdel_norows(char ***mstr)
{
	int count;

	if (mstr == NULL)
		return ;
	count = 0;
	while ((*mstr)[count] != NULL)
		count++;
	while (--count >= 0)
		free((*mstr)[count]);
	free(*mstr);
}
