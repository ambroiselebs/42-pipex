/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-12 22:30:39 by aberenge          #+#    #+#             */
/*   Updated: 2024-12-12 22:30:39 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **env)
{
	char	**arg_cmd;
	char	*path;

	arg_cmd = ft_split(cmd, ' ');
	if (!arg_cmd)
	{
		ft_printf("pipex: Error spliting command and arguments\n");
		exit(EXIT_FAILURE);
	}
	path = get_path_var(arg_cmd[0], env);
	if (!path)
	{
		ft_printf("pipex: Failed to get command path\n");
		exit(EXIT_FAILURE);
	}
	if (execve(path, arg_cmd, env) == -1)
	{
		perror("pipex");
		ft_free_tab(arg_cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
	ft_free_tab(arg_cmd);
	free(path);
}

void	child(char **argv, char **env, int pipefd[2])
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("pipex: infile not readable");
		exit(EXIT_FAILURE);
	}
	if (!check_cmd(argv[2], env))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	close(pipefd[0]);
	//dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	exec_cmd(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 3)
		return (ft_printf("pipex: ./pipex infile cmd1 cmd2 outfile"), 1);
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
		child(argv, env, pipefd);
	else
		ft_printf("suivant");
	return (0);
}
