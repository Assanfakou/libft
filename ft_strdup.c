//#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*buffer;
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	buffer = (char *)malloc(i + 1);
	if (*buffer == '\0')
	{
		return (NULL);
	}
	i = 0;
	while (str[i] && *buffer)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer = '\0';
	return (buffer);
}
#include <stdio.h>
#include <string.h>

int main ()
{
	char sti[] = "hello you";
	printf("%s\n", ft_strdup(sti));
	printf("%s\n", strdup(sti));
}
