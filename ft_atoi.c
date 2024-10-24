#include "libft.h"

int ft_atoi(const char *str)
{
    size_t res;
    size_t i;
    size_t signe;

    res = 0;
    signe = 1;
    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            signe *= -1;
        }
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (signe * res);
}
int main ()
{
    printf("%d\n", ft_atoi("120"));
}