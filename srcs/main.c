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

int		main(void)
{
	char		*line;
	t_token		*token;
	t_astnode	*astree;
	t_sh		sh;

	ft_bzero((void *)&sh, sizeof(t_sh));
	env_init(&sh);
	command_init(&sh);

	// t_dlist *t = ft_dlstnew("10", 2);
	// ft_dlstadd(&t, ft_dlstnew("80", 2));
	// ft_dlstadd(&t, ft_dlstnew("30", 2));
	// ft_dlstadd(&t, ft_dlstnew("90", 2));
	// ft_dlstadd(&t, ft_dlstnew("40", 2));
	// ft_dlstadd(&t, ft_dlstnew("50", 2));
	// ft_dlstadd(&t, ft_dlstnew("70", 2));

	// //test
	// t_dlist *ptr = t;
	// while (ptr)
	// {
	// 	printf("%s\n", ptr->content);
	// 	ptr = ptr->next;
	// }
	// // end

	// quick_sort(t);

	// printf("*******************\n");

	// //test
	// ptr = t;
	// while (ptr)
	// {
	// 	printf("%s\n", ptr->content);
	// 	ptr = ptr->next;
	// }
	// // end


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


	g_power = 1;
	while (g_power)
	{
		signals_init();	
		if ((line = ft_readline(&sh)) == NULL)			
			exit(0);
		printf("\n");
		token = tokenize(line);

		build_astree(token, &astree);

		// printBinaryTree(astree);

		execute_astree(astree);	//TODO: Change env built-in

		free(line);
		free_token_list(token);
		free_astree(&astree);
	}
}
