/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:23:44 by juochen           #+#    #+#             */
/*   Updated: 2019/02/09 13:23:46 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/42sh.h"

int main(void)
{
	int a = 1, b = 2, c = 3, d = 42;

	//queue
	t_queue *q = queue_init();

	qpush(q, &a, sizeof(int));
	qpush(q, &b, sizeof(int));
	qpush(q, &c, sizeof(int));
	qpush(q, &d, sizeof(int));

	printf("qpeek: %d\n", *(int *)qpeek(q));

	while (qis_empty(q) != 1)
		printf("%d, ", *(int *)qpop(q));
	printf("\n");

	//stack
	t_stack *s = stack_init();

	spush(s, &a, sizeof(int));
	spush(s, &b, sizeof(int));
	spush(s, &c, sizeof(int));
	spush(s, &d, sizeof(int));

	printf("speek: %d\n", *(int *)speek(s));

	while (sis_empty(s) != 1)
		printf("%d, ", *(int *)spop(s));
	printf("\n");

	return (0);
}