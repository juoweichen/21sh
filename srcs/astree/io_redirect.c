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

t_astnode *io_redirect_4(t_token **curtoken)
{
	return (io_here(curtoken));
}

t_astnode *io_redirect_3(t_token **curtoken)
{
	t_astnode	*node;
	t_astnode	*r_child_node;
	char		*io_number;

	if (*curtoken == NULL)
		return (NULL);

	//determined child node type
	if (is_number_node(curtoken) == -1)
		return (NULL);
	io_number = ft_strdup((*curtoken)->data);
	if ((r_child_node = io_here(curtoken)) == NULL)
		return (NULL);

	//build this node
	node = build_node(NODE_IO_REDIRECT);
	node->data = ft_strdup(io_number);
	node->right = r_child_node;
	return (node);
}

t_astnode *io_redirect_2(t_token **curtoken)
{
	return (io_file(curtoken));
}

t_astnode *io_redirect_1(t_token **curtoken)
{
	t_astnode	*node;
	t_astnode	*r_child_node;
	char		*io_number;

	if (*curtoken == NULL)
		return (NULL);

	//determined child node type
	if (is_number_node(curtoken) == -1)
		return (NULL);
	io_number = ft_strdup((*curtoken)->data);
	*curtoken = (*curtoken)->next;
	if ((r_child_node = io_file(curtoken)) == NULL)
		return (NULL);

	//build this node
	node = build_node(NODE_IO_REDIRECT);
	node->data = ft_strdup(io_number);
	node->right = r_child_node;
	return (node);
}

t_astnode *io_redirect(t_token **curtoken)
{
	t_astnode *node;
	t_token *init_token;

	if (*curtoken == NULL)
		return (NULL);

	//store init token so it can restore before other options
	init_token = *curtoken;

	//is <IO_NUMBER> <io_file> type?
	if ((node = io_redirect_1(curtoken)) != NULL)
		return (node);
	
	//restore curtoken to init_token
	*curtoken = init_token;

	//is <io_file> type?
	if ((node = io_redirect_2(curtoken)) != NULL)
		return (node);

	//restore curtoken to init_token
	*curtoken = init_token;
	
	//is <IO_NUMBER> <io_here> type?
	if ((node = io_redirect_3(curtoken)) != NULL)
		return (node);

	//restore curtoken to init_token
	*curtoken = init_token;
	
	//is <io_here> type?
	if ((node = io_redirect_4(curtoken)) != NULL)
		return (node);
	
	return (NULL);
}