/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:53:24 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/22 18:56:16 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

void	free_edit(t_edit *edit)
{
	int		i;

	i = 0;
	free_edit_array(edit->array);
	free(edit->clipboard);
	while (i < HISTORY_BUFFER)
	{
		free(edit->history[i]);
		i++;
	}
	free(edit->history);
}

void	free_edit_array(t_buffer **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]->line);
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}
