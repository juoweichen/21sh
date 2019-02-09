/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 22:53:12 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 13:16:30 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist *next;

	while (*alst)
	{
		next = (*alst)->next;
		ft_dlstdelone(alst, del);
		*alst = next;
	}
}
