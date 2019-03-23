/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_paste_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:22:22 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/20 01:30:57 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

/*
** Cut forwards to the end of the line(Ctrl - k)
*/

void	cut_to_endline(t_edit *edit)
{
	int				len;
	char			*s;
	unsigned int	buf;

	s = edit->array[edit->killzone]->line;
	buf = edit->array[edit->killzone]->buffpos;
	free(edit->clipboard);
	edit->clipboard = ft_strdup(s + buf);
	len = ft_strlen(edit->clipboard);
	ft_bzero(s + buf + 1, len);
	edit->array[edit->killzone]->printlen -= len;
}

/*
** Cut backwards to the start of the line (Ctrl - u)
*/

void	cut_to_prompt(t_edit *edit)
{
	int					uncut_len;
	int					cut_len;
	char				*s;
	unsigned int		buf;

	s = edit->array[edit->killzone]->line;
	buf = edit->array[edit->killzone]->buffpos;
	free(edit->clipboard);
	edit->clipboard = ft_strnew(4096);
	ft_strncpy(edit->clipboard, s, buf);
	cut_len = ft_strlen(edit->clipboard);
	uncut_len = ft_strlen(s) - cut_len;
	edit->array[edit->killzone]->printlen = uncut_len;
	ft_memmove(s, s + cut_len, uncut_len);
	ft_bzero(s + uncut_len, 4096 - uncut_len);
	edit->array[edit->killzone]->buffpos = 0;
	edit->cur_col = 0;
	move_cursor_to_prompt(edit);
}

/*
** paste(Ctrl - y)
*/

void	paste_clipboard(t_edit *edit)
{
	char			*s;
	unsigned int	buf;

	s = edit->array[edit->killzone]->line;
	buf = edit->array[edit->killzone]->buffpos;
	ft_memmove(s + buf + ft_strlen(edit->clipboard), s + buf, ft_strlen(s));
	ft_memmove(s + buf, edit->clipboard, ft_strlen(edit->clipboard));
	edit->array[edit->killzone]->printlen = ft_strlen(s);
}

/*
** Copy the next word ignoring any whitespace(Ctrl - G)
*/

void	copy_next_word(t_edit *edit)
{
	int					i;
	char				*cur;
	char				*s;
	unsigned int		buf;

	i = 0;
	s = edit->array[edit->killzone]->line;
	buf = edit->array[edit->killzone]->buffpos;
	cur = s + buf + 1;
	while (ft_isspace(cur[i]) && cur[i] != '\0')
		i++;
	if (cur[i] == '\0')
		return ;
	cur += i;
	i = 0;
	while (!ft_isspace(cur[i]) && cur[i] != '\0')
		i++;
	free(edit->clipboard);
	edit->clipboard = ft_strdup(cur);
	return ;
}

/*
** Copy the whole line(Ctrl - I)
*/

void	copy_line(t_edit *edit)
{
	free(edit->clipboard);
	edit->clipboard = ft_strdup(edit->array[edit->killzone]->line);
}
