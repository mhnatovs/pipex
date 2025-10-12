/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:50:14 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/13 12:27:24 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;
	size_t	i;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if ((dst == 0 && src == 0))
		return (dst);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

// #include <string.h>
// int main()
// {
// 	char str1[100] = "copies n bytes from memory area src";
// 	char str2[100] = "123";
// 	size_t n = 2;
// 	printf("%s\n", ft_memcpy(str2,str1,n));
// 	printf("%s", memcpy(str2,str1,n));
// }