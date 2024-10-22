#include "libft.h"
#include <stddef.h>
char	*ft_strnstr(char *big, char *little, unsigned int len)
{
	unsigned int	i;
	unsigned int	l;
	unsigned int	g;

	if (*little == '\0')
		return (big);
	l = 0;
	while (big[l] != '\0')
	{
		i = l;
		g = 0;
		while (little[g] != '\0' && big[i] != '\0' && big[i] == little[g])
		{
			g++;
			i++;
		}
		if (little[g] == '\0')
		{
			return (&big[l]);
		}
		l++;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>

int main ()
{
	char bi[] = "Gaz Bar Pets";
	char li[] = "Bar";

	printf("%s\n", ft_strnstr(bi, li, 4));
}
