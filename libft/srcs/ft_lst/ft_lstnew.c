/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:33:09 by juochen           #+#    #+#             */
/*   Updated: 2018/02/28 13:15:50 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list *)ft_memalloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content_size = content_size;
		tmp->content = ft_memalloc(content_size);
		if (!tmp->content)
		{
			free(tmp);
			return (NULL);
		}
		tmp->content = ft_memcpy(tmp->content, content, content_size);
	}
	tmp->next = NULL;
	return (tmp);
}
