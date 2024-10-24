/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:25:20 by hfakou            #+#    #+#             */
/*   Updated: 2024/10/24 14:03:57 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void    *ft_memmove(void *dest, const void *src, size_t n)
{                                                                                                           
    char    *de;
    const char *sr;
    size_t i;

    de = (char *) dest;
    sr = (const char *) src;
    if (de == sr)
        return (de);
    if (de > sr && de < sr + n)
    {
        i = n;
        while (i > 0)
        {
            de[i - 1] = sr[i - 1];
            i--;
        }
    }else{
        i = 0;
        while (i < n)
        {
            de[i] = sr[i];
            i++;
        }
    }
    return (de);
}
int main ()
{
    char st[] = "alien is not from earth";
    ft_memmove(st + 14, st + 9, 9);
    printf("%s", st);
}
