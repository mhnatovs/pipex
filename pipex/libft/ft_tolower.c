/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:54:35 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/13 12:28:30 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
		return (c);
	}
	else
		return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
// 	char c = 'Q';
// 	printf("%c\n", ft_tolower(c));
// 	printf("%d", tolower(4));
// }