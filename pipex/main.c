/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:01:43 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/12 15:53:53 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **av, char **envp, int *fd)
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

void	parent_process(char **av, char **envp, int *fd)
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
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (ac != 5)
		return (ft_putendl_fd("usage incorrect", 2), EXIT_FAILURE);
	if (pipe(fd) == -1)
		error_exit("pipe");
	pid1 = fork();
	error_pid(pid1);
	if (pid1 == 0)
		child_process(av, envp, fd);
	pid2 = fork();
	error_pid(pid2);
	if (pid2 == 0)
		parent_process(av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (EXIT_FAILURE);
}

/*
< infile grep Hello | wc -l > outshell
./pipex infile "grep Hello" "wc -l" outfile

./pipex in "cat" "hostname" out
< in cat | hostname > out

< input grep Hello | ls -l src/ > output
./pipex infile "grep Hello" "ls -l src/" outfile

< input ls -l src/ | wc -l > output
< input grep Hello | awk '{count++} END {print count}' > output
< input grep Hello | awk "{count++} END {print count}" > output
smart_split("head -1") → ["head", "-1"]
smart_split("awk '{print $1}'") → ["awk", "{print $1}"]
smart_split("echo \"Hello World\"") → ["echo", "Hello World"]
smart_split("grep 'some\\ value'") → ["grep", "some value"]
*/

// static void	spawn_process(void (*process)(char **, char **, int *),
// 								char **av, char **envp, int *fd)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == -1)
// 		error_exit("fork");
// 	if (pid == 0)
// 		process(av, envp, fd);
// }