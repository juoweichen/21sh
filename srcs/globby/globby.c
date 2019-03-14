/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globby.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:12:19 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/23 20:34:24 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/globby.h"

/*
**	Globbing is wildcard usage. For example cat srcs/lexer/\*.c
*/

int					is_dir(char *dir)
{
	struct stat		s;

	stat(dir, &s);
	return (S_ISDIR(s.st_mode));
}

void				free_double_char_pointer(char **strings)
{
	int				i;

	i = -1;
	while (strings[++i] != NULL)
	{
		free(strings[i]);
		strings[i] = NULL;
	}
	free(strings);
	strings = NULL;
}

int					is_globbable(char *str)
{
	char			*path;
	int				found_glob;
	int				i;

	found_glob = 0;
	i = ft_strlen(str);
	while (--i > 0 && str[i] != '/')
		if (str[i] == '*')
			found_glob = 1;
	if (found_glob == 0)
		return (0);
	path = ft_strndup(str, i + 1);
	if (is_dir(path) == 1)
		return (1);
	ft_printf("path: %s: not found\n");
	return (0);
}

int					end_matches_glob(char *str, char *glob)
{
	int				i;
	int				j;

	i = ft_strlen(glob);
	j = ft_strlen(str);
	while (--i >= 0 && --j >= 0)
	{
		if (glob[i] == '*')
			return (1);
		else if (glob[i] != str[j])
			break ;
	}
	return (0);
}

int					is_glob_match(char *str, char *glob)
{
	char			**globs;
	int				i;

	while (*glob != '*')
		if (*glob++ != *str++)
			return (0);
	if (end_matches_glob(str, glob) == 0)	
		return (0);
	globs = ft_strsplit(glob, '*');
	i = -1;
	while (globs[++i] != NULL)
		if ((str = ft_strstr(str, globs[i])) == NULL)
			break ;
	i = (globs[i] == NULL ? 1 : 0);
	free_double_char_pointer(globs);
	return (i);
}

void				get_glob_matches(t_queue *queue, char *path, char *pattern)
{
	DIR				*d_stream;
	struct dirent	*current_item;

	if ((d_stream = opendir(path)) == NULL)
		return ;
	while ((current_item = readdir(d_stream)) != NULL)
	{
		if (ft_strcmp(current_item->d_name, ".") == 0
			|| ft_strcmp(current_item->d_name, "..") == 0)
			continue ;
		if (is_glob_match(current_item->d_name, pattern) == 1)
			qpush(queue, ft_strdup(current_item->d_name), 0);
	}
	closedir(d_stream);
}

char				*ft_strdup_delim(char *str, int delim)
{
	int				i;

	i = 0;
	while (str[i] != '\0' && str[i] != delim)
		i++;
	return (ft_strndup(str, i));
}

void				the_real_globbing(t_queue *globs, char *path)
{
	t_queue			*files;
	char			*temp;
	char			*temp_path;
	char			*glob_pattern;

	temp = NULL;
	temp_path = ft_strchr(path, '/');
	while (temp_path != NULL)
	{
		glob_pattern = ft_strdup_delim(temp_path + 1, '/');
		temp = ft_strndup(path, temp_path - path + 1);
		if (ft_strchr(glob_pattern, '*') != NULL)
		{
			if (ft_strchr(temp_path + 1, '/') == NULL)
			{
				temp_path = ft_strchr(temp_path + 1, '/');
				get_glob_matches(globs, temp, glob_pattern);
			}
			else
			{
				files = queue_init();
				get_glob_matches(files, temp, glob_pattern);
				temp_path = ft_strchr(temp_path + 1, '/');
				while (qis_empty(files) == 0)
					the_real_globbing(globs, ft_strjoin_free_s1(ft_strjoin_free_s2(temp, qpop(files)), temp_path));
			}
		}
		else
			temp_path = ft_strchr(temp_path + 1, '/');
	}
}
