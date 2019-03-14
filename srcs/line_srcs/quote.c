#include "../line_incs/line.h"


int is_sglq(char c)
{
    if (c == '\'')
        return 1;
    return 0;
}
int is_dblq(char c)
{
    if (c == '\"')
        return 1;
    return 0;
}
int is_bckq(char c)
{
    if (c == '`')
        return 1;
    return 0;
}

int move_to_close(char *str ,int *index, char quote)
{
    int i;

    i = *index + 1;
    while (str[i] != quote && str[i] != '\0')
        i++;
    *index = i;
    if (str[i] == '\0')
        return 1;
    else
        return 0;
}



int quotes_are_closed(char *str)
{
    char *s;
    int i;
    t_tracker quote;

    quote.dbl =0;
    quote.sgl =0;
    quote.bck =0;
    i = 0;
    s = str;
    while(s[i] != '\0')
    {
        if(is_sglq(s[i]))
        {
            quote.sgl ^= 1;
           if( move_to_close(s,&(i), '\'') == 0)
            quote.sgl ^= 1;
        }  
        else if(is_dblq(s[i]))
        {
            quote.dbl ^= 1;
           if( move_to_close(s,&i, '\"') == 0)
            quote.dbl ^= 1;
        }  
        else if(is_bckq(s[i]))
        {
            quote.bck ^= 1;
           if( move_to_close(s,&i, '`') == 0)
            quote.bck ^= 1;
        }
        if(s[i] != '\0')
            i++;
    }
    if (s[i - 1] == '\\')
        return (5);
    if (quote.sgl == 1)
        return 1;
    else if (quote.dbl == 1)
        return 2;
    else if (quote.bck == 1)
        return 3; 
    return 0;
}