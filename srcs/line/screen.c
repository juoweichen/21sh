/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:48:00 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/20 01:49:46 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

void	get_window_size(t_edit *edit)
{
	edit->screencol = tgetnum("co");
	edit->screenrow = tgetnum("li");
}

void	perror_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	put_prompt_line(unsigned int row)
{
	if (row == 0)
		tputs(PROMPT, 0, term_putc);
	else
		tputs(QUOTE_PROMPT, 0, term_putc);
}
