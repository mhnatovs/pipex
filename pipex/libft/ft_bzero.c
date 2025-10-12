/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:02:43 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/13 12:26:07 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// #include <string.h>
// int main()
// {
//     char str[100] = "writes n zeroed bytes to the string s";
//    ft_bzero(str + 10, 50);
//     // printf("After memset(): %s\n", str);
// 	printf("%s",str);
//     return 0;
// }