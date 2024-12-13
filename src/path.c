/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 00:30:05 by aberenge          #+#    #+#             */
/*   Updated: 2024-12-13 00:30:05 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_get_var(char *name, char **env)
{
	int		i;
	int		j;
	char	*i_name;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=' && env[i][j])
			j++;
		i_name = ft_substr(env[i], 0, j);
		if (ft_strncmp(i_name, name, ft_strlen(name)) == 0)
		{
			free(i_name);
			return (env[i] + j + 1);
		}
		free(i_name);
		i++;
	}
	return (NULL);
}

char	**parse_path(char **env)
{
	char	*all_path;
	char	**path;

	all_path = ft_get_var("PATH", env);
	if (!all_path)
		return (ft_printf("pipex: PATH environement variable not found\n"), NULL);
	path = ft_split(all_path, ':');
	if (!path)
		return (ft_printf("pipex: Failed to parse PATH"), NULL);
	return (path);
}

char	*get_path_var(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*cmd_base;
	char	*cmd_path;

	path = parse_path(env);
	if (!path)
		return (NULL);
	i = -1;
	while (path[++i])
	{
		cmd_base = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(cmd_base, cmd);
		free(cmd_base);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			ft_free_tab(path);
			return (cmd_path);
		}
		free(cmd_path);
	}
	ft_printf("pipex: Command not found");
	ft_free_tab(path);
	return (NULL);
}

int	check_cmd(char *cmd, char **env)
{
	char	**cmd_name;
	char	*cmd_path;

	cmd_name = ft_split(cmd, ' ');
	if (!cmd_name)
		return (0);
	cmd_path = get_path_var(cmd_name[0], env);
	free(cmd_name);
	if (!cmd_path)
		return (0);
	free(cmd_path);
	return (1);
}
