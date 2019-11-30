/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:12:23 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/18 13:12:24 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREFIX_TREE_H
# define PREFIX_TREE_H

# define ALPHABET 80
# define MAX_CHAIN 255
# define MAX_FILE_LEN 255
# define START_ALPHA '+'
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct	s_trie
{
	struct		s_trie* alphabet[ALPHABET];
	int		    eow;
	int			chain[MAX_CHAIN];
}				t_trie;

t_trie			*make_trie_node();
t_trie			*prefix_tree(char **dictionary);
t_trie			*search_trie(t_trie *root, char *key);
int				insert_word_trie(t_trie *root, char *word);
void    		print_trie(t_trie *root, char *matching, int level, char *match);
void			clean_trie(t_trie *trie);
char			**low_case(char **dictionary);
int				count_trie_children(t_trie *root);
int				is_trie_leaf(t_trie *node);

#endif
