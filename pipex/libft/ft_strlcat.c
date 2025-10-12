/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:50:45 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/23 11:17:04 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
		i++;
	dst_len = i;
	while (dstsize > dst_len + j + 1 && src[j])
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	if (dst_len != dstsize)
		dst[dst_len + j] = '\0';
	return (dst_len + ft_strlen(src));
}
// #include <string.h>
// int main()
// {
// 	char str_dest[100] = "";
// 	char str_src[100] = "===1==";
// 	char str_dest1[100] = "";
// 	char str_src1[100] = "===1==";
// 	printf("%lu\n", strlcat(((void *)0), "fake", 0));
// 	// printf("%s\n", str_dest);
// 	printf("%lu\n", ft_strlcat(((void *)0), "fake", 0));
// 	// printf("%s\n", str_dest1);
// 	// printf("%s\n", str_dest);
// }