#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (s1[i] && s2[i] && i < n)
    {
        if (s1[i] == s2[i])
        {
            i++;
        }
        else
            return (unsigned char)(s1[i] - s2[i]);
    }
    return (0);
}
int main ()
{
    char u1[] = "hello";
    char u2[] = "HELLO";

    printf("%d\n", ft_strncmp(u1, u2, 4));
}