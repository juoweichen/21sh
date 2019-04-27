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

t_astnode	*cmd_suffix_4(t_token **curtoken)
{
	return (io_redirect(curtoken));
}

t_astnode	*cmd_suffix_3(t_token **curtoken)
{
	t_astnode *node;
	t_astnode *l_child_node;
	t_astnode *r_child_node;

	if (*curtoken == NULL)
		return (NULL);
	if ((l_child_node = io_redirect(curtoken)) == NULL)
		return (NULL);
	if ((r_child_node = cmd_suffix(curtoken)) == NULL)
	{
		free_astree(&l_child_node);
		return (NULL);
	}
	node = build_node(NODE_CMD_SUFFIX);
	node->left = l_child_node;
	node->right = r_child_node;
	return (node);
}

t_astnode	*cmd_suffix_2(t_token **curtoken)
{
	return (cmd_word(curtoken));
}

t_astnode	*cmd_suffix_1(t_token **curtoken)
{
	t_astnode *node;
	t_astnode *l_child_node;
	t_astnode *r_child_node;

	if (*curtoken == NULL)
		return (NULL);
	if ((l_child_node = cmd_word(curtoken)) == NULL)
		return (NULL);
	if ((r_child_node = cmd_suffix(curtoken)) == NULL)
	{
		free_astree(&l_child_node);
		return (NULL);
	}
	node = build_node(NODE_CMD_SUFFIX);
	node->left = l_child_node;
	node->right = r_child_node;
	return (node);
}

t_astnode	*cmd_suffix(t_token **curtoken)
{
	t_astnode	*node;
	t_token		*init_token;

	if (*curtoken == NULL)
		return (NULL);
	init_token = *curtoken;
	if ((node = cmd_suffix_3(curtoken)) != NULL)
		return (node);
	*curtoken = init_token;
	if ((node = cmd_suffix_4(curtoken)) != NULL)
		return (node);
	*curtoken = init_token;
	if ((node = cmd_suffix_1(curtoken)) != NULL)
		return (node);
	*curtoken = init_token;
	if ((node = cmd_suffix_2(curtoken)) != NULL)
		return (node);
	return (NULL);
}
