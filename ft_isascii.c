#include "libft.h"

int	ft_isascii(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 0 && str[i] <= 126)
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}
