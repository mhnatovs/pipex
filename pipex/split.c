/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:21:56 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/12 15:27:52 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	arg_length(const char *str, int *i)
{
	int		len;
	char	quote;

	len = 0;
	quote = 0;
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		quote = str[(*i)++];
		while (str[*i] && str[*i] != quote)
		{
			len++;
			(*i)++;
		}
		if (str[*i] == quote)
			(*i)++;
	}
	else
	{
		while (str[*i] && !ft_isspace(str[*i]))
		{
			len++;
			(*i)++;
		}
	}
	return (len);
}

int	ft_isspace(int c)
{
	if (c == 32 || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

static char	*extract_arg(const char *str, int *i)
{
	int		j;
	char	quote;
	char	*arg;

	quote = 0;
	j = 0;
	arg = malloc(ft_strlen(str + *i) + 1);
	if (!arg)
		return (NULL);
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		quote = str[(*i)++];
		while (str[*i] && str[*i] != quote)
		{
			if (str[*i] == '\\' && str[*i + 1])
				(*i)++;
			arg[j++] = str[(*i)++];
		}
		if (str[*i] == quote)
			(*i)++;
	}
	else
	{
		while (str[*i] && !ft_isspace(str[*i]))
		{
			if (str[*i] == '\\' && str[*i + 1])
				(*i)++;
			arg[j++] = str[(*i)++];
		}
	}
	arg[j] = '\0';
	return (arg);
}

char	**smart_split(char *str)
{
	char	**result;
	int		i;
	int		j;
	int		count;
	char	*arg;

	i = 0;
	count = 0;
	j = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			arg_length(str, &i);
			count++;
		}
	}
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			arg = extract_arg(str, &i);
			if (!arg)
				return (free_split(result), NULL);
			result[j++] = arg;
		}
	}
	result[j] = NULL;
	return (result);
}

// while (str[i])
// 	{
// 		while (ft_isspace(str[i]))
// 			i++;
// 		if (str[i])
// 		{
// 			arg_length(str, &i);
// 			count++;
// 		}
// 	}