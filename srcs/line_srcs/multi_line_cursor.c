#include "../line_incs/line.h"

static void up_update_edit(t_edit *edit)
{
    unsigned int top_len;
    unsigned int bot_len;
    unsigned int top_bufp;
    unsigned int bot_bufp;

    top_len = edit->array[edit->killzone]->printlen;
    bot_len = edit->array[edit->killzone+ 1]->printlen;
    top_bufp =edit->array[edit->killzone]->buffpos;
    bot_bufp = edit->array[edit->killzone + 1]->buffpos;
    if (top_len < bot_bufp)
    {
        edit->array[edit->killzone]->buffpos = edit->array[edit->killzone]->printlen;
        edit->cur_col = edit->array[edit->killzone]->printlen;
    }
    else
    {
        edit->array[edit->killzone]->buffpos = edit->array[edit->killzone + 1]->buffpos;
        edit->cur_col = edit->array[edit->killzone + 1]->buffpos;
    }
}

static void down_update_edit(t_edit *edit)
{
    unsigned int top_len;
    unsigned int bot_len;
    unsigned int top_bufp;
    unsigned int bot_bufp;

    top_len = edit->array[edit->killzone -1]->printlen;
    bot_len = edit->array[edit->killzone]->printlen;
    top_bufp =edit->array[edit->killzone - 1]->buffpos;
    bot_bufp = edit->array[edit->killzone]->buffpos;
    if (bot_len < top_bufp)
    {
        edit->array[edit->killzone]->buffpos = edit->array[edit->killzone]->printlen ;
        edit->cur_col = edit->array[edit->killzone]->printlen;
    }
    else
    {
        edit->array[edit->killzone]->buffpos = edit->array[edit->killzone -1]->buffpos;
        edit->cur_col = edit->array[edit->killzone]->buffpos;

    }
}

void move_killzone_up(t_edit *edit)
{
    if(edit->killzone == 0)
    {
        return ;
    }
    edit->killzone--;
    up_update_edit(edit);
    return;
}

void move_killzone_down(t_edit *edit)
{
    if(edit->killzone == (edit->linemax - 1))
    {
        return ;
    }
        
    edit->killzone++;
    down_update_edit(edit);
    
    return;
}