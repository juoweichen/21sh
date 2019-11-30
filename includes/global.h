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

#ifndef GLOBAL_H
# define GLOBAL_H

#include "line.h"

t_buffer 				***g_array;
unsigned int			*g_linemax;
unsigned int			*g_killzone;
unsigned int			*g_cur_col;
unsigned int			g_gasgas;

#endif