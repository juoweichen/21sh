/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:13:21 by csinglet          #+#    #+#             */
/*   Updated: 2019/01/21 16:13:22 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/signals.h"

/*
**	SIGINT   - 02 - interrupt program
**	SIGQUIT  - 03 - quit program
**	SIGABRT  - 06 - abort program (formerly SIGIOT)
**	SIGNKILL - 09 - kill program
**	SIGSTOP  - 17 - stop (cannot be caught or ignored)
**	SIGTSTP  - 18 - stop signal generated from keybaord
**	SIGCONT  - 19 - continue after stop
**	SIGWINCH - 28 - window size change
*/

void			signals_init(void)
{
	signal(SIGINT, handle_signals);
	signal(SIGQUIT, handle_signals);
	signal(SIGABRT, handle_signals);
	signal(SIGKILL, handle_signals);
	signal(SIGSTOP, handle_signals);
	signal(SIGTSTP, handle_signals);
	signal(SIGCONT, handle_signals);
	signal(SIGWINCH, handle_signals);
}

static void		suspend_program(void)
{
	disable_raw_mode();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void		restore_program(void)
{
	enable_raw_mode();
	signals_init();
}

void			handle_signals(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		ft_putstr(PROMPT);
		signals_init();
	}
	else if (sig == SIGQUIT || sig == SIGABRT ||
		sig == SIGKILL || sig == SIGSTOP)
		;
	else if (sig == SIGCONT)
		restore_program();
	else if (sig == SIGTSTP)
		suspend_program();
}
