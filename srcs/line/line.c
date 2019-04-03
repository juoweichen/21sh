/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:31:28 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/22 18:53:11 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

char	*ft_readline(void)
{
	t_edit		*edit;
	char		*ret;

	edit = init_edit();
	init_terminal_data(edit);
	import_history(edit);
	enable_raw_mode();
	ret = line_edit_body(edit);
	disable_raw_mode();
	free_edit(edit);
	return (ret);
}

t_edit	*init_edit(void)
{
	t_edit *new;

	new = ft_memalloc(sizeof(t_edit));
	new->array = (t_buffer**)ft_memalloc((sizeof(t_buffer*)) * 2);
	new->array[0] = ft_memalloc(sizeof(t_buffer));
	new->cur_col = 0;
	new->linemax = 1;
	new->quote = 0;
	new->buffer_change = 0;
	new->term = NULL;
	new->return_str = ft_strnew(1);
	new->clipboard = ft_strnew(1);
	new->killzone = 0;
	new->array[0]->line = ft_strnew(1024);
	new->array[0]->printlen = 0;
	new->array[0]->buffpos = 0;
	new->array[1] = NULL;
	new->hcount = 0;
	new->hmax = 0;
	new->is_eof = 1;
	return (new);
}

void	init_terminal_data(t_edit *line)
{
	char	*term;
	int		work;

	if (!(term = getenv("TERM")))
		perror_exit("Environment variable term does not exist\n");
	work = tgetent(term, line->term);
	if (work == 0)
		perror_exit("Terminal pointed to by $(TERM) is shit\n");
	else if (work == -1)
		perror_exit("Term database is fucked\n");
	get_window_size(line);
	tputs(tgetstr("ce", NULL), 0, term_putc);
	save_cursor_pos();
	return ;
}

char	*line_edit_body(t_edit *edit)
{
	long	num;
	int		len;

	num = 0;
	while (edit->is_eof)
	{
		num = 0;
		print_display(edit);
		len = read(STDIN_FILENO, &num, 6);
		process_input(num, len, edit);
		if ((int)num == '\n')
			return (newline_handler(edit));
	}
	return (NULL);
}

void	move_cursor_to_prompt(t_edit *edit)
{
	unsigned int buf;

	buf = edit->array[edit->killzone]->buffpos;
	edit->array[edit->killzone]->buffpos = 0;
	edit->cur_col = 0;
}
