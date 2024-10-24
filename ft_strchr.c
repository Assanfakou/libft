#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	char ct;

	ct = (char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ct)
		{
			return ((char *) &str[i]);
		}
		i++;
	}
	if (str[i] == ct)
		return ((char *) &str[i]);
	return (NULL);
}
int main ()
{
	char sr[] = "hello";
	char s = '\0';

	printf("%s\n", ft_strchr(sr, s));
	printf("%s\n", strchr(sr, s));
}
