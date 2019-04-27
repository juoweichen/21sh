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

t_astnode	*simple_command_2(t_token **curtoken)
{
	return (cmd_name(curtoken));
}

t_astnode	*simple_command_1(t_token **curtoken)
{
	t_astnode *this_node;
	t_astnode *l_child_node;
	t_astnode *r_child_node;

	if ((l_child_node = cmd_name(curtoken)) == NULL)
		return (NULL);
	if ((r_child_node = cmd_suffix(curtoken)) == NULL)
	{
		free_astree(&l_child_node);
		return (NULL);
	}
	this_node = build_node(NODE_SIMPLE_COMMAND);
	this_node->left = l_child_node;
	this_node->right = r_child_node;
	return (this_node);
}

t_astnode	*simple_command(t_token **curtoken)
{
	t_astnode	*node;
	t_token		*init_token;

	if (*curtoken == NULL)
		return (NULL);
	init_token = *curtoken;
	if ((node = simple_command_1(curtoken)) != NULL)
		return (node);
	*curtoken = init_token;
	if ((node = simple_command_2(curtoken)) != NULL)
		return (node);
	return (NULL);
}
