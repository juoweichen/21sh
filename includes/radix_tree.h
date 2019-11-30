/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:40:17 by mcouto            #+#    #+#             */
/*   Updated: 2019/11/20 16:40:18 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_TREE_H
#define RADIX_TREE_H

# include "line.h"
# include "prefix_tree.h"

int		rdx_isredundant(t_trie *node);
void	print_radix(t_trie *root, char *matching, int level, char *match);
t_trie	*rdx_redundant_chain(t_trie *node);
t_trie	*rdx_compress_nodes(t_trie *node, t_trie *chain);
t_trie	*make_radix_tree(t_trie *root);
t_trie	*search_radix(t_trie *root, char *key);

#endif
