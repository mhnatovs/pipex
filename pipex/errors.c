/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:26 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/12 14:14:10 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char *context)
{
	char	*msg;
	char	*copy;

	msg = strerror(errno);
	copy = ft_strdup(msg);
	if (copy && copy[0] >= 'A' && copy[0] <= 'Z')
		copy[0] += 32;
	ft_putstr_fd("pipex: ", 2);
	if (copy)
		ft_putstr_fd(copy, 2);
	else
		ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(context, 2);
	ft_putstr_fd("\n", 2);
	free(copy);
}

void	error_exit(char *context)
{
	error_message(context);
	exit(EXIT_FAILURE);
}

void	error_execve(char *path, char **cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	free(path);
	free_split(cmd);
	exit(errno);
}

void	error_path(char **cmd, int is_last_cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd("\n", 2);
	free_split(cmd);
	if (is_last_cmd)
		exit(127);
	else
		exit(0);
}

void	error_pid(pid_t pid)
{
	if (pid == -1)
		error_exit("fork");
}
