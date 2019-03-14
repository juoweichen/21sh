/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:09:17 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/18 15:09:17 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/42sh.h"

int main(void)
{
	char *line;
	t_token *token;
	t_astnode *astree;

	//test
	t_token *ptr;
	//test end

	while (1)
	{
		line = ft_readline();

		//test
		printf("line: %s\n", line);
		//test end

		token = tokenize(line);

		//test
		ptr = token;
		while (ptr)
		{
			printf("%s -> ", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
		//test end

		build_astree(token, &astree);

		//test
		printBinaryTree(astree);
		//test end

		execute_astree(astree);

		free(line);
	}
}