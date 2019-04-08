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

#include "ft_lst.h"

#ifndef DICT_H
# define DICT_H

# define HASHSIZE 1001
# define HASHNUMBER 31

typedef struct			s_dict_tab
{
	char				*key;
	void				*value;
	struct s_dict_tab	*next;
}						t_dict_tab;

typedef	struct			s_dict
{
	t_dict_tab			**tb;
	t_list				*iter;
	unsigned int		size;
}						t_dict;

/*
**	dict_helper.c
*/
unsigned				dict_hash(char *s);
t_dict_tab				*dict_find(t_dict *dict, char *s);
void					dict_free_elem(t_dict_tab **elem);
/*
**	dict.c
*/
t_dict					*dict_init(void);
int						dict_add(t_dict *dict, char *key, void *value,
	size_t value_size);
void					*dict_get(t_dict *dict, char *s);
int						dict_remove(t_dict *dict, char *s);
void					dict_destory(t_dict **dict);
/*
**	dict_iter.c
*/
void					dict_iter_add(t_dict *dict, char *key);
void					dict_iter_remove(t_dict *dict, char *key);

#endif
