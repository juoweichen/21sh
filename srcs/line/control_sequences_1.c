#include "../../includes/line.h"

/*
** moves cursor right by num of col
*/
void move_cursor_right_by(int col,t_edit *edit)
{
    int i;

    i = -1;
    while(++i < col)
        move_cursor_right(edit);
    return;        
}

/*
** moves cursor left by num of col
*/
void move_cursor_left_by(int col,t_edit *edit)
{
    int i;

    i = -1;
    while(++i < col)
        move_cursor_left(edit);
    return;        
}

/*
** moves cursor to prompt
*/
void move_cursor_to_prompt(t_edit *edit)
{
    unsigned int buf;

    buf = edit->array[edit->killzone]->buffpos;
    (void)edit;
    tputs(tgoto(tgetstr("ch", NULL), 0, 5), 1, term_putc);
    edit->array[edit->killzone]->buffpos =0;
    edit->cur_col = 0;
}

/*
** moves cursor to end of typed stuff
*/
void move_cursor_to_end(t_edit *edit)
{
    unsigned int len;

    len = edit->array[edit->killzone]->printlen;
    tputs(tgoto(tgetstr("ch", NULL), 0, len+ 5), 1, term_putc);
    edit->array[edit->killzone]->buffpos = len;
}

/*
** moves cursor to next alphanumeric sequence of char;
*/
void move_cursor_to_next_word(t_edit *edit)
{
    char s;
    unsigned int buf;
    char *line;

    buf = edit->array[edit->killzone]->buffpos;
    line = edit->array[edit->killzone]->line;
    s = line[buf + 1];
    while(ft_isalnum(s) && (s != '\0'))
    {

        move_cursor_right_by(1,edit);
        buf = edit->array[edit->killzone]->buffpos;
        line = edit->array[edit->killzone]->line;
        s = line[buf + 1];
    }
    while(!ft_isalnum(s) && (s != '\0'))
    {
        move_cursor_right_by(1,edit);
        buf = edit->array[edit->killzone]->buffpos;
        line = edit->array[edit->killzone]->line;
        s = line[buf + 1];
    }

}

/*
** moves cursor to previous alphanumeric sequence of char;
*/
 void move_cursor_to_previous_word(t_edit *edit)
{
    char s;
    unsigned int buf;
    char *line;

    buf = edit->array[edit->killzone]->buffpos;
    line = edit->array[edit->killzone]->line;
    s = line[buf];
    while(ft_isalnum(s) && (buf!= 0))
    {
        move_cursor_left_by(1,edit);
        buf = edit->array[edit->killzone]->buffpos;
        line = edit->array[edit->killzone]->line;
        s = line[buf];
    }
    while(!ft_isalnum(s) && (buf != 0))
    {
        move_cursor_left_by(1,edit);
        buf = edit->array[edit->killzone]->buffpos;
        line = edit->array[edit->killzone]->line;
        s = line[buf];
    }
}

/*
** moves cursor to last alphanumeric sequence of char;
*/
void move_cursor_to_last_word(t_edit *edit)
{
    move_cursor_to_end(edit);
    move_cursor_to_previous_word(edit); 
}
