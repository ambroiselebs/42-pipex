/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 14:55:03 by aberenge          #+#    #+#             */
/*   Updated: 2024-11-22 14:55:03 by aberenge         ###   ########.fr       */
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
