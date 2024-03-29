/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:53:14 by albartol          #+#    #+#             */
/*   Updated: 2024/03/05 18:49:22 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

// parte 1
int					ft_isalpha(const int i);
int					ft_isdigit(const int i);
int					ft_isalnum(const int i);
int					ft_isascii(const int i);
int					ft_isprint(const int i);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_calloc(size_t len, size_t size);
char				*ft_strdup(const char *str);

// parte 2
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_putchar_fd(const char c, int fd);
int					ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(const int n, int fd);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(const int n);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

// parte bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *to_add);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *to_add);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// get_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX FOPEN_MAX
# endif

char				*get_next_line(int fd);

// ft_printf

int					ft_printf(char const *str, ...);

int					ft_putstr_n(const char *s);
int					ft_putchar_n(char c);
int					ft_putnbr_n(long nbr);
int					ft_putnbr_base_n(unsigned long nbr, char *base);
int					ft_putptr_n(unsigned long ptr);

// push_swap

void				ft_quick_sort(int *list, int start, int len);
void				ft_merge_sort(int *list, int i, int *list_temp);

// minitalk

char				*ft_charjoin(const char *str, const char c);

// new
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);

#endif
