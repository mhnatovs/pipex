/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:26 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/13 12:27:34 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len > 0)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str1[100] = "writes len bytes of value c";
// 	char str2[100] = "to the string b";
// 	memset(str1, '-', 1);
// 	printf("%s\n",str1);
// 	ft_memset(str2, '_', 5);
// 	printf("%s\n",str2);
// }