/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:08:15 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/12 22:44:48 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <wchar.h>
# include <stdio.h>
# define MAX_LINE 999999

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				get_next_line(int fd, char **line);
char			*get_next_line_stdin(void);
char			*get_next_line_fd(int fd);
char			*get_raw_line_fd(int fd);
int				ft_strspn(const char *control, const char *s2);
int				ft_strachr(const char *format, const char *where);
int				ft_straposchr(const char *format, const char *where);
int				ft_chrpos(char *str, char ch);
int				ft_wctomb(char *s, wchar_t wchar);
int				ft_wstrtombstr(char *dst, wchar_t *wchar);
int				ft_wcsncpy(wchar_t *src, wchar_t *dst, size_t len);
size_t			ft_wcblen(wchar_t *src);
size_t			ft_wcslen(wchar_t *src);
char			ft_strlchr(char *str);
char			*ft_usitoa(intmax_t n);
char			*ft_straddpostfix(char *what, char *to);
char			*ft_straddprefix(char *what, char *to);
char			*ft_strskp(char c, char *src);
char			*ft_strnmcpy(const char *src, size_t len);
char			*ft_strpcpy(char *s1, char *s2);
char			*ft_strpspn(const char *control, const char *s2);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strpass(char *str, int n);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strchcpy(char *dest, char *src, char ch);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strdup(const char *src);
char			*ft_strmap(char const *s, char (*f)(char));
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(intmax_t n);
char			*ft_uitoa(uintmax_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfree(char const *s1, char const *s2);
void			ft_free(void *aim);
char			*get_raw_line_fd(int fd);
char			*ft_strtrim(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_bzero(void *s, size_t n);
void			ft_strdel(char **as);
void			ft_putendl(const char *s);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_lstnew(void const *content, size_t size);
void			ft_striter(char *s, void (*f)(char *));
void			ft_strclr(char *s);
void			ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			*ft_calloc(size_t count, size_t size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f) (t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void			ft_error(char *message);
void			ft_subchar(char *str, char from, char to);
size_t			ft_strlen(const char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strmlen(char *s);
t_list			*ft_lstmap(t_list *lst, t_list *(f) (t_list *elem));
int				ft_fd_valid(int fd);
void			ft_delete_deintegrated(char **deintegrated);
int				ft_is_whitespace(char c);
char			**ft_split_whitespace(char const *s);

#endif
