/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:09:03 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/04 14:03:46 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <limits.h>
#include <dirent.h>

void	close_all_unused_fds(void)
{
	int	fd;

	fd = 2;
	while (++fd < 1024)
	{
		if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO)
			close(fd);
	}
}

void	exec_cmd(char *cmd, char **env)
{
	char	**arg_cmd;
	char	*path;

	arg_cmd = ft_split(cmd, ' ');
	path = get_path_var(arg_cmd[0], env);
	close_all_unused_fds();
	if (execve(path, arg_cmd, env) == -1)
	{
		perror("pipex: ");
		free_tabs(arg_cmd);
		exit(EXIT_FAILURE);
	}
}

void	child(char **argv, int pipefd[2], char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	if (fd == -1)
	{
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	exec_cmd(argv[2], env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	parent(char **argv, int pipefd[2], char **env)
{
	int	fd;

	fd = open_file(argv[4], 1);
	if (fd == -1)
	{
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	exec_cmd(argv[3], env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	check_args(argc, argv);
	if (pipe(pipefd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(argv, pipefd, env);
	parent(argv, pipefd, env);
}
