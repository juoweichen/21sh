/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_queue		*queue_init(void)
{
	t_queue	*queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void		qpush(t_queue *queue, void *data, size_t data_size)
{
	t_qnode	*new;

	new = (t_qnode *)ft_memalloc(sizeof(t_qnode));
	new->data = ft_memalloc(data_size);
	new->data = ft_memcpy(new->data, data, data_size);
	new->data_size = data_size;
	if (queue->last != NULL)
		queue->last->next = new;
	queue->last = new;
	if (queue->first == NULL)
		queue->first = queue->last;
}

void		*qpop(t_queue *queue)
{
	t_qnode	*dequeue_item;
	void	*dequeue_data;

	if (qis_empty(queue) == 1)
		return (NULL);
	dequeue_item = queue->first;
	queue->first = queue->first->next;
	dequeue_data = dequeue_item->data;
	free(dequeue_item);
	if (queue->first == NULL)
		queue->last = NULL;
	return (dequeue_data);
}


void		 *qpeek(t_queue *queue)
{
	if (qis_empty(queue) == 1)
		return (NULL);
	return (queue->first->data);
}

int			qis_empty(t_queue *queue)
{
	return (queue->first == NULL);
}