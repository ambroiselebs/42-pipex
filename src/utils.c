/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:55:03 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/26 13:47:29 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tabs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	check_args(int argc, char **argv)
{
	if (argc != 5)
		exit(EXIT_FAILURE);
	if (access(argv[1], F_OK) != 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

int	open_file(char *path, int mode)
{
	int	res;

	if (mode == 0)
		res = open(path, O_RDONLY);
	if (mode == 1)
		res = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (res == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (res);
}
