/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:02:02 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/17 15:08:39 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;
	int		lenth;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	lenth = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((lenth * sizeof(char)) + 1);
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		new_str[j] = s2[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
