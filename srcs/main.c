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

	while (1)
	{
		line = ft_readline();
		printf("\n");
		token = tokenize(line);

		build_astree(token, &astree);
		execute_astree(astree);

		free(line);
		free_token_list(token);
		free_astree(&astree);
	}
}