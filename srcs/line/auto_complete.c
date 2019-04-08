/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 02:04:52 by rsathiad          #+#    #+#             */
/*   Updated: 2019/03/22 20:39:02 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line.h"

/*
** auto_complete (TAB)
*/
void	auto_complete(t_edit *edit)
{
	edit = NULL;
	
	//if input a command (if not adding any prefix, treat as command)
		//search command form env
			//search function

	//if input a dir
		//search from dir
			//search function



	//***Search function****
	//if only one result
			//print line
	//else 
		//show options
		//wait for user input
			//if input another tab
				//round to next option
			//else if input char 
				//add to line
}