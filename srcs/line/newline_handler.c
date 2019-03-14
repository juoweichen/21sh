#include "../../includes/line.h"

char *newline_handler(t_edit *edit)
{
    edit->killzone = edit->linemax - 1;
    while(multi_line_check(edit) != 0)
    {
        add_to_array(edit);
        edit->killzone++;
        move_cursor_newline(edit);
        put_prompt_line(2);
        save_cursor_pos();
        line_edit_body(edit);
    }
    return (edit->return_str);
}

void add_to_array(t_edit *edit)
{
    t_buffer **new;
    unsigned int index ;

    index = 0;
    edit->linemax++;
    new= (t_buffer**)malloc(sizeof(t_buffer *) * (edit->linemax +1));
    while(index < edit->linemax)
    new[index++]= (t_buffer*)malloc(sizeof(t_buffer));
    new[index] = NULL;
    index = 0;
    while ((new[index] != NULL )&& (edit->array[index] != NULL))
    {
            new[index]->line = ft_strdup(edit->array[index]->line);
            new[index]->buffpos = edit->array[index]->buffpos;
            new[index]->printlen = edit->array[index]->printlen;
            free(edit->array[index]);
            index++;
    }
    new[index]->line = ft_strnew(1024);
    new[index]->buffpos = 0;
    new[index]->printlen = 0;
    free(edit->array);
    edit->array= new;
    return;
}

char *reconstruct_string(t_edit *edit)
{
    char *ret;
    char *tmp;
    t_buffer **ptr;
    int i;

    ptr = edit->array;
    ret = ft_strdup(ptr[0]->line);
    i =0;
    while(ptr[i + 1]  != NULL)
    {
        tmp = ret;
        ret = ft_strjoin(tmp, ptr[i + 1]->line);
        free(tmp);
        i++;
    }
    free(edit->return_str);
    edit->return_str = ft_strdup(ret);

    return(ret);
}

int multi_line_check(t_edit *edit)
{
    char *tmp;
    
    tmp = reconstruct_string(edit);
    edit->quote= quotes_are_closed(tmp);
    
    free(tmp);
    if (edit->quote == 0)
        return (0);
    return(edit->quote);
}
