/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:39:46 by juochen           #+#    #+#             */
/*   Updated: 2018/04/19 21:24:35 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 320
# define BUFF_SIZE_IN 1

typedef struct		s_fd
{
	char			*content;
	int				fd;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);
int					get_next_line_sin(const int fd, char **line);
int					ft_skipline(int fd);

#endif
