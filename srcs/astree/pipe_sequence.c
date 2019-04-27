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

t_astnode	*pipe_sequence_2(t_token **curtoken)
{
	return (command(curtoken));
}

t_astnode	*pipe_sequence_1(t_token **curtoken)
{
	t_astnode	*node;
	t_astnode	*l_child_node;
	t_astnode	*r_child_node;
	char		*operator;

	operator = NULL;
	if ((l_child_node = command(curtoken)) == NULL)
		return (NULL);
	if (!is_right_operator(curtoken, "|", &operator))
	{
		free_astree(&l_child_node);
		return (NULL);
	}
	if ((r_child_node = pipe_sequence(curtoken)) == NULL)
	{
		free_astree(&l_child_node);
		return (NULL);
	}
	node = build_node(NODE_PIPE_SEQUENCE);
	node->left = l_child_node;
	node->data = ft_strdup(operator);
	node->right = r_child_node;
	return (node);
}

t_astnode	*pipe_sequence(t_token **curtoken)
{
	t_astnode	*node;
	t_token		*init_token;

	if (*curtoken == NULL)
		return (NULL);
	init_token = *curtoken;
	if ((node = pipe_sequence_1(curtoken)) != NULL)
		return (node);
	*curtoken = init_token;
	if ((node = pipe_sequence_2(curtoken)) != NULL)
		return (node);
	return (NULL);
}
