#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Prototypes*/
#ifndef LIBFT_H
#define LIBFT_H

int	ft_strlen(char *);
int ft_atoi(char *);
char	*ft_tolower(char *s);
char	*ft_toupper(char *st);
int	ft_isalpha(char *);
int	ft_isdigit(char *str);
int	ft_isalnum(char *str);
int	ft_isprint(char *str);
int	ft_strncmp(char *s1, char *s2,unsigned int n);
int	ft_isascii(char *);
char	*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n);
char	*ft_strcpy(char *dest, char *);
char	*ft_strcat(char *, char *);
void	*ft_memset(void *s, int a, size_t n);
char	*ft_strdup(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t size);
char	*ft_strchr(char *str, char c);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int n);
void    *ft_memmove(void *dest, const void *src, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void    *ft_memchr(const void *s, int c, size_t n);
#endif