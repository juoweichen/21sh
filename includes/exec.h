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

#ifndef EXEC_H
# define EXEC_H

#include "../libft/includes/libft.h"
#include "astree.h"

typedef struct	s_exec_simple_command
{
	int			argc;
	char		**argv;
	
	int 		piperead;
	int 		pipewrite;
	
	char		*redirect_op;
	char		*redirect_filename;
}				t_exec_sc;

void 			execute_astree(t_astnode *astree);
void 			execute_simple_command(t_astnode *astree,
	int piperead, int pipewrite);
int				check_built_in(t_exec_sc *exec_sc);

#endif