/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:00:26 by juochen           #+#    #+#             */
/*   Updated: 2018/04/17 22:51:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# define HASHSIZE 1001
# define HASHNUMBER 31

typedef	struct		s_dict
{
	char			*key;
	void			*value;
	struct s_dict	*next;
}					t_dict;

/*
**	dict_helper.c
*/
unsigned			dict_hash(char *s);
t_dict				*dict_find(t_dict **dict, char *s);
void				dict_free_elem(t_dict **elem);
/*
**	dict.c
*/
t_dict				**dict_create();
int					dict_add(t_dict **dict, char *key, void *value,
	size_t value_size);
void				*dict_get(t_dict **dict, char *s);
int					dict_remove(t_dict **dict, char *s);
void				dict_destory(t_dict ***dict);

#endif
