/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:50:19 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/13 14:24:50 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;
	size_t		i;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dest == source)
		return (dest);
	if (dest > source)
	{
		while (n-- > 0)
			dest[n] = source[n];
	}
	else
	{
		while (i < n)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

// #include <string.h>
// int main()
// {
// 	char dest[100] = "lorem ipsum dolor";
// 	char src[100] = "rem ipssum dolor sit a";
// 	char dest1[100] = "lorem ipsum dolor";
// 	char src1[100] = "rem ipssum dolor sit a";
// 	int n = 5;
// 	ft_memmove(dest,src,n);
// 	printf("%s\n", dest);
// 	memmove(dest1,src1,n);
// 	printf("%s", dest1);
// }