#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int s;

	if (*to_find == '\0')
	{
		return(str);
	}
	s = 0;
	while (str[s])
	{
		j = s;
		i = 0;
		while (to_find[i] == str[j] && str[j] && to_find[i])
		{
			i++;
			j++;
		}
		if (to_find[i] == '\0')
		{
			return (&str[s]);
		}
		s++;
	}
	return (0);
}
#include <string.h>
int main ()
{
	char st[] = "alaloalijador";
	char find[] = "ali";
	printf("%s\n", ft_strstr(st, find));
	printf("%s\n", strstr(st, find));
}
