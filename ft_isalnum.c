#include "libft.h"

int	ft_isalnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
		 || (str[i] >= 'A' && str[i] <= 'Z')
		 || (str[i] >= '0' && str[i] <=	'9'))
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}
