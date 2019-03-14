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

t_astnode *simple_command_2(t_token **curtoken)
{
	return (cmd_name(curtoken));
}

t_astnode *simple_command_1(t_token **curtoken)
{
	t_astnode *this_node;
	t_astnode *l_child_node;
	t_astnode *r_child_node;

	//test if fit this type
	if ((l_child_node = cmd_name(curtoken)) == NULL)
		return (NULL);
	if ((r_child_node = cmd_suffix(curtoken)) == NULL)
	{
		del_astnode(&l_child_node);
		return (NULL);
	}

	//build this node
	this_node = build_node(NODE_SIMPLE_COMMAND);
	this_node->left = l_child_node;
	this_node->right = r_child_node;
	return (this_node);
}

t_astnode *simple_command(t_token **curtoken)
{
	t_astnode *node;
	t_token *init_token;

	if (*curtoken == NULL)
		return (NULL);

	//store init token so it can restore before other options
	init_token = *curtoken;

	//is <simple_command> type?
	if ((node = simple_command_1(curtoken)) != NULL)
		return (node);

	//restore curtoken to init_token
	*curtoken = init_token;
	
	//is <simple_command> type?
	if ((node = simple_command_2(curtoken)) != NULL)
		return (node);
	
	return (NULL);
}