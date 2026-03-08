/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:43 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/13 19:22:41 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_first_cmd(char **av, char **envp, int *fd)
{
	int	file_in;

	file_in = open(av[1], O_RDONLY);
	if (file_in == -1)
	{
		error_message(av[1]);
		exit(1);
	}
	dup2(file_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(file_in);
	close(fd[0]);
	close(fd[1]);
	execute(av[2], envp, 0);
}

void	child_second_cmd(char **av, char **envp, int *fd)
{
	int	file_out;

	file_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
	{
		error_message(av[4]);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(file_out);
	close(fd[0]);
	close(fd[1]);
	execute(av[3], envp, 1);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		status_1;
	int		status_2;

	if (ac != 5)
		return (ft_putendl_fd("Usage incorrect!", 2), EXIT_FAILURE);
	if (pipe(fd) == -1)
		error_exit("pipe");
	pid_1 = fork();
	error_pid(pid_1);
	if (pid_1 == 0)
		child_first_cmd(av, envp, fd);
	pid_2 = fork();
	error_pid(pid_2);
	if (pid_2 == 0)
		child_second_cmd(av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, &status_1, 0);
	waitpid(pid_2, &status_2, 0);
	if (WIFEXITED(status_2))
		return (WEXITSTATUS(status_2));
	return (EXIT_FAILURE);
}
