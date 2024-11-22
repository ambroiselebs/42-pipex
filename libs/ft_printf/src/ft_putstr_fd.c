/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:13:14 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/15 02:45:15 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr_fd_printf(const char *str, int fd)
{
	int	counter;

	counter = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (str[counter])
		write(fd, &str[counter++], 1);
	return (counter);
}
