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

#ifndef EXEC_H
# define EXEC_H

# include "../libft/includes/libft.h"
# include "astree.h"
# include <dirent.h>
# include "../includes/env.h"

int g_power;

typedef	struct	s_env
{
	char		*name;
	char		*value;
}				t_env;

typedef struct	s_exec
{
	t_dict		*env_dict;
	t_dict		*com_dict;
	t_dict		*iv_dict;
}				t_exec;

typedef struct	s_exec_simple_command
{
	int			argc;
	char		**argv;
	int			piperead;
	int			pipewrite;
	char		*redirect_op;
	char		*redirect_des;
	char		*redirect_src;
}				t_exec_sc;

void			execute_astree(t_astnode *astree, t_sh *sh);
void			execute_simple_command(t_astnode *astree, t_exec *exec,
	int piperead, int pipewrite);
int				run_command(t_exec *exec, char *cmd_name, char **cmd_line);
/*
**	builtin.c
*/
int				check_built_in(t_exec *exec, t_exec_sc *exec_sc);
int				is_builtin(char *com_name);
/*
**	builtin list
*/
void			echo_builtin(t_exec *exec, char **arg);
void			cd_builtin(t_exec *exec, char **arg);
void			env_builtin(t_exec *exec, char **arg);
void			set_builtin(t_exec *exec, char **arg);
void			unset_builtin(t_exec *exec, char **arg);
void			exit_builtin(t_exec *exec, char **arg);
void			hash_builtin(t_exec *exec, char **arg);
void			type_builtin(t_exec *exec, char **arg);
void			export_builtin(t_exec *exec, char **arg);
/*
**	redirect.c
*/
void			redirect_lessand(t_exec_sc *exec_sc);
void			redirect_greatand(t_exec_sc *exec_sc);
void			redirect_dgreat(t_exec_sc *exec_sc);
void			redirect_less(t_exec_sc *exec_sc);
void			redirect_great(t_exec_sc *exec_sc);
/*
**	init_run_helper.c
*/
void			init_run_count_argv(t_astnode *astree, t_exec_sc *exec_sc);
void			init_run_store_argv(t_astnode *astree, t_exec_sc *exec_sc);
/*
**	exec.c
*/
void			execute_pipe_sequence(t_astnode *astree, t_exec *exec,
	int prevread, int prevwrite);
void			execute_pipe_sequence_pipe_and_fork(t_astnode *astree,
	t_exec *exec, int prevread, int prevwrite);

#endif
