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

#ifndef ASTREE_H
# define ASTREE_H

# include "../libft/includes/libft.h"
# include "lexer.h"

/*
**	NODE_COMMAND = 				1
**	NODE_SIMPLE_COMMAND = 		2
**	NODE_CMD_NAME = 			4
**	NODE_CMD_SUFFIX = 			8
**	NODE_CMD_WORD = 			16
**	NODE_PIPE_SEQUENCE = 		32
**	NODE_IO_REDIRECT = 			64
**	NODE_IO_FILE = 				128
**	NODE_FILENAME = 			256
**	NODE_IO_HERE = 				512
**	NODE_HERE_END = 			1024
**	NODE_COMPLETE_COMMAND = 	2048
**	NODE_LIST = 				4096
*/

typedef enum {
	NODE_COMMAND = (1 << 0),
	NODE_SIMPLE_COMMAND = (1 << 1),
	NODE_CMD_NAME = (1 << 2),
	NODE_CMD_SUFFIX = (1 << 3),
	NODE_CMD_WORD = (1 << 4),
	NODE_PIPE_SEQUENCE = (1 << 5),
	NODE_IO_REDIRECT = (1 << 6),
	NODE_IO_FILE = (1 << 7),
	NODE_FILENAME = (1 << 8),
	NODE_IO_HERE = (1 << 9),
	NODE_HERE_END = (1 << 10),
	NODE_COMPLETE_COMMAND = (1 << 11),
	NODE_LIST = (1 << 12)
}	t_node_type;

typedef struct			s_astnode
{
	int					type;
	char				*data;
	struct s_astnode	*left;
	struct s_astnode	*right;
}						t_astnode;

/*
**	build_astree.c
**	Entry function
*/
int						build_astree(t_token *token, t_astnode **astree);

/*
**	from exec dir
*/
t_astnode				*pipe_sequence(t_token **curtoken);
t_astnode				*command(t_token **curtoken);
t_astnode				*simple_command(t_token **curtoken);
t_astnode				*cmd_name(t_token **curtoken);
t_astnode				*cmd_word(t_token **curtoken);
t_astnode				*cmd_suffix(t_token **curtoken);
t_astnode				*io_redirect(t_token **curtoken);
t_astnode				*io_file(t_token **curtoken);
t_astnode				*filename(t_token **curtoken);
t_astnode				*io_here(t_token **curtoken);
t_astnode				*here_end(t_token **curtoken);
t_astnode				*complete_command(t_token **curtoken);
t_astnode				*list(t_token **curtoken);
t_astnode				*and_or(t_token **curtoken);
t_astnode				*pipeline(t_token **curtoken);

/*
**	astree_helper.c
*/
t_astnode				*build_node(t_node_type type);
int						is_right_operator(t_token **curtoken,
	char *type, char **ops);
int						is_word_node(t_token **curtoken);
void					travesal_astree_print_command(t_astnode *astree);
int						is_number_node(t_token **curtoken);
int						is_separator_op(t_token **curtoken, char **op);
void					free_astree(t_astnode **node);

#endif
