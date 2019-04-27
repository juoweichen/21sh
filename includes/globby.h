/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globby.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:13:02 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/21 15:13:03 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBBY_H
# define GLOBBY_H

# include "../libft/includes/libft.h"
# include <sys/stat.h>
# include <dirent.h>

int				is_dir(char *dir);
int				is_globbable(char *str);
void			the_globbing(t_queue *globs, char *path, char *pattern);
void			the_real_globbing(t_queue *globs, char *path);

#endif
