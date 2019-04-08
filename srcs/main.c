/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:09:17 by csinglet          #+#    #+#             */
/*   Updated: 2019/02/18 15:09:17 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/42sh.h"

void 	env_init(t_sh	*sh)
{
	extern char	**environ;
	char		**env_split;

	sh->env_dict = dict_init();
	while (environ[sh->env_dict->size])
	{
		env_split = ft_strsplit(environ[sh->env_dict->size], '=');
		// printf("n: %s, v: %s\n", env_split[0], env_split[1]);
		dict_add(sh->env_dict, env_split[0], env_split[1],
			ft_strlen(env_split[1]));
		ft_mstrdel_rows(&env_split, 2);
	}
}

int		main(void)
{
	// char		*line;
	// t_token		*token;
	// t_astnode	*astree;
	t_sh		sh;

	ft_bzero((void *)&sh, sizeof(t_sh));
	env_init(&sh);

// //test
// 	printf("dict path = %s\n", dict_get(sh.env_dict, "PATH"));
// 	printf("dict SHELL = %s\n", dict_get(sh.env_dict, "SHELL"));
// 	printf("dict Apple_Pu = %s\n", dict_get(sh.env_dict, "Apple_Pu"));
// 	printf("dict iter:\n");
// 	t_list *ptr;
// 	ptr = sh.env_dict->iter;
// 	while (ptr)
// 	{
// 		printf("%s => %s\n", ptr->content,
// 			(char *)dict_get(sh.env_dict, (char *)ptr->content));	
// 		ptr = ptr->next;
// 	}
// //end


	// g_power = 1;
	// while (g_power)
	// {
	// 	signals_init();	

	// 	if ((line = ft_readline()) == NULL)			
	// 		exit(0);
	// 	printf("\n");
	// 	token = tokenize(line);

	// 	build_astree(token, &astree);

	// 	// printBinaryTree(astree);

	// 	execute_astree(astree);

	// 	free(line);
	// 	free_token_list(token);
	// 	free_astree(&astree);
	// }
}
