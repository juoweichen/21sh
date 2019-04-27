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

t_astnode	*io_here_all(t_token **curtoken, char *type)
{
	t_astnode	*node;
	t_astnode	*r_child_node;
	char		*operator;

	if (*curtoken == NULL)
		return (NULL);
	if (!is_right_operator(curtoken, type, &operator))
		return (NULL);
	if ((r_child_node = here_end(curtoken)) == NULL)
		return (NULL);
	node = build_node(NODE_IO_HERE);
	node->data = ft_strdup(operator);
	node->right = r_child_node;
	return (node);
}

t_astnode	*io_here(t_token **curtoken)
{
	t_astnode	*node;
	t_token		*init_token;

	if (*curtoken == NULL)
		return (NULL);
	init_token = *curtoken;
	if ((node = io_here_all(curtoken, "<<")) != NULL)
		return (node);
	*curtoken = init_token;
	if ((node = io_here_all(curtoken, "<<-")) != NULL)
		return (node);
	return (NULL);
}
