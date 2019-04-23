/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

// Returns the last node of the list 
t_list *getTail(t_list *cur) 
{ 
	while (cur != NULL && cur->next != NULL) 
		cur = cur->next; 
	return (cur); 
} 

// partition_singles the list taking the last element as the pivot 
t_list *partition_single(t_list *head, t_list *end, 
					t_list **newHead, t_list **newEnd) 
{ 
	t_list *pivot = end; 
	t_list *prev = NULL, *cur = head, *tail = pivot; 

	// During partition_single, both the head and end of the list might change 
	// which is updated in the newHead and newEnd variables 
	while (cur != pivot) 
	{ 
		if (ft_strcmp(cur->content, pivot->content) < 0) 
		{ 
			// First node that has a value less than the pivot - becomes 
			// the new head 
			if ((*newHead) == NULL) 
				(*newHead) = cur; 

			prev = cur; 
			cur = cur->next; 
		} 
		else // If cur node is greater than pivot 
		{ 
			// Move cur node to next of tail, and change tail 
			if (prev) 
				prev->next = cur->next; 
			t_list *tmp = cur->next; 
			cur->next = NULL; 
			tail->next = cur; 
			tail = cur; 
			cur = tmp; 
		} 
	} 

	// If the pivot data is the smallest element in the current list, 
	// pivot becomes the head 
	if ((*newHead) == NULL) 
		(*newHead) = pivot; 

	// Update newEnd to the current last node 
	(*newEnd) = tail; 

	// Return the pivot node 
	return pivot; 
} 


//here the sorting happens exclusive of the end node 
t_list *quickSortRecur(t_list *head, t_list *end) 
{ 
	t_list *new_head = NULL;
	t_list *new_end = NULL; 
	
	// base condition 
	if (!head || head == end) 
		return (head); 
	// partition_single the list, newHead and newEnd will be updated 
	// by the partition_single function 
	t_list *pivot = partition_single(head, end, &new_head, &new_end); 

	// If pivot is the smallest element - no need to recur for 
	// the left part. 
	if (new_head != pivot) 
	{ 
		// Set the node before the pivot node as NULL 
		t_list *tmp = new_head; 
		while (tmp->next != pivot) 
			tmp = tmp->next; 
		tmp->next = NULL; 

		// Recur for the list before pivot 
		new_head = quickSortRecur(new_head, tmp); 

		// Change next of last node of the left half to pivot 
		tmp = getTail(new_head); 
		tmp->next = pivot; 
	} 

	// Recur for the list after the pivot element 
	pivot->next = quickSortRecur(pivot->next, new_end); 

	return (new_head); 
} 

// The main function for quick sort. This is a wrapper over recursive 
// function quickSortRecur() 
void quick_sort_str_list(t_list **list) 
{ 
	*list = quickSortRecur(*list, getTail(*list)); 
	return; 
} 