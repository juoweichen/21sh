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

t_astnode *complete_command_2(t_token **curtoken)
{
	return (list(curtoken));
}

t_astnode *complete_command_1(t_token **curtoken)
{
	t_astnode *node;
	t_astnode *l_child_node;
	char *operator = NULL;

	//test if fit this type
	if ((l_child_node = list(curtoken)) == NULL)
		return (NULL);
	if (is_separator_op(curtoken, &operator) != 1)  //will store operator
	{
		del_astnode(&l_child_node);
		return (NULL);
	}
	//type correct, build node and return
	node = build_node(NODE_COMPLETE_COMMAND);
	node->left = l_child_node;
	node->data = operator;
	return (node);
}

t_astnode *complete_command(t_token **curtoken)
{
	t_astnode *node;
	t_token *init_token;

	if (*curtoken == NULL)
		return (NULL);
	//store init token so it can restore before other options
	init_token = *curtoken;

	//is <command> '|' <pipe_sequence> type?
	if ((node = complete_command_1(curtoken)) != NULL)
		return (node);
	
	//restore curtoken to init_token
	*curtoken = init_token;

	//is <command> type?
	if ((node = complete_command_2(curtoken)) != NULL)
		return (node);
	
	return (NULL);
}