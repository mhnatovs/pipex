/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:16:38 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/13 12:28:34 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
		return (c);
	}
	else
		return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
// 	char c = 'x';
// 	printf("%c\n", ft_toupper(c));
// 	printf("%d", toupper(4));
// }