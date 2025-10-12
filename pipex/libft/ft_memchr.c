/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:49:56 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/13 12:27:13 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;
	size_t				i;

	str = (const unsigned char *) s;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (0);
}

// #include <string.h>
// int main()
// {
// 	char c = 'i';
// 	char str[100] = "locates first occurrence of c";
// 	char str1[100] = "locates first occurrence of c";
// 	printf("%s\n",ft_memchr(str,c,15));
// 	printf("%s",memchr(str1,c,15));
// }