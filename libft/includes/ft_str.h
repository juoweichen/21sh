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

#ifndef FT_STR_H
# define FT_STR_H

/*
**	length
*/
size_t		ft_wstrlen(const wchar_t *wstr);
size_t		ft_strlen(const char *str);
/*
**	copy string
*/
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
/*
**	concatenate string
*/
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
/*
**	find charactor in string
*/
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strchri(char *s, char c);
/*
**	find string in string
*/
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
/*
**	create new string
*/
char		*ft_strnew(size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
/*
**	delete string
*/
void		ft_strdel(char **as);
void		ft_strclr(char *s);
/*
**	iterate a function pointer to string
*/
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
/*
**	iterate a function pointer to a new string
*/
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*
**  compare two string
*/
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
/*
**  catch a sub-string from string
*/
char		*ft_strsub(char const *s, unsigned int start, size_t len);
/*
**  trim space in string
*/
char		*ft_strtrim(char const *s);
/*
**	string split
*/
char		**ft_strsplit(char const *s, char c);
int			ft_words_count(const char *str, char c);
int			*ft_words_pos(const char *str, char c, int wcount);
/*
**  join two string
*/
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_btw(char const *s1, char const *s2, char btw);

#endif
