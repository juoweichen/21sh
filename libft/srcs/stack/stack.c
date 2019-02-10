/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_stack		*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack->root = NULL;
	return (stack);
}

void		spush(t_stack *stack, void *data, size_t data_size)
{
	t_snode *new;

	new = (t_snode *)ft_memalloc(sizeof(t_snode));
	new->data = ft_memalloc(data_size);
	new->data = ft_memcpy(new->data, data, data_size);
	new->data_size = data_size;
	new->next = stack->root;
	stack->root = new;
}

void		*spop(t_stack *stack)
{
	t_snode	*pop_item;
	void	*pop_data;

	if (sis_empty(stack) == 1)
		return (NULL);
	pop_item = stack->root;
	stack->root = stack->root->next;
	pop_data = pop_item->data;
	ft_memdel((void **)&pop_item);
	return (pop_data);
}

int			sis_empty(t_stack *stack)
{
	return (stack->root == NULL);
}

void		*speek(t_stack *stack)
{
	if (sis_empty(stack) == 1)
		return (NULL);
	return (stack->root->data);
}