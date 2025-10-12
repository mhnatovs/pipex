/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:03:54 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/07/21 10:13:18 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*my_free(char **str, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	wordcount(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			res++;
		i++;
	}
	return (res);
}

static int	add_word(char **res, char const *s, int start, int end)
{
	char	*newptr;
	int		i;

	i = 0;
	newptr = malloc(sizeof(char) * (end - start + 1));
	if (!newptr)
		return (0);
	while (start < end)
	{
		newptr[i] = s[start];
		i++;
		start++;
	}
	newptr[i] = '\0';
	*res = newptr;
	return (1);
}

char	**alloc_and_check(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!(res))
		return (NULL);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	int			start;
	size_t		i;
	size_t		j;

	res = alloc_and_check(s, c);
	if (!s || !res)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || s[i] == '\0') && start >= 0)
		{
			if (!add_word(&res[j++], s, start, i))
				return (my_free(res, j - 1));
			start = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

// int main()
// {
// 	int i = 0;
// 	char **ptr;
// 	ptr = ft_split("Allocates memory using malloc", ' ');
// 	while (ptr[i])
// 	{
// 		printf("%s\n", ptr[i]);
// 		free(ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// }
