#include "libft.h"
void	*ft_memset(void *s, int a, size_t n)
{
	size_t	i;
	char *_ptr;

	_ptr = s;
	i = 0;
	while (i < n)
	 {
		_ptr[i] = a;
		i++;
	}
	return (s);
}
int main ()
{
        char st[17];
        size_t     i;

        ft_memset(st, 0, 10);
        i = 0;
        while (i < 17)
        {
                printf("st[%ld] = %d\n", i, st[i]);
                i++;
		}
        
}