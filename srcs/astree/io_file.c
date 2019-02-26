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

t_astnode *io_file_all(t_token **curtoken, char *type)
{
	t_astnode	*node;
	t_astnode	*r_child_node;
	char		*operator = NULL;

	if (*curtoken == NULL)
		return (NULL);

	//determined child node type
	if (!is_right_operator(curtoken, type, &operator))
		return (NULL);
	if ((r_child_node = filename(curtoken)) == NULL)
		return (NULL);

	//build this node
	node = build_node(NODE_IO_FILE);
	node->data = operator;
	node->right = r_child_node;
	return (node);
}

t_astnode *io_file(t_token **curtoken)
{
	t_astnode *node;
	t_token *init_token;

	if (*curtoken == NULL)
		return (NULL);

	//store init token so it can restore before other options
	init_token = *curtoken;

	//is LESSAND <filename> type?
	if ((node = io_file_all(curtoken, "<&")) != NULL)
		return (node);

	//is GREATAND <filename> type?
	*curtoken = init_token;
	if ((node = io_file_all(curtoken, ">&")) != NULL)
		return (node);

	//is DGREAT <filename> type?
	*curtoken = init_token;
	if ((node = io_file_all(curtoken, ">>")) != NULL)
		return (node);

	//is LESSGREAT <filename> type?
	*curtoken = init_token;
	if ((node = io_file_all(curtoken, "<>")) != NULL)
		return (node);

	//is CLOBBER <filename> type?
	*curtoken = init_token;
	if ((node = io_file_all(curtoken, ">|")) != NULL)
		return (node);

	//is '>' <filename> type?
	*curtoken = init_token;
	if ((node = io_file_all(curtoken, ">")) != NULL)
		return (node);

	//is '<' <filename> type?
	*curtoken = init_token;
	if ((node = io_file_all(curtoken, "<")) != NULL)
		return (node);
	
	return (NULL);
}