/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:59:06 by juochen           #+#    #+#             */
/*   Updated: 2018/04/05 18:11:16 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_fd			*new_file(int fd)
{
	t_fd	*tmp;

	tmp = (t_fd *)ft_memalloc(sizeof(t_fd));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->content = ft_memalloc(1);
	if (!tmp->content)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

/*
**	Check fd list if currrent fd is exist in list or not
**	if exist, return pointer to the certain node
**	if not exist or there's no list, create new node
*/

static	t_fd	*get_fd(t_fd **begin_file, int fd)
{
	t_fd *tmp;
	t_fd *pre;

	tmp = *begin_file;
	pre = NULL;
	if (!tmp)
	{
		tmp = new_file(fd);
		*begin_file = tmp;
		return (tmp);
	}
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		pre = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		tmp = new_file(fd);
		pre->next = tmp;
	}
	return (tmp);
}

/*
**	keep reading till the new line has meet
*/

static	int		read_content(int fd, char *buff, char **content)
{
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (*content)
		{
			tmp = *content;
			*content = ft_strjoin(tmp, buff);
			free(tmp);
			tmp = NULL;
		}
		else
			*content = ft_strdup(buff);
		if (ft_strchr(*content, '\n'))
			break ;
	}
	return (ret);
}

/*
**	content include string before \n and string after
**	copy string before \n to line
**	tuncate the content after \n
*/

void			set_line(char **content, char **line)
{
	int		nllen;
	char	*tmp;
	int		i;

	nllen = 0;
	while ((*content)[nllen] && (*content)[nllen] != '\n')
		nllen++;
	*line = ft_strnew(nllen);
	ft_strncpy(*line, *content, nllen);
	tmp = ft_strdup(*content);
	i = 0;
	nllen++;
	while (tmp[nllen])
		(*content)[i++] = tmp[nllen++];
	(*content)[i] = '\0';
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*files;
	t_fd			*cur;
	char			buff[BUFF_SIZE + 1];

	if ((fd < 0 || line == NULL || read(fd, buff, 0) < 0))
		return (-1);
	cur = get_fd(&files, fd);
	if (read_content(fd, buff, &(cur->content)) < BUFF_SIZE &&
		!ft_strlen(cur->content))
		return (0);
	set_line(&(cur->content), line);
	return (1);
}
