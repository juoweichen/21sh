#include "../../includes/line.h"

void arrow_up(t_edit *edit)
{
    (void)edit;
}
void arrow_down(t_edit *edit)
{
        (void)edit;
}
void arrow_left(t_edit *edit)
{
        unsigned int buf;
        unsigned int printlen;

        buf = edit->array[edit->killzone]->buffpos;
        printlen = edit->array[edit->killzone]->printlen;
        if (buf == 0)
        return; 
        edit->cur_col--;
        edit->array[edit->killzone]->buffpos--;
        ft_putstr(tgetstr("le",NULL));       
}
void arrow_right(t_edit *edit)
{
        unsigned int buf;
        unsigned int printlen;

        buf = edit->array[edit->killzone]->buffpos;
        printlen = edit->array[edit->killzone]->printlen;
        if (buf == printlen)
        return;
        edit->cur_col++;
        edit->array[edit->killzone]->buffpos++;
        ft_putstr(tgetstr("nd",NULL)); 
}

void arrow_backspace(t_edit *edit)
{
        size_t cursor_to_null;
        unsigned int buf;
        unsigned int printlen;
        char *s;

        s = edit->array[edit->killzone]->line;
        buf = edit->array[edit->killzone]->buffpos;
        printlen = edit->array[edit->killzone]->printlen;
        if (buf == 0)
        return;           
        edit->array[edit->killzone]->buffpos--;
        edit->cur_col--;    
        cursor_to_null = ft_strlen(s + buf) + 1;
        ft_memmove(s + buf, s + buf + 1,cursor_to_null);
        ft_putstr((tgetstr("le",NULL)));
        edit->array[edit->killzone]->printlen--;

}
