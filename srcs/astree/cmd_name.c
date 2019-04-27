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

t_astnode	*cmd_name(t_token **curtoken)
{
	t_astnode	*this_node;

	if (!is_word_node(curtoken))
		return (NULL);
	this_node = build_node(NODE_CMD_NAME);
	this_node->data = ft_strdup((*curtoken)->data);
	*curtoken = (*curtoken)->next;
	return (this_node);
}
