/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:58:08 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/13 19:21:38 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i++], "/");
		path = strjoin_free(path, cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (free_split(paths), path);
		free(path);
	}
	free_split(paths);
	return (NULL);
}

char	*strjoin_free(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	if (!joined)
	{
		free(s1);
		return (NULL);
	}
	free(s1);
	return (joined);
}

void	print_command_not_found(char *cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	execute(char *cmd_str, char **envp, int is_last_cmd)
{
	char	**cmd;
	char	*path;

	cmd = smart_split(cmd_str);
	if (!cmd || !cmd[0])
		error_path(cmd, is_last_cmd);
	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], X_OK) == 0)
			execve(cmd[0], cmd, envp);
		else
			error_execve(cmd[0], cmd);
	}
	else
	{
		path = find_path(cmd[0], envp);
		if (!path)
			error_path(cmd, is_last_cmd);
		if (execve(path, cmd, envp) == -1)
			execve(path, cmd, envp);
	}
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
