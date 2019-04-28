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

#include "../../includes/lexer.h"
#include "../../includes/astree.h"

t_astnode	*io_file_all(t_token *init_token, t_token **curtoken, char *type)
{
	t_astnode	*node;
	t_astnode	*r_child_node;
	char		*operator;

	operator = NULL;
	*curtoken = init_token;
	if (*curtoken == NULL)
		return (NULL);
	if (!is_right_operator(curtoken, type, &operator))
		return (NULL);
	if ((r_child_node = filename(curtoken)) == NULL)
		return (NULL);
	node = build_node(NODE_IO_FILE);
	node->data = ft_strdup(operator);
	node->right = r_child_node;
	return (node);
}

t_astnode	*io_file(t_token **curtoken)
{
	t_astnode	*node;
	t_token		*init_token;

	if (*curtoken == NULL)
		return (NULL);
	init_token = *curtoken;
	if ((node = io_file_all(init_token, curtoken, "<&")) != NULL ||
		(node = io_file_all(init_token, curtoken, ">&")) != NULL ||
		(node = io_file_all(init_token, curtoken, ">>")) != NULL ||
		(node = io_file_all(init_token, curtoken, "<>")) != NULL ||
		(node = io_file_all(init_token, curtoken, ">|")) != NULL ||
		(node = io_file_all(init_token, curtoken, ">")) != NULL ||
		(node = io_file_all(init_token, curtoken, "<")) != NULL)
		return (node);
	return (NULL);
}
