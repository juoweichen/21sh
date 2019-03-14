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

t_astnode *build_node(t_NodeType type)
{
	t_astnode *new_node;

	new_node = (t_astnode *)ft_memalloc(sizeof(t_astnode));
	new_node->data = NULL;
	new_node->type = type;
	new_node->right = NULL;
	new_node->left = NULL;
	return (new_node);
}

int 	is_number_node(t_token **curtoken)
{
	if (*curtoken == NULL)
		return (-1);
	if ((*curtoken)->type == NUMBER_TOKEN && (*curtoken)->data != NULL)
		return (1);
	return (-1);
}

int		is_right_operator(t_token **curtoken, char *type, char **ops)
{
	if (*curtoken == NULL)
		return (-1);
	if (ft_strcmp((*curtoken)->data, type) == 0)
	{
		*curtoken = (*curtoken)->next;
		*ops = ft_strdup(type);
		return (1);
	}
	return (0);
}

int 	is_word_node(t_token **curtoken)
{
	if (*curtoken == NULL)
		return (-1);
	if (((*curtoken)->type == STRING_TOKEN || (*curtoken)->type == NUMBER_TOKEN)
		&& (*curtoken)->data != NULL)
		return (1);
	return (-1);
}

void travesal_astree_print_command(t_astnode *astree)
{
	if (astree == NULL)
		return ;
	travesal_astree_print_command(astree->left);
	if (astree->data != NULL)
		printf("[%s] ", astree->data);
	travesal_astree_print_command(astree->right);
}

int		is_separator_op(t_token **curtoken, char **op)
{
	if (*curtoken == NULL)
		return (-1);
	if (ft_strcmp((*curtoken)->data, ";") == 0)
	{
		*op = ";";
		*curtoken = (*curtoken)->next;
		return (1);
	}
	else if (ft_strcmp((*curtoken)->data, "&") == 0)
	{
		*op = "&";
		*curtoken = (*curtoken)->next;
		return (1);
	}
	op = NULL;
	return (0);
}

void	del_one_astnode(t_astnode **node)
{
	if (*node == NULL)
		return ;
	if ((*node)->data != NULL)
		ft_strdel(&(*node)->data);
	ft_memdel((void **)node);
}

void	del_astnode(t_astnode **nodes)
{
	if (*nodes == NULL)
		return ;
	del_astnode(&(*nodes)->left);
	del_astnode(&(*nodes)->right);
	del_one_astnode(nodes);
}