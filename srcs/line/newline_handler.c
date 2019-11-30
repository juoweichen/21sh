/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 02:18:13 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/22 13:28:43 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

char		*newline_handler(t_edit *edit)
{
	edit->killzone = edit->linemax - 1;
	edit->return_str = reconstruct_string(edit);
	while (quotes_are_closed(edit->return_str) != 0)
	{
		edit->killzone++;
		edit->cur_col = 0;
		move_cursor_newline(edit);
		add_to_array(edit);
		line_edit_body(edit);
	}
	update_history(edit);
	return (edit->return_str);
}

void		add_to_array(t_edit *edit)
{
	t_buffer		**new;
	unsigned int	index;

	edit->linemax++;
	new = (t_buffer**)ft_memalloc(sizeof(t_buffer *) * (edit->linemax + 1));
	index = 0;
	while (edit->array[index] != NULL)
	{
		new[index] = (t_buffer*)ft_memalloc(sizeof(t_buffer));
		new[index]->line = ft_strdup(edit->array[index]->line);
		new[index]->buffpos = edit->array[index]->buffpos;
		new[index]->printlen = edit->array[index]->printlen;
		index++;
	}
	new[index - 1]->line = ft_strjoin_free_s1(new[index - 1]->line, "\n");	// add newline to multiple line
	new[index] = (t_buffer*)ft_memalloc(sizeof(t_buffer));
	new[index]->line = ft_strnew(1024);
	new[index]->buffpos = 0;
	new[index]->printlen = 0;
	free_edit_array(edit->array);
	edit->array = new;
}

char		*reconstruct_string(t_edit *edit)
{
	char		*ret;
	char		*tmp;
	t_buffer	**ptr;
	int			i;

	ptr = edit->array;
	ret = ft_strdup(ptr[0]->line);
	i = 0;
	while (ptr[i + 1] != NULL)
	{
		tmp = ret;
		ret = ft_strjoin(tmp, ptr[i + 1]->line);
		free(tmp);
		i++;
	}
	free(edit->return_str);
	edit->return_str = ft_strdup(ret);
	return (ret);
}

