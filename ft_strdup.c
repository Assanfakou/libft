//#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*buffer;
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	buffer = malloc(sizeof(char * i + 1));
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

int main ()
{
	char sti[] = "hello you";
	printf("%s\n", ft_strdup(sti));
//	printf("%s\n", strdup(sti));
}
