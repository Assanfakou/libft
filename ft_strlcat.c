#include "libft.h"

char	*ft_strlcat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_length;
	unsigned int	s_length;

	j = 0;
	d_length = 0;
	s_length = 0;
	while (dest[s_length])
		s_length++;

	i = 0;
	while (src[d_length])
		d_length++;

	d_length = j;
	s_length = i;
	i = 0;
	j = 0;
	while (src[i] && d_length < (n - 1) && n != 0)
	{
		dest[d_length] = src[i];
		i++;
		d_length++;
	}
	dest[d_length] = '\0';
	return (dest);
}
