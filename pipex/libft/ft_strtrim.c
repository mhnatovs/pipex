/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:25:48 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/16 13:50:47 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*is_char(char const s, char const *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == s)
			return ((char *)&c[i]);
		i++;
	}
	return (NULL);
}

char	*ft_setstr(char *s1, const char *s2, size_t s, size_t e)
{
	size_t	i;

	i = 0;
	while (s < e)
		s1[i++] = s2[s++];
	s1[i] = '\0';
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	size_t		start;
	size_t		end;

	start = 0;
	end = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && is_char (s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_char(s1[end - 1], set))
		end--;
	res = (char *)malloc(sizeof(char) * sizeof(char) *(end - start + 1));
	if (res == NULL)
		return (NULL);
	return (ft_setstr(res, s1, start, end));
}

// int main()
// {
// 	printf("%s", ft_strtrim("12", "12"));
// }
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }