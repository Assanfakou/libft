#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    size_t i;
    size_t backup;
    size_t j;

    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] == (char) c)
        {
            backup = i;
            j = i;
        }
        i++;
    }
    if (s[i] == (char) c)
        return (&s[i]);
    else if (backup == j)
        return (&s[backup]);
    return (NULL);
}
int main ()
{
    char st[] = "hello worlllld1";
    printf("%s\n", ft_strrchr(st, 'l'));
}