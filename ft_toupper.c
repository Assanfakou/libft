#include "libft.h"

char	*ft_toupper(char *st)
{
	int	i;

	i = 0;
	while (st[i])
	{
		if (st[i] >= 'a' && st[i] <= 'z')
		{
			st[i] -= 32;
		}
		i++;
	}
	return (st);
}
