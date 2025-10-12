/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:26:45 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/08/12 15:32:45 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# if defined(__linux__)
#  define NULL_PTR "(nil)"
# elif defined(__APPLE__)
#  define NULL_PTR "0x0"
# endif

int	ft_printf(const char *s, ...);
int	ft_put_unsnbr(unsigned int n);
int	ft_puthex(unsigned int num);
int	ft_puthex_cap(unsigned int num);
int	ft_put_ptr(void *ptr);

#endif