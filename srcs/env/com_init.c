/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:03:48 by kblack            #+#    #+#             */
/*   Updated: 2019/04/26 18:03:53 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void				free_com_dlist(t_dlist **com_dlist)
{
	t_dlist			*next;

	while (*com_dlist)
	{
		next = (*com_dlist)->next;
		ft_strdel(&((t_com *)((*com_dlist)->content))->name);
		ft_strdel(&((t_com *)((*com_dlist)->content))->path);
		free((t_com *)((*com_dlist)->content));
		ft_memdel((void **)com_dlist);
		(*com_dlist) = next;
	}
}

void				store_to_com_dlist(char *path,
	char *name, t_dlist **com_dlist)
{
	t_com			new_com;

	ft_bzero(&new_com, sizeof(t_com));
	new_com.name = ft_strdup(name);
	new_com.path = ft_strjoin_btw(path, name, '/');
	if (*com_dlist == NULL)
		*com_dlist = ft_dlstnew(&new_com, sizeof(t_com));
	else
		ft_dlstadd(com_dlist, ft_dlstnew(&new_com, sizeof(t_com)));
}

t_dlist				*get_com_dlist(char **path_split)
{
	int				i;
	DIR				*dirptr;
	struct dirent	*entry;
	t_dlist			*com_dlist;

	com_dlist = NULL;
	i = -1;
	while (path_split[++i])
	{
		if ((dirptr = opendir(path_split[i])) == NULL)
			continue ;
		while ((entry = readdir(dirptr)) != NULL)
		{
			if (ft_strequ(entry->d_name, "..") == 1 ||
				ft_strequ(entry->d_name, ".") == 1)
				continue ;
			store_to_com_dlist(path_split[i], entry->d_name, &com_dlist);
		}
		closedir(dirptr);
	}
	return (com_dlist);
}

/*
**	Directs a command to be stored to a list, sorted,
**	stored to com_dist, or freed
*/

void				command_init(t_sh *sh)
{
	char			**path_split;
	t_dlist			*com_dlist;
	t_dlist			*ptr;

	path_split = ft_strsplit(dict_get(sh->env_dict, "PATH"), ':');
	com_dlist = get_com_dlist(path_split);
	ft_mstrdel_norows(&path_split);
	quick_sort_str_dlist(com_dlist);
	sh->com_dict = dict_init();
	ptr = com_dlist;
	while (ptr)
	{
		dict_add(sh->com_dict,
			((t_com *)ptr->content)->name,
			((t_com *)ptr->content)->path,
			ft_strlen(((t_com *)ptr->content)->path));
		ptr = ptr->next;
	}
	free_com_dlist(&com_dlist);
}
