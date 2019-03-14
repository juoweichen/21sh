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

t_astnode *command_1(t_token **curtoken)
{
	return (simple_command(curtoken));
}

t_astnode *command(t_token **curtoken)
{
	t_astnode *node;
	t_token *init_token;

	if (*curtoken == NULL)
		return (NULL);

	//store init token so it can restore before other options
	init_token = *curtoken;

	//is <simple_command> type?
	if ((node = command_1(curtoken)) != NULL)
		return (node);
	
	return (NULL);
}