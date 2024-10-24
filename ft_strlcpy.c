#include "libft.h"

size_t  ft_strlcpy(char *dest, const char *src, size_t n)
{
    size_t  i;
    size_t  sr_len;
    
    sr_len = 0;
    while (src[sr_len])
        sr_len++;
    i = 0;
    while (src[i] && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[n - 1] = '\0';
    return (sr_len);
}
int main ()
{
    char st[] = "hello world";
    char de[14] ="hi";
    
    printf("%ld", ft_strlcpy(de, st, 5));
}
