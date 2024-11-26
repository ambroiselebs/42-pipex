/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:09:03 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/26 14:39:36 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **env)
{
	char	**arg_cmd;
	char	*path;

	arg_cmd = ft_split(cmd, ' ');
	path = get_path_var(arg_cmd[0], env);
	if (!path)
	{
		ft_printf("pipex : %s\n Command not found\n", arg_cmd[0]);
		free_tabs(arg_cmd);
		exit(1);
	}
	if (execve(path, arg_cmd, env) == -1)
	{
		perror("pipex");
		free(path);
		free_tabs(arg_cmd);
		exit(EXIT_FAILURE);
	}
}

void	child(char **argv, int pipefd[2], char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	exec_cmd(argv[2], env);
}

void	parent(char **argv, int pipefd[2], char **env)
{
	int	fd;

	fd = open_file(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	exec_cmd(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	check_args(argc, argv);
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
		child(argv, pipefd, env);
	else
		parent(argv, pipefd, env);
	return (0);
}
