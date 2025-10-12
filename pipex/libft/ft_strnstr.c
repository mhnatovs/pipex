/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:22:37 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/20 16:09:23 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == 0)
		return ((char *) haystack);
	while (i < len && haystack[i])
	{
		while ((i + j) < len && haystack[i + j] == needle[j] && haystack[i + j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}

// #include <string.h>
// int main()
// {
// 	const char *haystack = "first occurrence of string needle";
// 	const char *needle = "string";
// 	const char *str1 = "abcdefgh";
// 	const char *needle1 = "abc";
// 	const char *str2 = "abc";
// 	const char *needle2 = "abcdef";
// 	const char *str3 = "abcdefgh";
// 	const char *needle3 = "";
// 	const char *str4 = "123";
// 	const char *needle4 = "345";
// 	printf("%s\n", ft_strnstr(str4, needle4, 0));
// 	printf("%s\n", strnstr(str4, needle4, 0));
// }