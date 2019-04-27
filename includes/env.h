/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:23:56 by juochen           #+#    #+#             */
/*   Updated: 2019/04/26 22:54:34 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <dirent.h>
# include "lexer.h"
# include "astree.h"
# include "../libft/includes/libft.h"

typedef	struct	s_sh
{
	t_dict		*env_dict;
	t_dict		*com_dict;
	t_dict		*iv_dict;
}				t_sh;

typedef struct	s_com
{
	char		*name;
	char		*path;
}				t_com;

void			env_init(t_sh *sh);
void			command_init(t_sh *sh);
void			intern_variable_init(t_sh *sh);
void			quick_sort_str_dlist(t_dlist *dlist);
void			quick_sort_str_list(t_list **list);
void			expand_enviornment_variables(t_token *token, t_sh *sh);

#endif
