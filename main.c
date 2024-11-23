/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:09:03 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/23 10:46:29 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	check_args(argc, argv);
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{

	} else
	{

	}
	return (0);
}
