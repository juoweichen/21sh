/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 23:58:19 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/22 20:49:02 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H
# include "unistd.h"
# include "termios.h"
# include "term.h"
# include "stdlib.h"
# include "stdio.h"
# include "curses.h"
# include "../libft/includes/libft.h"

# define PROMPT "42sh>"
# define QUOTE_PROMPT ">>>>>"

# define K_UP 4283163
# define K_DOWN 4348699
# define K_LEFT 4479771
# define K_RIGHT 4414235
# define CTRL_UPK 71696882162459
# define CTRL_DNK 72796393790235
# define CTRL_LFK 74995417045787
# define CTRL_RTK 73895905418011
# define K_DEL 2117294875
# define K_BS 127
# define CTRL_K 11
# define CTRL_E 5
# define CTRL_U 21
# define CTRL_G 7
# define CTRL_I 6
# define CTRL_W 23
# define CTRL_L 12
# define CTRL_D 0	// <== not sure if I can put 0
# define ALT_F 37574
# define ALT_G 43458
# define ALT_K 39627
# define ALT_L 44226
# define ALT_O 47299
# define ALT_P 32975
# define ALT_Q 37829
# define ALT_D 8554722
# define HOME_B 4741915
# define END_B 4610843
# define NEWLINE 10
# define PROMPT_LEN 5

typedef	struct		s_buffr
{
	unsigned int	buffpos;
	unsigned int	printlen;
	char			*line;
}					t_buffer;

typedef struct		s_edit
{
	struct termios	*original;
	unsigned int	linemax;
	unsigned int	cur_col;
	unsigned int	screenrow;
	unsigned int	screencol;
	unsigned int	quote;
	unsigned int	killzone;
	unsigned int	buffer_change;
	int				hcount;
	int				hmax;
	char			**history;
	char			*term;
	char			*return_str;
	char			*clipboard;
	t_buffer		**array;
	int				is_eof;
}					t_edit;

typedef	struct		s_tracker
{
	unsigned int	sgl:1;
	unsigned int	dbl:1;
	unsigned int	bck:1;
}					t_tracker;

typedef struct		s_dispatch_ctrl
{
	long			value;
	void			(*f)(t_edit *edit);
}					t_ctrl;

struct termios		g_original;

/*
** line.c
*/
char				*ft_readline(void);
void				init_terminal_data (t_edit *line);
t_edit				*init_edit();
/*
** term_arrow.c
*/

void				arrow_up(t_edit *edit);
void				arrow_down(t_edit *edit);
void				arrow_left(t_edit *edit);
void				arrow_right(t_edit *edit);
void				arrow_backspace(t_edit *edit);

/*
** display_util.c void clear_screen()
*/
void				align_cursor(t_edit *edit);
void				enable_raw_mode(void);
void				disable_raw_mode(void);
void				print_display(t_edit *edit);
void				display_lines(t_edit *edit);
void				edit_multi_lines(t_edit *edit);
/*
** cursor.c
*/
void				move_cursor_right(t_edit *edit);
void				move_cursor_left(t_edit *edit);
int					term_putc(int c);
void				save_cursor_pos(void);
void				recall_last_cursor_pos(void);
/*
** prompt.c
*/
void				put_prompt_line(unsigned int row);
void				refresh_line_after_prompt(t_edit *edit);
/*
** screen.c
*/
void				get_window_size(t_edit *edit);
/*
** stdin_handler.c
*/
void				print_the_buffer(t_edit *edit);
char				*line_edit_body(t_edit *edit);
/*
** quotes.c
*/
int					quotes_are_closed(char *str);
/*
** newline_handler.c
*/
char				*newline_handler(t_edit *edit);
void				replace_old_array(char **new, char **old);
void				add_to_array(t_edit *edit);
char				*reconstruct_string(t_edit *edit);
int					multi_line_check(t_edit *edit);
void				perror_exit(char *str);
/*
** process_input.c
*/
void				process_input(long num, int len, t_edit *edit);
void				add_to_killzone (int num, t_edit *edit);
void				delete_from_killzone(t_edit *edit);
/*
** cut_paste_line.c
*/
void				cut_to_endline(t_edit *edit);
void				cut_to_prompt(t_edit *edit);
void				paste_clipboard(t_edit *edit);
void				copy_next_word(t_edit *edit);
void				copy_line(t_edit *edit);
/*
** cut_paste_line.c
*/
void				move_cursor_right_by(int col, t_edit *edit);
void				move_cursor_left_by(int col, t_edit *edit);
void				move_cursor_to_prompt(t_edit *edit);
void				move_cursor_to_end(t_edit *edit);
void				move_cursor_to_previous_word(t_edit *edit);
void				move_cursor_to_next_word(t_edit *edit);
void				move_cursor_to_last_word(t_edit *edit);
void				move_cursor_newline(t_edit *edit);

void				move_killzone_up(t_edit *edit);
void				move_killzone_down(t_edit *edit);
/*
** history.c
*/
void				read_file_to_array(t_edit *edit, int fd);
void				import_history(t_edit *edit);
void				update_history(t_edit *edit);
void				history_up(t_edit *edit);
void				history_down(t_edit *edit);
void				free_edit(t_edit *edit);
void				free_edit_array(t_buffer **array);
/*
**	send_eof.c 
*/
void				send_eof(t_edit *edit);
#endif
