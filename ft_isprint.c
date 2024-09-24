#include "libft.h"

int	ft_isprint(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
		{
			str++;
		}
		else
			return (0);
	}
	return (1);
}
