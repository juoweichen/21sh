/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_str_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:07:42 by kblack            #+#    #+#             */
/*   Updated: 2019/04/26 18:07:44 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

/*
**	Returns the last node of the list
*/

t_list		*get_tail(t_list *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return (cur);
}

/*
**	partition_singles is the list taking the last element as the pivot
**		t_list	*pivot[0];
**		t_list	*prev == pivot[1]
**		t_list	*tmp == pivot[2]
**		t_list	*cur == pivot[3]
**		t_list	*tail == pivot[4]
**	-	During partition_single, both the head and end of the list might change
**		which is updated in the new_head and new_end variables
**		~ 	If the first node that has a value less than
**			pivot then pivot becomes new head
**		~	Else if cur is greater than pivot move cur node
**			to tail next and set tail to cur
**	-	If the pivot data is the smallest element in the current list,
**		pivot becomes the head
**	-	Update new_end to the current last node
**	RETURN pivot node
*/

t_list		*partition_single(t_list *head, t_list *end,
	t_list **new_head, t_list **new_end)
{
	t_list	*pivot[5];

	pivot[0] = end;
	pivot[3] = head;
	pivot[4] = pivot[0];
	pivot[1] = NULL;
	while (pivot[3] != pivot[0])
	{
		if (ft_strcmp(pivot[3]->content, pivot[0]->content) < 0)
		{
			((*new_head) == NULL) ? (*new_head) = pivot[3] : 0;
			pivot[1] = pivot[3];
			pivot[3] = pivot[3]->next;
		}
		else
		{
			(pivot[1] != NULL) ? pivot[1]->next = pivot[3]->next : 0;
			pivot[2] = pivot[3]->next;
			pivot[3]->next = NULL;
			pivot[4]->next = pivot[3];
			pivot[4] = pivot[3];
			pivot[3] = pivot[2];
		}
	}
	((*new_head) == NULL) ? (*new_head) = pivot[0] : 0;
	(*new_end) = pivot[4];
	return (pivot[0]);
}

/*
**	Here the sorting happens exclusive of the end node.
**	partition_single()updates new_head and new_end
**	- If the pivot is the smallest element - no need to recur for left side
**		~ Set node before the pivot to NULL
**		~ Recur for the list before pivot
**		~ Change next of last node of the left half to pivot
*/

t_list		*quick_sort_recur(t_list *head, t_list *end)
{
	t_list	*new_head;
	t_list	*new_end;
	t_list	*pivot;
	t_list	*tmp;

	new_head = NULL;
	new_end = NULL;
	if (!head || head == end)
		return (head);
	pivot = partition_single(head, end, &new_head, &new_end);
	if (new_head != pivot)
	{
		tmp = new_head;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		new_head = quick_sort_recur(new_head, tmp);
		tmp = get_tail(new_head);
		tmp->next = pivot;
	}
	pivot->next = quick_sort_recur(pivot->next, new_end);
	return (new_head);
}

/*
**	The main function for quick sort. This is a wrapper over recursive
**	function quick_sort_recur()
*/

void		quick_sort_str_list(t_list **list)
{
	*list = quick_sort_recur(*list, get_tail(*list));
	return ;
}
