#include "../line_incs/line.h"

void get_window_size(t_edit *edit)
{
    edit->screencol = tgetnum("co");
    edit->screenrow = tgetnum("li");
}

void perror_exit(char *str)
{
    ft_printf("%s\n",str);
    exit(1);
}

void put_prompt_line(unsigned int row)
{
    if (row == 0)
        tputs("42sh>",0,term_putc);
    else
        tputs(">>>>>",0,term_putc);
    
}