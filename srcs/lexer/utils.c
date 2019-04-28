/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:23:59 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/12 15:23:59 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

/*
**	The below operations return TRUE or FALSE depending on if the given
**	character matches any of the characters in the given static strings
*/

int					is_quote(char c)
{
	if (ft_strchr("\"\'`", c) != NULL)
		return (TRUE);
	return (FALSE);
}

int					is_operator(char c)
{
	if (ft_strchr(";|&<>", c) != NULL)
		return (TRUE);
	return (FALSE);
}

int					ft_isspace(char c)
{
	if (ft_strchr(" \t\n", c) != NULL)
		return (TRUE);
	return (FALSE);
}
