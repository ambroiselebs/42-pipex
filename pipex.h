/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:43:38 by aberenge          #+#    #+#             */
/*   Updated: 2024/12/03 16:53:59 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"
# include <sys/wait.h>

void	check_args(int argc, char **argv);
void	free_tabs(char **tab);
char	*ft_get_env(char *name, char **env);
char	*get_path_var(char *cmd, char **env);
int		open_file(char *path, int mode);
void	exit_handler(int n_exit);

#endif
