# include <errno.h>

#ifndef DIRENT_H
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#endif

#ifndef LINE_H
# include "../../includes/line.h"
#endif

void	read_file_to_array(t_edit *edit, int fd)
{
	int		i;
	int		ret;

	i = 0;
	while ((ret = get_next_line(fd, edit->history + i)) == 1 &&
		i < HISTORY_BUFFER - 1)
		i++;
	edit->hcount = i;
	edit->hmax = i + 1;
	if (ret == -1)
		ft_printf("GNL ret -1: %s\n", strerror(errno));
}

void	import_history(t_edit *edit)
{
	int fd;

	if (edit->history_path == NULL)
		edit->history_path = ft_strjoin(dict_get(edit->env_dict, "HOME"), "/.21_history");
	fd = open(edit->history_path, O_RDWR | O_CREAT |  O_APPEND, S_IRWXU);
	if (fd == -1)
		ft_printf("open history failed: %s\n", strerror(errno));
	edit->history = (char **)ft_memalloc((sizeof(char *) * HISTORY_BUFFER));
	read_file_to_array(edit, fd);
	close(fd);
	return ;
}

void	update_history(t_edit *edit)
{
	int		fd;

	fd = open(edit->history_path, O_RDWR | O_APPEND, S_IRWXU);
	write(fd, edit->return_str, ft_strlen(edit->return_str));
	write(fd, "\n", 1);
	close(fd);
	return ;
}

void	history_up(t_edit *edit)
{
	char *str;

	if (edit->hcount <= 0)
		return ;
	str = edit->array[edit->killzone]->line;
	ft_bzero(str, 1024);
	str = ft_strcpy(str, edit->history[edit->hcount]);
	edit->array[edit->killzone]->buffpos = ft_strlen(str);
	edit->array[edit->killzone]->printlen = ft_strlen(str);
	edit->cur_col = ft_strlen(str);
	edit->hcount--;
}

void	history_down(t_edit *edit)
{
	char *str;

	if (edit->hcount >= edit->hmax - 1)
		return ;
	str = edit->array[edit->killzone]->line;
	ft_bzero(str, 1024);
	str = ft_strcpy(str, edit->history[edit->hcount]);
	edit->array[edit->killzone]->buffpos = ft_strlen(str);
	edit->array[edit->killzone]->printlen = ft_strlen(str);
	edit->cur_col = ft_strlen(str);
	edit->hcount++;
}
