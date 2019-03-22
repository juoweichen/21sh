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

void handle_redirect(t_exec_sc *exec_sc)
{
	int fd;
	
	//redirect stdout to file if specified
	if (ft_strequ(exec_sc->redirect_op, ">") == 1)
	{
		if ((fd = open(exec_sc->redirect_filename, O_WRONLY | O_CREAT | O_APPEND,
						S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		{
			perror("redirect_out");
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
	}
	//redirect stdin from file if specified
	else if (ft_strequ(exec_sc->redirect_op, "<") == 1)
	{
		if ((fd = open(exec_sc->redirect_filename, O_RDONLY)) == -1)
		{
			perror("redirect_in");
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
	}
	//redirect stdout to file if specified, overwrite
	else if (ft_strequ(exec_sc->redirect_op, ">>") == 1)
	{
		if ((fd = open(exec_sc->redirect_filename, O_WRONLY | O_CREAT | O_TRUNC,
						S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		{
			perror("overwrite redirect_out");
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
	}
}

void run(t_exec *exec, t_exec_sc *exec_sc)
{
	pid_t pid;
	int stdoutfd = dup(STDOUT_FILENO);

	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		//child process
		if (exec_sc->redirect_op != NULL)
			handle_redirect(exec_sc);

		//read stdin from pipe if present
		if (exec_sc->piperead != -1)
			dup2(exec_sc->piperead, STDIN_FILENO);

		//write stdout to pipe if present
		if (exec_sc->pipewrite != -1)
			dup2(exec_sc->pipewrite, STDOUT_FILENO);

		//in order to let built-in function got pipel
		if (check_built_in(exec, exec_sc) == 1)
			exit(0) ;

		if (ft_execvp(exec_sc->argv[0], exec_sc->argv) < 0)
		{
			// restore the stdout for displaying error message
            dup2(stdoutfd, STDOUT_FILENO);
			
			printf("Command not found: \'%s\'\n", exec_sc->argv[0]);
			exit(1);
		}
		exit(0);
	}
	else
	{
		//parent process
		wait(NULL);
	}
}

void init_run(t_astnode *astree, t_exec_sc *exec_sc, int piperead, int pipewrite)
{
	t_astnode *astptr;
	int i;

	if (astree->type == NODE_SIMPLE_COMMAND)
	{
		//count argc
		astptr = astree;
		while (astptr)
		{
			if (astptr->type == NODE_IO_FILE)
			{
				exec_sc->redirect_op = ft_strdup(astptr->data);
				exec_sc->redirect_filename = ft_strdup(astptr->right->data);
				break ;
			}
			exec_sc->argc += 1;
			astptr = astptr->right;
		}
		exec_sc->argv = (char **)ft_memalloc(exec_sc->argc * sizeof(char *) + 1);
		//store to argv
		astptr = astree;
		i = 0;
		while (i < exec_sc->argc)
		{
			if (astptr->left != NULL)
				exec_sc->argv[i] = ft_strdup(astptr->left->data);
			else
				exec_sc->argv[i] = ft_strdup(astptr->data);
			astptr = astptr->right;
			i++;
		}
		exec_sc->argv[i] = NULL;
	}
	else
	{
		//only cmd_name
		exec_sc->argc = 1;
		exec_sc->argv = (char **)ft_memalloc(exec_sc->argc * sizeof(char *) + 1);
		exec_sc->argv[0] = ft_strdup(astree->data);
		exec_sc->argv[1] = NULL;
	}

	// store attributes
	exec_sc->piperead = piperead;
	exec_sc->pipewrite = pipewrite;
}

void execute_simple_command(t_astnode *astree, t_exec *exec, int piperead, int pipewrite)
{
	t_exec_sc exec_sc;

	if (astree == NULL)
		return ;
	ft_bzero(&exec_sc, sizeof(t_exec_sc));
	
	init_run(astree, &exec_sc, piperead, pipewrite);
	run(exec, &exec_sc);

	ft_mstrdel_rows(&exec_sc.argv, exec_sc.argc);
	ft_strdel(&exec_sc.redirect_op);
	ft_strdel(&exec_sc.redirect_filename);
}