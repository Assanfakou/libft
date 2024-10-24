#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*buffer;
	size_t	i;
 
	i = 0;
	while (str[i] != '\0')
		i++;
	buffer = (char *)malloc(i + 1);
	if (buffer == NULL)
	{	
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
int main ()
{
	char sti[] = "hello you";
	printf("%s\n",ft_strdup(sti));
	printf("%s\n", strdup(sti));
}
