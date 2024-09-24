#include "libft.h"

char	*ft_strlcpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i > n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i > n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
#include <stdio.h>
#include <string.h>

int main ()
{
	char sr[] = "hello assanKou";
	char de[18] = ""; 
	printf("%s\n", ft_strlcpy(de, sr, 3));
	printf("%s\n", strncpy(de, sr, 3));
}
