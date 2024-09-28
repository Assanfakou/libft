#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_length;
	unsigned int	s_length;

	d_length = 0;
	while (dest[d_length])
		d_length++;

	s_length = 0;
	while (src[s_length])
		s_length++;

	d_length = j;
	i = 0;
	j = 0;
	while (src[i] && j < (n - 1) && n != 0)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[d_length + n] = '\0';
	return (d_length + n);
}
