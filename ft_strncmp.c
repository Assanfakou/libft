#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
#include <stdio.h>
#include <string.h>
int main ()
{
	char si[] = "hEloo";
	char se[] = "heloo";
	int l = ft_strncmp(si, se, 2);
	int s = strncmp(si, se, 2);
	printf("mine , the combination : %d\n,", l);
	printf("theirs , the combination : %d\n,", s);
}

