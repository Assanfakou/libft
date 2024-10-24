#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	g;

	if (*little == '\0')
		return (big);
	l = 0;
	while (big[l] != '\0' && l < len)
	{
		i = l;
		g = 0;
		while (little[g] != '\0' && i <= len &&  big[i] != '\0' && big[i] == little[g])
		{
			g++;
			i++;
		}
		if (little[g] == 0)
		{
			return (&big[l]);
		}
		l++;
	}
	return (0);
}
int main ()
{
	char bi[] = "Gaz Ba,ri Bar final";
	char li[] = "Bar";

	printf("%s\n", ft_strnstr(bi, li, 20));
}
