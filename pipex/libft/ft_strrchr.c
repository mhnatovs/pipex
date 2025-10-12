/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:54:01 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/14 17:23:38 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ptr_c;

	i = 0;
	ptr_c = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr_c = (char *) &s[i];
		i++;
	}
	if ((char) c == s[i])
		return ((char *)&s[i]);
	return ((char *)ptr_c);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *str = "strrchr() locates last occur. of c.";
// 	printf("%s\n", ft_strrchr(str, 's'));
// 	printf("%s\n", strrchr(str, 's'));

// }