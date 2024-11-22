/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:40:14 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/15 02:45:46 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
void	ft_parser(char c, int *counter, va_list *args);

int		ft_print_hex_fd_maj(int nb, int fd);
int		ft_print_hex_fd_min(int nb, int fd);
int		ft_putchar_fd_printf(char c, int fd);
int		ft_putnbr_fd_printf(int nb, int fd);
int		ft_putstr_fd_printf(const char *str, int fd);
int		ft_print_pointer(unsigned long long addr, int fd);
int		ft_putnbr_unsigned_fd(unsigned int n, int fd);

#endif
