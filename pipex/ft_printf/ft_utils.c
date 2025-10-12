/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:23:02 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/08/12 15:28:01 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsnbr(unsigned int n)
{
	int	count;
	int	temp;

	count = 0;
	if (n >= 10)
	{
		temp = ft_put_unsnbr(n / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = ft_putchar((n % 10) + '0');
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	ft_puthex(unsigned int num)
{
	const char	*hex_str;
	int			count;
	int			temp;

	hex_str = "0123456789abcdef";
	count = 0;
	if (num >= 16)
	{
		temp = ft_puthex(num / 16);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = ft_putchar(hex_str[num % 16]);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	ft_puthex_cap(unsigned int num)
{
	char	*hex_cap;
	int		count;
	int		temp;

	hex_cap = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
	{
		temp = ft_puthex_cap(num / 16);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = ft_putchar(hex_cap[num % 16]);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

static int	ft_putptr_rec(unsigned long buf)
{
	char	*base;
	int		count;
	int		temp;

	base = "0123456789abcdef";
	count = 0;
	if (buf >= 16)
	{
		temp = ft_putptr_rec((buf / 16));
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = ft_putchar(base[buf % 16]);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	unsigned long	buf;
	int				count;
	int				temp;

	if (ptr == NULL)
		return (ft_putstr(NULL_PTR));
	buf = (unsigned long)ptr;
	count = 0;
	temp = write (1, "0x", 2);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = ft_putptr_rec(buf);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}
