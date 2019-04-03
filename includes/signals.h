/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:18:49 by csinglet          #+#    #+#             */
/*   Updated: 2019/03/13 22:19:31 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

#include "line.h"
#include "../libft/includes/libft.h"
#include <signal.h>
#include <sys/ioctl.h>

void			signals_init(void);
void			handle_signals(int sigh);

#endif
