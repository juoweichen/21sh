/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:52:09 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/16 23:52:10 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

static t_trie *get_dir_programs(DIR *dir, t_trie *root, char *dir_path)
{
	struct dirent	*dir_files;
	struct stat filestat;
	char	*path;
	char	*tmp;

	if (root == NULL)
		root = make_trie_node();
	path = ft_strjoin(dir_path, "/");
	tmp = path;
	while ((dir_files = readdir(dir)))
	{
		path = ft_strjoin(tmp, dir_files->d_name);
		if (lstat((const char*)path, &filestat) == -1)
			ft_printf("readlink, %s\n", strerror(errno));
		if (filestat.st_mode & S_IXUSR)
		{
			if (insert_word_trie(root, dir_files->d_name) == 0)
			{
				clean_trie(root);
				return (NULL);
			}
		}
		ft_strdel(&path);
	}
	ft_strdel(&tmp);
	root = make_radix_tree(root);
	return (root);
}

static t_trie *get_path_programs(t_edit *edit)
{
	char			**path;
	t_trie			*root;
	DIR				*dir;

	if (edit->path_programs != NULL)
		return (edit->path_programs);
	path = ft_strsplit((const char*)getenv("PATH"), ':');
	root = NULL;
	while (*path != NULL)
	{
		dir = opendir(*path);
		if (dir != NULL)
			root = get_dir_programs(dir, root, *path);
		path++;
	}
	return (root);
}

void	auto_complete(t_edit *edit)
{
	t_trie	*programs_dictionary;
	//t_trie	*directory_dictionary;
	char	matching[MAX_FILE_LEN];

	programs_dictionary = get_path_programs(edit);
	//directory_dictionary = get_direc_dictionary(edit);
	programs_dictionary = search_radix(programs_dictionary, edit->array[edit->killzone]->line);
	if (programs_dictionary == NULL)
		return ;
	ft_printf("\n");
	print_radix(programs_dictionary,  matching, 0, edit->array[edit->killzone]->line);
}
