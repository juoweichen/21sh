
#include "../../includes/line.h"

void	enable_raw_mode(void)
{
	struct termios raw;

	tcgetattr(STDIN_FILENO, &raw);
	g_original = raw;
	raw.c_lflag &= ~(ECHO | ICANON);
	raw.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &raw);
}

void	disable_raw_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSADRAIN, &g_original);
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
	max += (len + PROMPT_LEN - 1) / edit->screencol;
	// printf("\nsc: %d, max: %d, row: %d, base: %d, len: %d\n", edit->screencol, max, row, base, len);
	while (++row < max)
		ft_putstr(tgetstr("up", NULL));
	if (len > base)
		while (base < len--)
			ft_putstr(tgetstr("nd", NULL));
	else
		while (base > len++)
			ft_putstr(tgetstr("le", NULL));
	edit->cur_col = edit->array[edit->killzone]->buffpos;
}

void	print_display(t_edit *edit)
{
	int row;

	row = 0;
	edit->buffer_change = 0;
	while (row < ((int)edit->linemax))
	{
		clear_line();
		if (row + 1 == (int)edit->linemax)
		{
			edit->cur_col = edit->array[edit->killzone]->buffpos;
			put_prompt_line(row);
			tputs(edit->array[row]->line, 0, term_putc);
		}
		row++;			
	}
	align_cursor(edit);
}

void clear_line(void)
{
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr(tgetstr("ce", NULL));
	ft_putstr(tgetstr("cd", NULL));
}