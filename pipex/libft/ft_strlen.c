/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:09:14 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/18 18:37:12 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	printf("%zu\n", ft_strlen("Helllo\0"));
// 	printf("%lu", strlen("Helllo\0"));
// }