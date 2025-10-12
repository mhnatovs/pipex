/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:53:24 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/08/01 15:23:56 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;
	int	temp;

	if (!s)
		return (write (1, "(null)", 6));
	count = 0;
	i = 0;
	while (s[i])
	{
		temp = ft_putchar(s[i]);
		if (temp == -1)
			return (-1);
		count += temp;
		i++;
	}
	return (count);
}
