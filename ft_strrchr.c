#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    unsigned char cc;
    unsigned int i;
    unsigned int backup;

    cc = (unsigned char) c;
    i = 0;
    while (s[i])
    {
        if (s[i] == cc)
        {
            backup = i;
        }
        i++;
    }
    return (void *) (&s[backup]);
}
int main ()
{
    char st[] = "hello worlllld1";
    printf("%s\n", ft_strrchr(st, 'l'));
}