/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:19:07 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/14 14:53:57 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

// #include <string.h>
// int main()
// {
// 	char dest[50] = "1";
// 	char src[50] = "123";
// 	char dest1[50] = "1";
// 	char src1[50] = "123";
// 	printf("%lu\n", strlcpy(dest,src,15));
// 	printf("%s\n", dest);
// 	printf("%lu\n", ft_strlcpy(dest1,src1,15));
// 	printf("%s\n", dest1);
// }