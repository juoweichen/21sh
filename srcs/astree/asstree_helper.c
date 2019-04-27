/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:23:44 by juochen           #+#    #+#             */
/*   Updated: 2019/02/09 13:23:46 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"
#include "../../includes/astree.h"

t_astnode	*build_node(t_node_type type)
{
	t_astnode *new_node;

	new_node = (t_astnode *)ft_memalloc(sizeof(t_astnode));
	new_node->data = NULL;
	new_node->type = type;
	new_node->right = NULL;
	new_node->left = NULL;
	return (new_node);
}

void		travesal_astree_print_command(t_astnode *astree)
{
	if (astree == NULL)
		return ;
	travesal_astree_print_command(astree->left);
	if (astree->data != NULL)
		printf("[%s] ", astree->data);
	travesal_astree_print_command(astree->right);
}

void		free_astnode(t_astnode **node)
{
	if (*node == NULL)
		return ;
	ft_strdel(&(*node)->data);
	ft_memdel((void **)node);
}

void		free_astree(t_astnode **nodes)
{
	if (*nodes == NULL)
		return ;
	free_astree(&(*nodes)->left);
	free_astree(&(*nodes)->right);
	free_astnode(nodes);
}
