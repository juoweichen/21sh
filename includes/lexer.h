/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:33:27 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/04 19:33:28 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/*
**	AND_IF	OR_IF	DSEMI
**	&&		||		;;
**	DLESS	DGREAT	LESSAND	GREATAND	LESSGREAT	DLESSDASH
**	<<		>>		<&					>&			<<-
**	CLOBBER
**	>\
**	LBRACE	RBRACE	BANG
**	{		}		!
*/

# define SEMI_COLON		(1 << 0)
# define PIPE			(1 << 1)
# define COMMAND_SUB	(1 << 2)
# define SL_ARROW		(1 << 3)
# define SR_ARROW		(1 << 4)
# define OPEN_DQUOTE	(1 << 5)
# define OPEN_SQUOTE	(1 << 6)
# define OPEN_BQUOTE	(1 << 7)
# define DL_ARROW		(1 << 8)
# define DR_ARROW		(1 << 9)
# define CLOSED_DQUOTE	(1 << 10)
# define CLOSED_SQUOTE	(1 << 11)
# define CLOSED_BQUOTE	(1 << 12)
# define NUMBER_TOKEN	(1 << 13)
# define STRING_TOKEN	(1 << 14)

# define OP_AND_QT_TOKS	";|$<>\"\'`"
# define DBL_TOK_OFFSET	5

typedef struct			s_token
{
	int					type;
	char				*data;
	struct s_token		*next;
}						t_token;

/*
**	lexer.c
*/

t_token					*tokenize(char *input);

/*
**	tokens.c
*/

t_token					*new_token(char *data, int type);
void					free_token(t_token *token);
void					free_token_list(t_token *token_list);

/*
**	types.c
*/

t_token					*get_operator_token(char *input);
t_token					*get_quote_token(char *input);
t_token					*get_generic_token(char *input);

/*
**	utils.c
*/

int						is_quote(char c);
int						is_operator(char c);
int						ft_isspace(char c);

#endif
