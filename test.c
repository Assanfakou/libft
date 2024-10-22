#include <stdio.h>
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    char *de;   
    const char *sr;
    size_t l;

    sr = (const char *) src;
    de = (char *) dest;
    if (de > sr && de < sr + n)
    {
        l = n;
        while (l > 0)
        {
            de[l - 1] = sr[l - 1];
            l--;
        }
    }else{
        l = 0;
        while (l < n)
        {
            de[l] = sr[l];
            l++;
        } 
    }
    return (de);
}
int main ()
{
    char sr[] = "helloworld";
    ft_memmove(sr + 2, sr + 5, 5);
    printf("%s", sr);
}