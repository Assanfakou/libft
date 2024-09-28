#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
#include <stdio.h>
#include <string.h>

int main ()
{
	char st[] = "hello";
	char de[5] = "";
	printf("%s\n", ft_strcpy(de, st));
/*	printf("%s\n", strcpy(de, st));*/
}
