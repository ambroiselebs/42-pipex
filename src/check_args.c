/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:09:30 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/22 13:15:15 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
