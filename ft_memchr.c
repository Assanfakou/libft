/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:47:13 by hfakou            #+#    #+#             */
/*   Updated: 2024/10/23 20:44:04 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *st;
	unsigned char l;
	size_t i;

	st = (unsigned const char *) s;
	l = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (st[i] == l)
		{
			return (void *)(st + i);
		}
		i++;
	}
	return (NULL);
}
int main ()
{
	char sd[] = "alien is not from earth";
	printf("%s" , ft_memchr(sd, 'f', sizeof(sd)));
}
