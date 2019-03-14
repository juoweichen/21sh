/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:47:09 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/05 17:47:10 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

t_token				*new_token(char *data, int type)
{
	t_token			*token;

	if (!(token = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	token->data = data;
	token->type = type;
	token->next = NULL;
	return (token);
}

void				free_token(t_token *token)
{
	if (token != NULL)
	{
		if (token->data != NULL)
		{
			free(token->data);
			token->data = NULL;
		}
		free(token);
		token = NULL;
	}
}

void				free_token_list(t_token *token_list)
{
	t_token			*next;

	if (token_list != NULL)
	{
		while (token_list != NULL)
		{
			next = token_list->next;
			free_token(token_list);
			token_list = next;
		}
	}
}
