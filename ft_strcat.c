#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
	{
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
#include <string.h>
#include <stdio.h>

int main ()
{
	char st[] = "hellohd;j";
        char de[] = "assan ";
	printf("%s\n", ft_strcat(de, st));
	printf("%s\n", strcat(de, st));
}
