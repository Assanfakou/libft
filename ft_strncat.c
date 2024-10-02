#include "libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	l;

	l = 0;
	while (dest[l])
		l++;
	i = 0;
	while (src[i] && i < (n - 1))
	{
		dest[l] = src[i];
		l++;
		i++;
	}
	dest[l] = '\0';
	return (dest);
}
#include <stdio.h>
#include <string.h>

int main ()
{
	char s[] = "hello";
	char h[] = "sal";
	printf("%s\n", ft_strncat(h, s, 2));
	printf("%s\n", strncat(h, s, 2));
}
