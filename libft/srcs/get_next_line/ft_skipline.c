/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:31:14 by juochen           #+#    #+#             */
/*   Updated: 2018/02/25 15:03:06 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_skipline(int fd)
{
	char	*line;

	if (!get_next_line(fd, &line))
		return (0);
	ft_strdel(&line);
	return (1);
}
