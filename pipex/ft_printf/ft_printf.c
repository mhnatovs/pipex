/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:31:06 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/08/20 10:59:58 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_input(char c, va_list *args)
{
	int	temp;

	temp = 0;
	if (c == 'c')
		temp = ft_putchar(va_arg(*args, int));
	else if (c == 's')
		temp = ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		temp = ft_put_ptr(va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		temp = ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		temp = ft_put_unsnbr(va_arg(*args, unsigned int));
	else if (c == 'x')
		temp = ft_puthex(va_arg(*args, unsigned int));
	else if (c == 'X')
		temp = ft_puthex_cap(va_arg(*args, unsigned int));
	else if (c == '%')
		temp = ft_putchar('%');
	else
		return (0);
	if (temp == -1)
		return (-1);
	return (temp);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		temp;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			temp = check_input(s[++i], &args);
		else
			temp = ft_putchar(s[i]);
		if (temp == -1)
		{
			va_end(args);
			return (-1);
		}
		count += temp;
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	int		num;
// 	void	*p;
// 	long	n;

// 	setbuf(stdout, NULL);
// 	num = 123;
// 	p = &num;
// 	n = -214;
// 	printf("\n0x%p-\n", (void *)ULONG_MAX);
// 	ft_printf("0x%p-\n", (void *)ULONG_MAX);
// 	ft_printf("");
// 	printf("");
// 	ft_printf("\nmy print - just text\n");
// 	printf("original - just text\n");
// 	ft_printf("\n%c%c%c", 'a', '\t', 'b');
// 	printf("\n%c%c%c\n", 'a', '\t', 'b');
// 	ft_printf("\nc my print - \t%c\n", 0);
// 	printf("c original - \t%c\n", 0);
// 	ft_printf("\ns my print - \t%s\n", "string");
// 	printf("s original - \t%s\n", "string");
// 	ft_printf("\ns my print - \t%s\n", "");
// 	printf("s original - \t%s\n", "");
// 	ft_printf("\ns my print - \t%s\n", NULL);
// 	printf("s original - \t%s\n", NULL);
// 	ft_printf("\np my print - \t%p\n", p);
// 	printf("p original - \t%p\n", p);
// 	ft_printf("\np my print - \t%p\n", NULL);
// 	printf("p original - \t%p\n", NULL);
// 	ft_printf("\nd my print - \t%d\n", 1);
// 	printf("d original - \t%d\n", 1);
// 	ft_printf("\nd my print - \t%d\n", n);
// 	printf("d original - \t%ld\n", n);
// 	ft_printf("\nd my print - \t%d\n", 123);
// 	printf("d original - \t%d\n", 123);
// 	ft_printf("\nd my print - \t%d\n", 0);
// 	printf("d original - \t%d\n", 0);
// 	ft_printf("\ni my print - \t%i\n", -1234);
// 	printf("i original - \t%i\n", -1234);
// 	ft_printf("\nu my print - \t%u\n", -1);
// 	printf("u original - \t%u\n", -1);
// 	ft_printf("\nu my print - \t%u\n", 0);
// 	printf("u original - \t%u\n", 0);
// 	ft_printf("\nx my print - \t%x\n", 2051118);
// 	printf("x original - \t%x\n", 2051118);
// 	ft_printf("\nX my print - \t%X\n", 2051118);
// 	printf("X original - \t%X\n", 2051118);
// 	ft_printf("\nx my print - \t%x\n", 0);
// 	printf("x original - \t%x\n", 0);
// 	ft_printf("\nX my print - \t%X\n", 0);
// 	printf("X original - \t%X\n", 0);
// 	printf("\n%d\n", ft_printf("*%c\n%c\n%c*", 'a', '\t', 'b'));
// 	printf("\n%d\n", printf("*%c\n%c\n%c*", 'a', '\t', 'b'));
// 	printf("\n");
// 	return (0);
// }