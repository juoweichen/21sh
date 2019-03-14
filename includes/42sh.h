/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:23:56 by juochen           #+#    #+#             */
/*   Updated: 2019/02/09 13:23:57 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

#include "../libft/includes/libft.h"
#include "astree.h"
#include "exec.h"
#include "globby.h"
#include "lexer.h"
#include "print_btree.h"
#include "signal.h"
#include "string.h"

typedef struct s_tok
{
	char			*data;
	int				type;
	struct s_tok 	*next;
}					t_tok;

enum TokenType{
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_AMPERSAND = '&',
	CHAR_QOUTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SEMICOLON = ';',
	CHAR_WHITESPACE = ' ',
	CHAR_ESCAPESEQUENCE = '\\',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_NULL = 0,
	
	TOKEN	= -1,
};

#endif