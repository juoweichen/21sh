/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct		s_snode
{
	void			*data;
	size_t			data_size;
	struct s_snode	*next;
}					t_snode;

typedef struct		s_stack
{
	t_snode			*root;
}					t_stack;

/*
**	stack.c
*/
t_stack				*stack_init(void);
void				spush(t_stack *stack, void *data, size_t data_size);
void				*spop(t_stack *stack);
int					sis_empty(t_stack *stack);
void				*speek(t_stack *stack);

#endif