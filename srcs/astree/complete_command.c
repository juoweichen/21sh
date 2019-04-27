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

t_astnode	*complete_command_2(t_token **curtoken)
{
	return (list(curtoken));
}

t_astnode	*complete_command_1(t_token **curtoken)
{
	t_astnode	*node;
	t_astnode	*l_child_node;
	char		*operator;

	operator = NULL;
	if ((l_child_node = list(curtoken)) == NULL)
		return (NULL);
	if (is_separator_op(curtoken, &operator) != 1)
	{
		free_astree(&l_child_node);
		return (NULL);
	}
	node = build_node(NODE_COMPLETE_COMMAND);
	node->left = l_child_node;
	node->data = ft_strdup(operator);
	return (node);
}

t_astnode	*complete_command(t_token **curtoken)
{
	t_astnode	*node;
	t_token		*init_token;

	if (*curtoken == NULL)
		return (NULL);
	init_token = *curtoken;
	if ((node = complete_command_1(curtoken)) != NULL)
		return (node);
	*curtoken = init_token;
	if ((node = complete_command_2(curtoken)) != NULL)
		return (node);
	return (NULL);
}
