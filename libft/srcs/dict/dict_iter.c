/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	dict_iter_add(t_dict *dict, char *key)
{
	if (dict->iter == NULL)
		dict->iter = ft_lstnew((void *)key, ft_strlen(key));
	else
		ft_lstaddend(&dict->iter, ft_lstnew((void *)key, ft_strlen(key)));
	dict->size += 1;
}

void	dict_iter_remove(t_dict *dict, char *key)
{
	t_list	*preptr;
	t_list	*curptr;

	if (dict->iter == NULL)
		return ;
	preptr = NULL;
	curptr = dict->iter;
	while (curptr)
	{
		if (ft_strequ(key, (char *)curptr->content) == 1)
		{
			preptr->next = curptr->next;
			ft_lstdelone(&curptr, ft_lstdel_content);
			dict->size -= 1;
			return ;
		}
		preptr = curptr;
		curptr = curptr->next;
	}
}
