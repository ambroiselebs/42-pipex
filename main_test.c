/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:43:02 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/22 13:28:41 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* int	main(void)
{
	int		pipefd[2];
	char	buffer[13];

	pipe(pipefd);
	if (fork() == 0)
	{
		close(pipefd[0]);
		write(pipefd[1], "Hello world!", 12);
		close(pipefd[1]);
	}
	else
	{
		close(pipefd[1]);
		read(pipefd[0], buffer, 12);
		buffer[12] = '\0';
		ft_printf("%s\n", buffer);
		close(pipefd[0]);
	}
	return (0);
} */

/* int	main(void)
{
	int	fd;

	fd = open("fin.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd, STDOUT_FILENO);
	ft_printf("ton pere");
	close(fd);
	return (0);
} */

/* int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;

	char	*args[] = {"/bin/ls", "-l", NULL};
	int		fd;

	fd = open("fin.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd, STDOUT_FILENO);
	execve(args[0], args, envp);
	close(fd);
	return (0);
} */

/* int	main(int argc, char **argv, char **envp)
{
	char	*args_ls[] = {"/bin/ls", "-l", NULL};
	char	*args_grep[] = {"/bin/grep", "pipex", NULL};
	int		pipefd[2];
	int		pid;

	(void) argc;
	(void) argv;
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execve(args_ls[0], args_ls, envp);
		return (1);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		execve(args_grep[0], args_grep, envp);
		return (1);
	}
	return (0);
} */

int	main(int c, char **v, char **env)
{
	char	*path;
	(void) c;
	(void) v;

	path = get_path_var("grep", env);
	ft_printf("%s\n", path);
	free(path);
}
