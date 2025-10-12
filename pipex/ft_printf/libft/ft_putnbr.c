/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:43:09 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/08/01 16:06:34 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	safe_add(int *count, int temp)
{
	if (temp == -1)
		return (-1);
	*count += temp;
	return (0);
}

int	ft_putnbr(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	if (n < 0)
	{
		if (safe_add(&count, write(1, "-", 1)) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if (safe_add(&count, ft_putnbr(n / 10)) == -1)
			return (-1);
		if (safe_add(&count, ft_putnbr(n % 10)) == -1)
			return (-1);
	}
	else
	{
		if (safe_add(&count, ft_putchar(n + '0')) == -1)
			return (-1);
	}
	return (count);
}
