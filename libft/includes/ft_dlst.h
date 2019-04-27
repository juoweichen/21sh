/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:28:17 by juochen           #+#    #+#             */
/*   Updated: 2018/04/19 01:08:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLST_H
# define FT_DLST_H

typedef	struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstadd(t_dlist **alst, t_dlist *new);
void				ft_dlstaddend(t_dlist **alst, t_dlist *new);
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdel_content(void *content, size_t content_size);
void				ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
t_dlist				*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem));

#endif
