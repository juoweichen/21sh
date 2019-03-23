/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:55:57 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/22 13:06:08 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

void	enable_raw_mode(void)
{
	struct termios raw;

	tcgetattr(STDIN_FILENO, &raw);
	g_original = raw;
	raw.c_lflag &= ~(ECHO | ICANON);
	raw.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void	disable_raw_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_original);
}

void	align_cursor(t_edit *edit)
{
	unsigned int max;
	unsigned int row;
	unsigned int base;
	unsigned int len;

	max = edit->linemax;
	row = edit->killzone;
	base = edit->array[edit->linemax - 1]->printlen;
	len = edit->array[edit->killzone]->buffpos;
	while (++row < max)
	{
		ft_putstr(tgetstr("up", NULL));
	}
	if (len > base)
		while (base < len--)
			ft_putstr(tgetstr("nd", NULL));
	else
		while (base > len++)
			ft_putstr(tgetstr("le", NULL));
	edit->cur_col = edit->array[edit->killzone]->buffpos;
}

void	move_clear_till_top_and_clear(t_edit *edit)
{
	int printdisplay;

	printdisplay = (int)edit->linemax - 1;
	while (printdisplay > 0)
	{
		ft_putstr(tgetstr("up", NULL));
		printdisplay--;
	}
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr(tgetstr("ce", NULL));
	ft_putstr(tgetstr("cd", NULL));
}

void	print_display(t_edit *edit)
{
	int row;
	int col;

	row = 0;
	col = edit->cur_col;
	recall_last_cursor_pos();
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr(tgetstr("ce", NULL));
	ft_putstr(tgetstr("cd", NULL));
	edit->buffer_change = 0;
	while (row < ((int)edit->linemax))
	{
		put_prompt_line(row);
		edit->cur_col = edit->array[edit->killzone]->buffpos;
		tputs(edit->array[row]->line, 0, term_putc);
		if (++row < (int)edit->linemax)
			move_cursor_newline(edit);
	}
	align_cursor(edit);
}
