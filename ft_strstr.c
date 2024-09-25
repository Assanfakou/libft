#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	l;
	int	s;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		l = i;
		s = 0;
		while (to_find[s] == str[l] && to_find[s] && str[l])
		{
			s++;
			l++;
		}
		if (to_find[s] == '\0')
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
