/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:46:17 by xchouina          #+#    #+#             */
/*   Updated: 2022/07/28 13:13:00 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	ft_bzero(void *s, size_t n);

int		ft_toupper(int c);
int		ft_tolower(int c);

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int t);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);

char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//Bonus
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// AJOUTS
char	*ft_strcpy(char *dest, char *src);
void	ft_swap(int a, int b);
void	ft_pt_swap(int *a, int *b);
long	ft_atol(const char *str);

char	*get_next_line(int fd);
char	*ft_get_temp(char *rmd);
char	*ft_new_rmd(char *rmd);

int		ft_isquote(const int c);
bool	ft_iswhitespace(const int c);
bool	ft_iseven(const int c);
bool	ft_isuneven(const int c);

void	ft_arrayprint(char **tab);
int		ft_arraylen(char **tab);
char 	**ft_arraycpy(char **tab);
char	**ft_arrayadd(char **tab, char *str_to_add);
char	ft_arraysrch(char **tab, char str_to_find);

#endif