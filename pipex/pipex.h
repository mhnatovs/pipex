/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:25:57 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/12 16:21:06 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <string.h>
# include <stdlib.h>

void	parent_process(char **av, char **envp, int *fd);
void	child_process(char **av, char **envp, int *fd);
int		main(int ac, char **av, char **envp);
char	*find_path(char *cmd, char **envp);
void	execute(char *cmd_str, char **envp, int is_last_cmd);
char	*ft_strjoin_free(char *s1, char *s2);
void	free_split(char **arr);
char	**smart_split(char *str);
int		ft_isspace(int c);
void	error_message(char *context);
void	error_exit(char *context);
void	error_execve(char *path, char **cmd);
void	error_path(char **cmd, int is_last_cmd);
void	error_pid(pid_t pid);
void print_command_not_found(char *cmd);

#endif