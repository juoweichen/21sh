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
#include "signals.h"
#include "string.h"
#include "line.h"

typedef	struct	s_sh
{
	t_dict		*env_dict;
}				t_sh;

#endif