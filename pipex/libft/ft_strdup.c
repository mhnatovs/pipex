/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:39:29 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/15 15:49:10 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (s1[size])
		size++;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str[100] = "allocates sufficient";
// 	char *str1 = strdup(str);
// 	printf("%s\n", str1);
// 	char str2[100] = "memory for a copy";
// 	char *str3 = ft_strdup(str);
// 	printf("%s", str3);
// }