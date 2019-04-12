/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 02:04:52 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/22 20:39:02 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

/*
** auto_complete (TAB)
*/
void	auto_complete(t_edit *edit)
{
	// edit->is_eof = 0;
	newline_handler(edit);
	// ftprintf("%s\n", edit->return_str);

	size_t	curpathlen = 0;
	char	*curpath;
	char 	*left;
	size_t	leftlen;
	DIR		*dirptr;
	struct	dirent	*entry;

	if (ft_strchr(edit->return_str, '/') != NULL)
	{
		left = ft_strrchr(edit->return_str, '/');
		leftlen = ft_strlen(left);
		printf("left: %s\n", left);
		curpathlen = left - edit->return_str;
		printf("curpathlen: %zu\n", curpathlen);
		curpath = ft_strsub(edit->return_str, 0, curpathlen);
		printf("curpath: %s\n", curpath);

		if ((dirptr = opendir(curpath)) == NULL)
			return ;
		while ((entry = readdir(dirptr)))
		{
			if (!ft_strncmp(entry->d_name, left + 1, leftlen - 1))
			{
				//should delete left
				//print full file name
			}
		}
		closedir(dirptr);
		ft_strdel(&curpath);
	}
	else
	{
		printf("command\n");
	}
	

	//if input a command (if not adding any prefix, treat as command)
		//search command form env
			//search function

	//if input a dir
		//search from dir
			//search function



	//***Search function****
	//if only one result
			//print line
	//else 
		//show options
		//wait for user input
			//if input another tab
				//round to next option
			//else if input char 
				//add to line
}