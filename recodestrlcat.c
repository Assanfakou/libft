

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int n;
	unsigned int j;
	unsigned int d_length;
	unsigned int s_length;

	s_length = 0;
	while (src[s_length])
		s_length++;
	d_length = 0;
	while (dest[d_length])
		d_length++;
	if (d_length >= size)
	{
		return (s_length + size);
	}
	j = d_length;
	n = 0;
	while (src[n] && j < (size - 1))
	{
		dest[j] = src[n];
		j++;
		n++;
	}
	dest[j] = '\0';
	return (d_length + s_length);
}
#include <stdio.h>

int main ()
{
	char sr[] = "hello";
	char de[] = "say hi to joey";
	printf("%d", ft_strlcat(de, sr, 5));
}
