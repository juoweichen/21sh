#include "../../includes/line.h"


/*
** movement of  cursor;
*/

void save_cursor_pos()
{
    ft_putstr(tgetstr("sc",NULL));

}

void recall_last_cursor_pos()
{
    ft_putstr(tgetstr("rc",NULL));
}


void move_cursor_right(t_edit *edit)
{
    unsigned int buf;
    unsigned int printlen;

    buf = edit->array[edit->killzone]->buffpos;
    printlen = edit->array[edit->killzone]->printlen;
    if(buf == printlen)
        return;
    ft_putstr(tgetstr("nd",NULL));
    edit->cur_col++;
    edit->array[edit->killzone]->buffpos++;
    save_cursor_pos();
}

void move_cursor_left(t_edit *edit)
{
    unsigned int buf;

    buf = edit->array[edit->killzone]->buffpos;
    if(buf <= 0)
    {
        edit->array[edit->killzone]->buffpos = 0;
        edit->cur_col=0;
        move_cursor_to_prompt(edit);
        return;
    }
    ft_putstr(tgetstr("le",NULL));
    edit->cur_col--;
    edit->array[edit->killzone]->buffpos--;
}

void move_cursor_newline(t_edit *edit)
{
    tputs(tgetstr("do",NULL),0, term_putc);
    tputs(tgetstr("cr",NULL),0, term_putc);
    edit->cur_col = 0;
}

void move_cursor_lmargin(t_edit *edit)
{
    tputs(tgetstr("ce",NULL),0, term_putc);
    edit->cur_col = 0;
}

int term_putc(int c)
{
    write(1,&c,1);
    return 0;
}