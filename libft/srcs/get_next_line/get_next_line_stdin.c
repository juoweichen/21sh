/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_stdin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:05:34 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/13 18:16:38 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	save(char **temp, char *buf, int i, int ret)
{
	if (i == ret)
	{
		if (*temp != 0)
			ft_strdel(&*temp);
		return ;
	}
	*temp = ft_strsub(buf, i, ret - i);
}

static int	found_nl(char **line, char **temp, char *buf, int i)
{
	char *temp2;
	char *temp3;

	if (buf[i] != '\n')
		return (-1);
	if (!*line)
		*line = ft_strsub(buf, 0, i);
	else
	{
		temp2 = ft_strsub(buf, 0, i);
		temp3 = *line;
		*line = ft_strjoin(*line, temp2);
		ft_strdel(&temp2);
		ft_strdel(&temp3);
	}
	save(temp, buf, i + 1, ft_strlen(buf));
	return (1);
}

static void	save_and_cont(char **line, char *buf, int ret)
{
	char *temp2;
	char *temp3;

	if (!*line)
		*line = ft_strsub(buf, 0, ret);
	else
	{
		temp3 = *line;
		temp2 = ft_strsub(buf, 0, ret);
		*line = ft_strjoin(*line, temp2);
		ft_strdel(&temp2);
		ft_strdel(&temp3);
	}
}

static int	checktemp(int fd, char **temp, char **line, int ret)
{
	int i;

	i = -1;
	if (ret == 0)
		return (1);
	while (temp[fd][++i] != '\0')
	{
		if (temp[fd][i] == '\n')
		{
			*line = ft_strsub(temp[fd], 0, i);
			save(&temp[fd], temp[fd], i + 1, ft_strlen(temp[fd]));
			return (1);
		}
		if (temp[fd][i + 1] == '\0' && ret == 0)
		{
			*line = ft_strdup(temp[fd]);
			return (1);
		}
	}
	*line = ft_strdup(temp[fd]);
	ft_strdel(&temp[fd]);
	return (0);
}

int			get_next_line_sin(const int fd, char **line)
{
	char			buf[BUFF_SIZE_IN + 1];
	static	char	*temp[255];
	int				i;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	if (temp[fd] != 0)
		if (checktemp(fd, temp, line, 1) == 1)
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE_IN)) > 0)
	{
		i = -1;
		buf[ret] = '\0';
		while (++i < ret)
			if (found_nl(line, &temp[fd], buf, i) == 1)
				return (1);
		save_and_cont(line, buf, ret);
	}
	if (ret < 0)
		return (-1);
	if (checktemp(fd, temp, line, ret) == 1 && ft_strlen(*line) > 0)
		return (1);
	return (0);
}
