/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:55:00 by csinglet          #+#    #+#             */
/*   Updated: 2019/04/26 22:55:05 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

static char		*get_env_var_name(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0' && ft_isalpha(str[i]))
		i++;
	return (ft_strndup(str, i));
}

static char		*expand(char *str, t_sh *sh)
{
	char		*temp;
	char		*name;
	char		*ex;
	int			i;

	temp = str;
	ex = NULL;
	i = -1;
	while (temp[++i] != '\0')
	{
		if (temp[i] != '$')
			continue ;
		ex = (ex == NULL) ? ft_strndup(temp, i) :
							ft_strjoin_free(ex, ft_strndup(temp, i));
		name = get_env_var_name(temp + i + 1);
		if (dict_get(sh->env_dict, name) != NULL)
			ex = ft_strjoin_free_s1(ex, dict_get(sh->env_dict, name));
		temp += i + ft_strlen(name) + 1;
		free(name);
		i = -1;
	}
	if (ex == NULL)
		return (str);
	free(str);
	return (ft_strjoin_free_s1(ex, temp));
}

static void		strip_quotes(char *str)
{
	int			i;

	i = -1;
	while (str[++i] != '\0')
		str[i] = str[i + 1];
	str[i - 2] = '\0';
}

void			expand_enviornment_variables(t_token *token, t_sh *sh)
{
	t_token		*cur;

	cur = token;
	while (cur != NULL)
	{
		if (cur->type != CLOSED_SQUOTE)
			cur->data = expand(cur->data, sh);
		if (cur->type == CLOSED_SQUOTE || cur->type == CLOSED_DQUOTE)
		{
			strip_quotes(cur->data);
			cur->type = STRING_TOKEN;
		}
		cur = cur->next;
	}
}
