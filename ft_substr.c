#include "libft.h"

char *substr(const char *s, size_t start, size_t len)
{
    size_t i;
    char *ptr;

    if (s == NULL)
        return (NULL);
    if (ft_strlen(s) <= start)
        return (ft_strdup(""));
    ptr = malloc(len + 1);
    if (ptr == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        ptr[i] = s[start];
        i++;
        start++;
    }
    ptr[i] = '\0';
    return (ptr);
}
