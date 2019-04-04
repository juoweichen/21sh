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
#include "../../includes/exec.h"

void redirect_lessand(t_exec_sc *exec_sc)
{
	if (exec_sc->redirect_src == NULL)
		dup2(STDIN_FILENO, ft_atoi(exec_sc->redirect_des));
	else if (ft_strequ(exec_sc->redirect_des, "-") == 1)
		close(ft_atoi(exec_sc->redirect_src));
	else
		dup2(ft_atoi(exec_sc->redirect_des), ft_atoi(exec_sc->redirect_src));
}

void redirect_greatand(t_exec_sc *exec_sc)
{
	if (exec_sc->redirect_src == NULL)
		dup2(STDOUT_FILENO, ft_atoi(exec_sc->redirect_des));
	else if (ft_strequ(exec_sc->redirect_des, "-") == 1)
		close(ft_atoi(exec_sc->redirect_src));
	else
		dup2(ft_atoi(exec_sc->redirect_des), ft_atoi(exec_sc->redirect_src));
}

//redirect stdout to file if specified, apppend
void redirect_dgreat(t_exec_sc *exec_sc)
{
	int fd;

	if ((fd = open(exec_sc->redirect_des, O_WRONLY | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	{
		perror("redirect_out");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
}

//redirect stdin from file if specified
void redirect_less(t_exec_sc *exec_sc)
{
	int fd;

	if ((fd = open(exec_sc->redirect_des, O_RDONLY)) == -1)
	{
		perror("redirect_in");
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
}

//redirect stdout to file if specified
void redirect_great(t_exec_sc *exec_sc)
{
	int fd;

	if ((fd = open(exec_sc->redirect_des, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	{
		perror("overwrite redirect_out");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
}
