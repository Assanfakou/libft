#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Prototypes*/
#ifndef LIBFT_H
#define LIBFT_H

int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isprint(int c);
int	ft_isascii(int c);
void	*ft_memset(void *s, int a, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t size);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void    *ft_memchr(const void *s, int c, size_t n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char    *ft_strrchr(const char *s, int c);
int ft_atoi(const char *str);
char	*ft_strdup(const char *str);
void *ft_calloc(size_t nmemb, size_t size);
char *substr(const char *s, size_t start, size_t len);
#endif
