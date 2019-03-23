/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:50:09 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/22 15:55:15 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

int			move_to_close(char *str, int *index, char quote)
{
	int	i;

	i = *index + 1;
	while (str[i] != quote && str[i] != '\0')
		i++;
	*index = i;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

t_tracker	double_quote_handler(char *str, int *index, t_tracker quote)
{
	int i;

	i = *index + 1;
	quote.dbl ^= 1;
	while (str[i] != '\0')
	{
		if (str[i] == '`')
		{
			quote.bck ^= 1;
			if (move_to_close(str, &i, '`') == 0)
				quote.bck ^= 1;
		}
		else if (str[i] == '\"' && str[i] != '\0')
			quote.dbl ^= 1;
		if (str[i] != '\0')
			i++;
	}
	*index = i;
	return (quote);
}

t_tracker	check_each_char_in_the_str(char *s, int *index, t_tracker quote)
{
	int i;

	i = *index;
	if (s[i] == '\'' && s[i] != '\0')
	{
		quote.sgl ^= 1;
		if (move_to_close(s, &(i), '\'') == 0)
			quote.sgl ^= 1;
	}
	else if (s[i] == '\"' && s[i] != '\0')
		quote = double_quote_handler(s, &i, quote);
	else if (s[i] == '`' && s[i] != '\0')
	{
		quote.bck ^= 1;
		if (move_to_close(s, &i, '`') == 0)
			quote.bck ^= 1;
	}
	if (s[i] != '\0')
		i++;
	*index = i;
	return (quote);
}

int			quotes_are_closed(char *s)
{
	int			i;
	t_tracker	quote;

	quote.dbl = 0;
	quote.sgl = 0;
	quote.bck = 0;
	i = 0;
	while (s[i] != '\0')
		check_each_char_in_the_str(s, &i, quote);
	if (s[i - 1] == '\\')
		return (5);
	if (quote.sgl == 1)
		return (1);
	else if (quote.dbl == 1)
		return (2);
	else if (quote.bck == 1)
		return (3);
	return (0);
}
