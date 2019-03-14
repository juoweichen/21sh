/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:38:03 by csinglet          #+#    #+#             */
/*   Updated: 2019/03/09 19:38:04 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void			remove_quotes(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i - 2] = '\0';
}

#include <stdio.h>

int				main(int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("Before: %s\n", argv[1]);
		remove_quotes(argv[1]);
		printf("After: %s\n", argv[1]);
	}
	return (0);
}
