/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:30:39 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/16 15:44:39 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **env)
{
	char	**arg_cmd;
	char	*path;

	arg_cmd = ft_split(cmd, ' ');
	if (!arg_cmd || !arg_cmd[0])
	{
		ft_printf("pipex: Error splitting command or empty command\n");
		ft_free_tab(arg_cmd);
		exit(EXIT_FAILURE);
	}
	path = get_path_var(arg_cmd[0], env);
	if (!path)
	{
		perror("pipex: Unknown command");
		ft_free_tab(arg_cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, arg_cmd, env) == -1)
	{
		(perror("pipex"), ft_free_tab(arg_cmd));
		free(path);
		exit(EXIT_FAILURE);
	}
	ft_free_tab(arg_cmd);
	free(path);
}

void	child(char **argv, char **env, int pipefd[2])
{
	int		fd;

	close(pipefd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("pipex: infile");
		close(pipefd[1]);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	exec_cmd(argv[2], env);
	exit(EXIT_FAILURE);
}

void	parent(char **argv, char **env, int pipefd[2])
{
	int		fd;

	close(pipefd[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("pipex: outfile");
		close(pipefd[0]);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	exec_cmd(argv[3], env);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (argc != 5)
		return (ft_printf("pipex: ./pipex infile cmd1 cmd2 outfile\n"), 1);
	if (pipe(pipefd) == -1)
	{
		perror("pipex: pipe");
		return (1);
	}
	pid = fork();
	if (pid == -1)
		return (perror("pipex: fork"), 1);
	if (pid == 0)
		child(argv, env, pipefd);
	else
	{
		waitpid(pid, &status, 0);
		parent(argv, env, pipefd);
	}
	return (0);
}
