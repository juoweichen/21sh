/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

typedef struct		s_qnode
{
	void			*data;
	size_t			data_size;
	struct s_qnode	*next;
}					t_qnode;

typedef struct		s_queue
{
	t_qnode			*first;
	t_qnode			*last;
}					t_queue;

/*
**	queue.c
*/
t_queue				*queue_init(void);
void				qpush(t_queue *queue, void *data, size_t data_size);
void				*qpop(t_queue *queue);
void				*qpeek(t_queue *queue);
int					qis_empty(t_queue *queue);

#endif
