#include <stddef.h>
#include "libft.h"
void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*de;
	char const	*sr;

	de = dest;
	sr = src;
	i = 0;
	while (i < size)
	{
		de[i] = sr[i];
		i++;
	}
	return (de);
}
#include <stdio.h>
#include <string.h>

int main() {
    int src[] = {1, 2, 3, 4, 5};  
    int dst[5];

    ft_memcpy(dst, src, sizeof(src));
    printf("Destination array after memcpy: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dst[i]);
    }
    printf("\n");

    return 0;
}

