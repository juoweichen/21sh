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

#include "../includes/lexer.h"
#include "../includes/astree.h"
#include "../includes/print_btree.h"
#include "../includes/exec.h"

int build_astree(t_token *token, t_astnode **astree)
{
	if (token == NULL)
	{
		ft_printf("Empty token error\n");
		return (-1);
	}
	//for now the most top node is this
	if ((*astree = complete_command(&token)) == NULL)
		return (-1);
	return (0);
}

int main(void)
{
	t_token *token;
	t_astnode *astree;

	token = tokenize("cat sample | grep -v a | sort -r | cat -e > hahahahha");
	// token = tokenize("ls -la | cat -e | more");
	// token = tokenize("mkdir test ; cd test ; ls -a ; ls | cat | wc -c > fifi ; cat fifi");

	// t_token *ptr = token;

	// while (ptr)
	// {
	// 	ft_printf("%s ", ptr->data);
	// 	ptr = ptr->next;
	// }
	// printf("\n");

	if (build_astree(token, &astree) == -1)
	{
		perror("unable to build astree\n");
		exit(1);
	}
	
	printBinaryTree(astree);
	travesal_astree_print_command(astree);
	printf("\n");

	//execute AST
	execute_astree(astree);

	return (0);
}
