/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:17:12 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/20 01:22:01 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

/*
** movement of  cursor;
*/

void	move_cursor_right(t_edit *edit)
{
	unsigned int buf;
	unsigned int printlen;

	buf = edit->array[edit->killzone]->buffpos;
	printlen = edit->array[edit->killzone]->printlen;
	if (buf == printlen)
		return ;
	edit->cur_col++;
	edit->array[edit->killzone]->buffpos++;
}

void	move_cursor_left(t_edit *edit)
{
	unsigned int buf;

	buf = edit->array[edit->killzone]->buffpos;
	if (buf == 0)
	{
		edit->array[edit->killzone]->buffpos = 0;
		edit->cur_col = 0;
		return ;
	}
	edit->cur_col--;
	edit->array[edit->killzone]->buffpos--;
}

void	move_cursor_newline(t_edit *edit)
{
	tputs(tgetstr("do", NULL), 0, term_putc);
	tputs(tgetstr("cr", NULL), 0, term_putc);
	edit->cur_col = 0;
}

void	move_cursor_lmargin(t_edit *edit)
{
	tputs(tgetstr("ce", NULL), 0, term_putc);
	edit->cur_col = 0;
}

int		term_putc(int c)
{
	write(1, &c, 1);
	return (0);
}
