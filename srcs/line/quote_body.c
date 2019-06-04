/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 02:18:13 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/22 13:28:43 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

void	print_display_quote(t_edit *edit)
{
	int row;
	int col;

	row = 1;
	col = edit->cur_col;
	recall_last_cursor_pos();
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr(tgetstr("ce", NULL));
	ft_putstr(tgetstr("cd", NULL));
	edit->buffer_change = 0;
	while (row < ((int)edit->linemax))
	{
		tputs(QUOTE_PROMPT, 0, term_putc);
		edit->cur_col = edit->array[edit->killzone]->buffpos;
		tputs(edit->array[row]->line, 0, term_putc);
		if (++row < (int)edit->linemax)
		{
			tputs(tgetstr("cr", NULL), 0, term_putc);
			ft_putstr(tgetstr("ce", NULL));
			ft_putstr(tgetstr("cd", NULL));
		}
	}
	align_cursor(edit);
}

char	*quote_body(t_edit *edit)
{
	long	num;
	int		len;

	num = 0;
	tputs(tgetstr("do", NULL), 0, term_putc);
	while (edit->is_eof)
	{
		num = 0;
		print_display_quote(edit);
		len = read(STDIN_FILENO, &num, 6);
		process_input(num, len, edit);
		if ((int)num == '\n')
		{
			edit->cur_col = 0;
			return (newline_handler(edit));
		}
	}
	return (NULL);
}