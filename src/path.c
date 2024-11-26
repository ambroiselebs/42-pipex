/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:13:02 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/26 14:35:51 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*var_name;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=' && env[i][j])
			j++;
		var_name = ft_substr(env[i], 0, j);
		if (ft_strncmp(var_name, name, ft_strlen(name)) == 0)
		{
			free(var_name);
			return (env[i] + j + 1);
		}
		free(var_name);
		i++;
	}
	return (NULL);
}

char	**parse_path(char **env)
{
	char	*path_str;
	char	**pathes;

	path_str = ft_get_env("PATH", env);
	if (!path_str)
	{
		ft_printf("Error: PATH environment variable not found\n");
		return (NULL);
	}
	pathes = ft_split(path_str, ':');
	if (!pathes)
	{
		ft_printf("Error: Parsing PATH\n");
		return (NULL);
	}
	return (pathes);
}

char	*get_path_var(char *cmd, char **env)
{
	int		i;
	char	**pathes;
	char	*path_base;
	char	*cmd_path;

	pathes = parse_path(env);
	if (!pathes)
		return (NULL);
	i = -1;
	while (pathes[++i])
	{
		path_base = ft_strjoin(pathes[i], "/");
		cmd_path = ft_strjoin(path_base, cmd);
		free(path_base);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_tabs(pathes);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_tabs(pathes);
	ft_printf("Error: Command '%s' not found\n", cmd);
	return (NULL);
}
