/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 09:43:29 by ocheresh          #+#    #+#             */
/*   Updated: 2019/06/21 20:01:21 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "../../vmdir/my_printf/includes/ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*fts_memset(void *b, int c, size_t len);
void				fts_bzero(void *s, size_t n);
void				*fts_memcpy(void *dest, const void *src, size_t n);
void				*fts_memccpy(void *dest, const void *src, int c, size_t n);
void				*fts_memmove(void *dest, const void *src, size_t n);
void				*fts_memchr(const void *s, int c, size_t n);
int					fts_memcmp(const void *s1, const void *s2, size_t n);
size_t				fts_strlen(const char *s);
char				*fts_strdup(const char *src);
char				*fts_strcpy(char *dest, const char *src);
char				*fts_strncpy(char *dest, const char *src, size_t n);
char				*fts_strcat(char *des, const char *src);
char				*fts_strncat(char *dest, const char *src, size_t n);
size_t				fts_strlcat(char *dst, const char *src, size_t size);
char				*fts_strchr(const char *s, int c);
char				*fts_strrchr(const char *s, int c);
char				*fts_strstr(const char *str, const char *str2);
char				*fts_strnstr(const char *str, const char *str2, size_t n);
int					fts_strcmp(const char *s1, const char *s2);
int					fts_strncmp(const char *s1, const char *s2, size_t n);
int					fts_atoi(const char *nptr);
int					fts_isalpha(int c);
int					fts_isdigit(int c);
int					fts_isalnum(int c);
int					fts_isascii(int c);
int					fts_isprint(int c);
int					fts_toupper(int c);
int					fts_tolower(int c);
void				*fts_memalloc(size_t size);
void				fts_memdel(void **ap);
char				*fts_strnew(size_t size);
void				fts_strdel(char **as);
void				fts_strclr(char *s);
void				fts_striter(char *s, void (*f)(char *));
void				fts_striteri(char *s, void (*f)(unsigned int, char *));
char				*fts_strmap(char const *s, char (*f)(char));
char				*fts_strmapi(char const *s, char (*f)(unsigned int, char));
int					fts_strequ(char const *s1, char const *s2);
int					fts_strnequ(char const *s1, char const *s2, size_t n);
char				*fts_strsub(char const *s, unsigned int start, size_t len);
char				*fts_strjoin(char const *s1, char const *s2);
char				*fts_strtrim(char const *s);
char				**fts_strsplit(char const *s, char c);
char				*fts_itoa(int n);
void				fts_putchar(char c);
void				fts_putstr(char const *s);
void				fts_putendl(char const *s);
void				fts_putnbr(int n);
void				fts_putchar_fd(char c, int fd);
void				fts_putstr_fd(char const *s, int fd);
void				fts_putendl_fd(char const *s, int fd);
void				fts_putnbr_fd(int n, int fd);
t_list				*fts_lstnew(void const *content, size_t content_size);
void				fts_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				fts_lstdel(t_list **alst, void(*del)(void *, size_t));
void				fts_lstadd(t_list **alst, t_list *new);
void				fts_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*fts_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				fts_swap(int *a, int *b);
void				fts_lstadd_end(t_list **begin_list, t_list *new);
int					fts_listsize(t_list *lst);
char				*fts_wordfinder(char const *s, char c);
int					fts_cstr(char const *s, char c);
char				*fts_strndup(char *str, int k);

#endif
