#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_length;
	size_t	s_length;

	d_length = 0;
	while (dest[d_length])
		d_length++;
	s_length = 0;
	while (src[s_length])
		s_length++;
	j = d_length;
	i = 0;
	while (src[i] && j < (size - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (d_length < size)
		return (size + s_length);
	return (d_length + s_length);
}

int main ()
{
	char st[] = "hello there";
	char he[20] = "hello ";
	printf("%ld\n", ft_strlcat(he, st, 17));
//	printf("%ld\n", strlcat(he, st, 17));
}
