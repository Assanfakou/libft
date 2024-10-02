#include "libft.h"

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
		else
			i++;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>

int main ()
{
	char sr[] = "hello";
	char s = 's';

	printf("%s\n", ft_strchr(sr, s));
	printf("%s\n", strchr(sr, s));
}
