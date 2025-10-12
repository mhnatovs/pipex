/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:02:47 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/15 15:49:28 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			total_size;

	i = 0;
	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// #include <string.h>
// int main()
// {
// 	int *ptr1 = (int *)ft_calloc(100,sizeof(int));
// 	int *ptr2 = (int *)calloc(100,sizeof(int));
// 	printf("%i\n", *ptr1);
// 	printf("%i", *ptr2);
// }