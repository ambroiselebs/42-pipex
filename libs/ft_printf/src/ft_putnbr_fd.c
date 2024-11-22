/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:34:02 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/15 02:46:53 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_fd_printf(int nb, int fd)
{
	int		counter;
	char	c;

	counter = 0;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
		counter++;
	}
	if (nb >= 10)
	{
		counter += ft_putnbr_fd_printf(nb / 10, fd);
	}
	c = (nb % 10) + '0';
	write(fd, &c, 1);
	counter++;
	return (counter);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int	counter;

	counter = 0;
	if (n >= 10)
		counter += ft_putnbr_unsigned_fd(n / 10, fd);
	ft_putchar_fd_printf((n % 10) + '0', fd);
	counter++;
	return (counter);
}
