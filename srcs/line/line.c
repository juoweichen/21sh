

#include "../../includes/line.h"
#include "../../includes/global.h"

char	*ft_readline(t_sh *sh)
{
	t_edit		edit;
	char		*ret;

	init_edit(&edit, sh);
	init_terminal_data(&edit);
	import_history(&edit);
	enable_raw_mode();
	ret = line_edit_body(&edit);
	disable_raw_mode();
	free_edit(&edit);
	return (ret);
}

void	init_edit(t_edit *edit, t_sh *sh)
{
	ft_bzero(edit, sizeof(t_edit));
	edit->array = ft_memalloc((sizeof(t_buffer*)) * 2);
	edit->array[0] = ft_memalloc(sizeof(t_buffer));
	edit->linemax = 1;
	edit->return_str = ft_strnew(1);
	edit->clipboard = ft_strnew(1);
	edit->array[0]->line = ft_strnew(1024);
	edit->array[0]->printlen = 0;
	edit->array[0]->buffpos = 0;
	edit->array[1] = NULL;
	edit->gas = TRUE;
	edit->env_dict = sh->env_dict;
	edit->com_dict = sh->com_dict;
	edit->path_programs = NULL;
	edit->dir_files = NULL;
	g_array = &edit->array;
	g_linemax = &edit->linemax;
	g_killzone = &edit->killzone;
	g_cur_col = &edit->cur_col;
}

void	init_terminal_data(t_edit *line)
{
	char	*term;
	int		work;

	if (!(term = getenv("TERM")))
		perror_exit("Terminal type not found! Set type with: seotenv TERM [type]\n");
	work = tgetent(term, line->term);
	if (work == 0)
		perror_exit("Terminal pointed to by $(TERM) is shit\n");
	else if (work == -1)
		perror_exit("Terminfo database not found!!\n");
	else if (work < 0)
		perror_exit("Could not access the termcap database!!\n");
	get_window_size(line);
	tputs(tgetstr("ce", NULL), 0, term_putc);
	save_cursor_pos();
	return ;
}

char	*line_edit_body(t_edit *edit)
{
	long	num;
	int		len;

	while (edit->gas)
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
