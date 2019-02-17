/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:43:45 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/05 17:43:45 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

/*
**	Get token data		[✓]
**	Get token type		[✓]
**	Skip token data		[✓]
**	Subject to change	[✓]
*/

/*
**	get_token()
**	- Takes in string, input
**	- Returns a data structure pointer of t_token type
**
**	* If the first character in input is:
**		1. An operator defined in lexer.h
**			1a. return token from get_operator_token()
**		2. A single, double, or back quote
**			2a. return token from get_quote_token()
**		3. None of the above
**			3a. return token from get_generic_token()
**
**	NOTE:
**		The function calling get_token() must skip all whitespace in input
**		beforehand. If whitespace is not skipped NULL will be returned
*/

static t_token		*get_token(char *input)
{
	if (is_operator(*input) == TRUE)
		return (get_operator_token(input));
	else if (is_quote(*input) == TRUE)
		return (get_quote_token(input));
	else if (ft_isspace(*input) == FALSE)
		return (get_generic_token(input));
	else
		return (NULL);
}

/*
**	tokenize()
**		- Takes in string, input
**		- Returns a queue data structure queued with data structure of
**		  t_token type
**
**	* While input has content to be evaluated
**		1. Skips all whitespace
**		2. Gets the next token in input
**		3. Stores the token into a queue
**		4. Skips the length of the token
**	- returns the queue of tokens
*/

t_token				*tokenize(char *input)
{
	t_token			*token_list;
	t_token			*cur;
	int				i;

	i = 0;
	token_list = NULL;
	while (input[i] != '\0')
	{
		while (input[i] != '\0' && ft_isspace(input[i]) == TRUE)
			i++;
		if (input[i] == '\0')
			break ;
		if (token_list == NULL)
		{
			token_list = get_token(input + i);
			cur = token_list;

		}
		else
			cur->next = get_token(input + i);
		if (cur->next != NULL)
			cur = cur->next;
		i += ft_strlen(cur->data);
	}
	return (token_list);
}
