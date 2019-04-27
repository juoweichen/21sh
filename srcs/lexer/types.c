/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:14:22 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/05 18:14:23 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/42sh.h"

/*
**	get_shift()
**		- Takes in a single char
**		- Returns a short on success and -1 on failure
**
**	Finds the bit shift needed to flag the correct type. Types are defined in
**	lexer.h
**	The location of an operator or quote in the string OP_AND_QT_TOKS
**	corresponds to the correct bit shift associated with the given operator
**	or quote
**
**	NOTE:
**		get_shift() will never be called unless the character c is of operator
**		or quote token type
*/

static short		get_shift(char c)
{
	short			shift;

	shift = -1;
	while (OP_AND_QT_TOKS[++shift] != '\0')
		if (c == OP_AND_QT_TOKS[shift])
			return (1 << shift);
	return (-1);
}

/*
**	get_operator_token()
**		- Takes in string, input
**		- Returns a data structure pointer of t_token type
**
**	1. shift is set to the bit shift associated with the operator character
**	   at input[0]
**	* In the situation that the operator character at input[0] is '<' or '>'
**		* If the following character at input[1] matches the '<' or '>'
**		  character at input[0] the operator consists of two characters
**			2. return a new token
**				2a. token data is a string consisting of input[0 - 1]
**				2b. token data is shift left shifted by the offset for 2
**					character token types
**	3. return a new token
**		3a. token data is a string consisting of input[0] only
**		3b. token type is shift
**
**	NOTE:
**		get_operator_token() should only called when input[0] is equal to an
**		operator character
*/

t_token				*get_operator_token(char *input)
{
	int				shift;
	int				i;

	shift = 0;
	i = 0;
	shift = get_shift(*input);
	if ((input[i] == '<' && input[i + 1] == '<') ||
		(input[i] == '>' && input[i + 1] == '>') ||
		(input[i] == '|' && input[i + 1] == '|') ||
		(input[i] == '&' && input[i + 1] == '&'))
		return (new_token(ft_strndup(input, i + 2), (shift << DBL_TOK_OFFSET)));
	else if (input[i] == '>' && input[i + 1] == '&')
		return (new_token(ft_strndup(input, i + 2), SR_ARROW_AND));
	else if (input[i] == '<' && input[i + 1] == '&')
		return (new_token(ft_strndup(input, i + 2), SL_ARROW_AND));
	return (new_token(ft_strndup(input, i + 1), shift));
}

/*
**	get_quote_token()
**		- Takes in a string, input
**		- Returns a data structure pointer to t_token type
**
**	1. matching_quote is set to the first character of input which will always
**	   be a double quote, single quote, or back quote
**	2. shift is set to the bit shift associated with the operator character
**	   at input[0]
**	3. i is set to 0 so that ++i will start at the second character in input,
**	   skipping the first quote located at input[0]
**	* While input[i] is a valid character
**		* If input[i] is euqal to matching_quote
**			4. Return a new token
**				4a. token data is the contents of input from the first given
**					quote up until the matching closing quote
**				4b. token data is shift left shifted by the offset for 2
**					character token types
**	5. Return a new token
**		5a. token data is the entirety of input because no matching closing
**			quote was found
**		5b. token type is shift
*/

static int			has_matching_quote(char *str, char match)
{
	int				i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == match)
			return (1);
	return (0);
}

t_token				*get_quote_token(char *input)
{
	char			matching_quote;
	int				shift;
	int				i;

	matching_quote = *input;
	shift = get_shift(matching_quote);
	i = 0;
	if (has_matching_quote(input + 1, *input))
	{
		while (input[++i] != '\0')
			if (input[i] == matching_quote)
				return (new_token(ft_strndup(input, i + 1),
					(shift << DBL_TOK_OFFSET)));
	}
	else
	{
		while (input[++i] != '\0')
			if (is_quote(input[i]))
				return (new_token(ft_strndup(input, i), shift));
	}
	return (new_token(ft_strdup(input), shift));
}

/*
**	get_generic_token()
**		- Takes in a string, input
**		- Returns a data structure pointer to t_token type
**
**	1. The index, i is set to 1 or 0 depending on if input starts with a '+'
**	   or '-' character (numbers that start with '+' or '-' are still valid).
**	2. valid_num is set to true or false depending on if the only character
**	   in input was '+' or '-' (a single '+' or '-' is a valid string)
**	* While input[i] is a valid character
**		* If the value of input[i] is that of operator or quote type, or the
**		  any whitespace is found
**			3. Break the while loop
**		* If any value of input[i] is not of numerical value
**			4. valid_num is set to false. Valid base 10 number values do not
**			   contain anything besides numerical values
**	* If the evaluation of input is in fact all numerical values
**		5. Return a new token
**			5a. token data is the contents of input from start up until i
**			5b. token type is of NUMBER_TOKEN
**	6. Return a new node
**		6a. token data is the contents of input from start up until i
**		6b. token type is of STRING_TOKEN
*/

t_token				*get_generic_token(char *input)
{
	int				valid_num;
	int				i;

	i = (*input == '+' || *input == '-') ? 1 : 0;
	valid_num = (input[i] != '\0') ? TRUE : FALSE;
	while (input[i] != '\0')
	{
		if (is_operator(input[i]) == TRUE || is_quote(input[i]) == TRUE
			|| ft_isspace(input[i]) == TRUE)
			break ;
		if (valid_num == TRUE && !ft_isdigit(input[i]))
			valid_num = FALSE;
		i++;
	}
	if (valid_num == TRUE)
		return (new_token(ft_strndup(input, i), NUMBER_TOKEN));
	return (new_token(ft_strndup(input, i), STRING_TOKEN));
}
