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

#include "../../includes/astree.h"

int build_astree(t_token *token, t_astnode **astree)
{
    if (token == NULL)
    {
        ft_printf("Empty token error\n");
        return (-1);
    }

    // printf("\n");
    // t_token *ptr;
    // ptr = token;
    // while (ptr)
    // {
    //     printf("%s(%d) -> ", ptr->data, ptr->type);
    //     ptr = ptr->next;
    // }

    //for now the most top node is this
    if ((*astree = complete_command(&token)) == NULL)
        return (-1);
    return (0);
}