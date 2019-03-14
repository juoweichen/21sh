#include "../../includes/line.h"

char *ft_readline(void)
{
    t_edit *edit;
    char *ret;

    edit = init_edit();
    init_terminal_data(edit);
    enable_raw_mode();
    ret = line_edit_body(edit);
    disable_raw_mode();
    free(edit); //need to free the string inside as well.!!!
    return ret;
}

t_edit *init_edit()
{
    t_edit *new;

    new = malloc(sizeof(t_edit));
    new->array = (t_buffer**)malloc((sizeof(t_buffer*)) * 2);
    new->array[0] = malloc(sizeof(t_buffer));
    new->cur_col = 0;
    new->linemax = 1;
    new->quote = 0;
    new->term = NULL;
    new->return_str = ft_strnew(1);
    new->clipboard = ft_strnew(1);
    new->killzone = 0;
    new->array[0]->line = ft_strnew(1024);
    new->array[0]->printlen = 0;
    new->array[0]->buffpos = 0;
    new->array[1]= NULL;

    return (new);
}

void init_terminal_data (t_edit *line)
{
    char *term;
    int work;

    if (!(term = getenv("TERM")))
        perror_exit("Environment variable term does not exist\n");
    work = tgetent(term,line->term);
    if (work == 0)
        perror_exit("Terminal pointed to by $(TERM) is shit\n");
    else if (work == -1)
        perror_exit("Term database is fucked\n");
    get_window_size(line);
    tputs(tgetstr("ce",NULL),0,term_putc);
    print_display(line);
    save_cursor_pos();
    return;
}

char *line_edit_body(t_edit *edit)
{
    long num = 0;
    int len;

    while(1)
    {
        num = 0;
        print_display(edit);
        len = read(STDIN_FILENO, &num, 6);
        process_input(num, len, edit);
        if ((int)num == '\n')
            return(newline_handler(edit));
        save_cursor_pos();
        print_display(edit);
       // recall_last_cursor_pos();
    }
}
