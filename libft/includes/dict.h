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

# include "ft_lst.h"

# define HASHSIZE 1001
# define HASHNUMBER 31

typedef struct			s_dict_tab
{
	char				*key;
	void				*value;
	struct s_dict_tab	*next;
}						t_dict_tab;

/*
**	How to use iter:
**	1. iter is a list store key base on store sequence
**	2. iter will be update when dict_add or dict_remove success
**	3. when you want to iter this dict,
**		set a t_list pointer then assign it to iter,
**		loop it and use dict_get to find corresponding value
**	NOTE: check out env_builtin or hash_builtin for example
*/
typedef	struct			s_dict
{
	t_dict_tab			**tb;
	t_list				*iter;
	unsigned int		size;
}						t_dict;

/*
**	dict.c			PLEASE USE THOSE FUNCTIONS!
**	dict_init: Create a empty dict
**	dict_add: add new element or update if already exist
**	dict_get: search key then return value, return NULL if not found
**	dict_remove: remove value, return 1 if remove success, 0 if not
**	dict_destory: remove all dict
*/
t_dict					*dict_init(void);
int						dict_add(t_dict *dict, char *key, void *value,
	size_t value_size);
void					*dict_get(t_dict *dict, char *key);
int						dict_remove(t_dict *dict, char *key);
void					dict_destory(t_dict **dict);
/*
**	dict_iter.c		DON'T USE THOSE FUNCTIONS!
*/
void					dict_iter_add(t_dict *dict, char *key);
void					dict_iter_remove(t_dict *dict, char *key);
/*
**	dict_helper.c	DON'T USE THOSE FUNCTIONS!
*/
unsigned				dict_hash(char *s);
t_dict_tab				*dict_find(t_dict *dict, char *s);
void					dict_free_elem(t_dict_tab **elem);

#endif
