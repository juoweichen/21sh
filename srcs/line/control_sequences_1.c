/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_sequences_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:34:36 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/20 01:17:00 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

/*
** moves cursor right by num of col
*/

void	move_cursor_right_by(int col, t_edit *edit)
{
	int i;

	i = -1;
	while (++i < col)
		move_cursor_right(edit);
	return ;
}

/*
** moves cursor left by num of col
*/

void	move_cursor_left_by(int col, t_edit *edit)
{
	int i;

	i = -1;
	while (++i < col)
		move_cursor_left(edit);
	return ;
}

/*
** moves cursor to end of typed stuff
*/

void	move_cursor_to_end(t_edit *edit)
{
	unsigned int len;

	len = edit->array[edit->killzone]->printlen;
	edit->array[edit->killzone]->buffpos = len;
}

/*
** moves cursor to next alphanumeric sequence of char;
*/

void	move_cursor_to_next_word(t_edit *edit)
{
	char			s;
	unsigned int	buf;
	char			*line;

	buf = edit->array[edit->killzone]->buffpos;
	line = edit->array[edit->killzone]->line;
	s = line[buf + 1];
	while (ft_isalnum(s) && (s != '\0'))
	{
		move_cursor_right_by(1, edit);
		buf = edit->array[edit->killzone]->buffpos;
		line = edit->array[edit->killzone]->line;
		s = line[buf + 1];
	}
	while (!ft_isalnum(s) && (s != '\0'))
	{
		move_cursor_right_by(1, edit);
		buf = edit->array[edit->killzone]->buffpos;
		line = edit->array[edit->killzone]->line;
		s = line[buf + 1];
	}
	if (ft_isalnum(s) && (s != '\0'))
		move_cursor_right_by(1, edit);
}

/*
** moves cursor to previous alphanumeric sequence of char;
*/

void	move_cursor_to_previous_word(t_edit *edit)
{
	char			s;
	unsigned int	buf;
	char			*line;

	buf = edit->array[edit->killzone]->buffpos;
	line = edit->array[edit->killzone]->line;
	s = line[buf];
	while (ft_isalnum(s) && (buf != 0))
	{
		move_cursor_left_by(1, edit);
		buf = edit->array[edit->killzone]->buffpos;
		line = edit->array[edit->killzone]->line;
		s = line[buf];
	}
	while (!ft_isalnum(s) && (buf != 0))
	{
		move_cursor_left_by(1, edit);
		buf = edit->array[edit->killzone]->buffpos;
		line = edit->array[edit->killzone]->line;
		s = line[buf];
	}
}
