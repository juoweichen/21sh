/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_str_dlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:06:13 by kblack            #+#    #+#             */
/*   Updated: 2019/04/26 18:06:15 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void		swap_content(t_dlist *dl1, t_dlist *dl2)
{
	void	*tmp_content;
	size_t	tmp_size;

	tmp_content = dl1->content;
	tmp_size = dl1->content_size;
	dl1->content = dl2->content;
	dl1->content_size = dl2->content_size;
	dl2->content = tmp_content;
	dl2->content_size = tmp_size;
}

t_dlist		*partition_double(t_dlist *head, t_dlist *last)
{
	t_dlist *i;
	t_dlist *j;
	t_dlist	*p;

	p = last;
	i = head->prev;
	j = head;
	while (j != last)
	{
		if (ft_strcmp(((t_com *)j->content)->name,
			((t_com *)p->content)->name) < 0)
		{
			i = (i == NULL) ? head : i->next;
			swap_content(i, j);
		}
		j = j->next;
	}
	i = (i == NULL) ? head : i->next;
	swap_content(i, last);
	return (i);
}

void		sort(t_dlist *head, t_dlist *last)
{
	t_dlist *pivot;

	if (last != NULL && last != head && last->next != head)
	{
		pivot = partition_double(head, last);
		sort(head, pivot->prev);
		sort(pivot->next, last);
	}
}

void		quick_sort_str_dlist(t_dlist *dlist)
{
	t_dlist	*lastnode;

	if (dlist == NULL)
		return ;
	lastnode = dlist;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	sort(dlist, lastnode);
}
