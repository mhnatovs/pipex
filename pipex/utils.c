/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:58:08 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/12 12:31:50 by mhnatovs         ###   ########.fr       */
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
		path = ft_strjoin_free(path, cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (free_split(paths), path);
		free(path);
	}
	free_split(paths);
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
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

void	execute(char *cmd_str, char **envp, int is_last_cmd)
{
	char	**cmd;
	char	*path;

	cmd = smart_split(cmd_str);
	if (!cmd || !cmd[0])
	{
		ft_putstr_fd("pipex: command not found\n", 2);
		free_split(cmd);
		if (is_last_cmd)
			exit(127);
		else
			exit(0);
	}
	path = find_path(cmd[0], envp);
	if (!path)
		error_path(cmd, is_last_cmd);
	if (execve(path, cmd, envp) == -1)
		error_execve(path, cmd);
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

// void	execute(char *cmd_str, char **envp)
// {
// 	char	*argv[] = {"/bin/sh", "-c", cmd_str, NULL};

// 	if (execve("/bin/sh", argv, envp) == -1)
// 		error_exit(cmd_str);
// }