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

	// line = ft_readline();
	line = "ls -la";

	//test
	printf("line: %s\n", line);
	//test end

	// sleep(10);

	token = tokenize(line);

	//test
	t_token *ptr;
	ptr = token;
	while (ptr)
	{
		printf("%s -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	//test end

	// sleep(10);

	build_astree(token, &astree);

	//test
	printBinaryTree(astree);
	//test end

	// free_token_list(token);
	// free_astree(&astree);
	// sleep(10);

	execute_astree(astree);

	// free(line);
	free_token_list(token);
	free_astree(&astree);
	sleep(10);
}