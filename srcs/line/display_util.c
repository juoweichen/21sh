#include "../../includes/line.h"

void enable_raw_mode()
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);
    g_original = raw;
    raw.c_lflag &= ~(ECHO| ICANON);
    raw.c_cc[VMIN] = 1;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disable_raw_mode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_original);
}

void  align_cursor(t_edit *edit)
{
    unsigned int max = edit->linemax - 1;
    unsigned int row = edit->killzone;
    unsigned int col = edit->array[edit->killzone]->buffpos;
    unsigned int len = edit->array[edit->killzone]->printlen;
    while (row < max)
    {
        ft_putstr(tgetstr("up",NULL));
        row++;
    }
    while(col < len--)
    {
        ft_putstr(tgetstr("le",NULL));
    }
        
}





void print_display(t_edit *edit)
{
    int row;
    int col;
    
    row = edit->linemax ;
    col = edit->cur_col;
    ft_putstr(tgetstr("cr",NULL));
    while(--row >0)
    {
        ft_putstr(tgetstr("up",NULL));
    }
        
    ft_putstr(tgetstr("cd",NULL));
    row = 0;
    while (row < ((int)edit->linemax))
    {
          
        ft_putstr(tgetstr("cd",NULL));
        put_prompt_line(row);
        edit->cur_col =edit->array[edit->killzone]->buffpos;
        tputs(edit->array[row]->line,0,term_putc);
        row++;
        if (edit->linemax != 1 && row != (int)edit->linemax)
            move_cursor_newline(edit);
    }
    if (edit->killzone != (edit->linemax - 1))
       align_cursor(edit);
    
}