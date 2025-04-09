/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:29:58 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/04 14:16:39 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_env(char **env, char *cmd)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	path = NULL;
	if (ft_strcmp(cmd, "") == 0)
		return (ft_error(NULL, cmd, " : command not found"), NULL);
	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		return (NULL);
	while (env[i] && tmp)
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = ft_find_in_env(env[i], tmp);
			if (path)
				return (free(tmp), path);
			else
				return (ft_error(NULL, tmp, " : command not found"), free(tmp), NULL);
		}
		i++;
	}
	return (ft_error(NULL , tmp, ": No such file or directory"), free(tmp), NULL);
}

char	*ft_find_in_env(char *env, char *cmd)
{
	char	**temp;
	char	*path;
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	temp = ft_split(env, ':');
	if (!temp)
		return (NULL);
	while (temp[i])
	{
		path = ft_strjoin(temp[i], cmd);
		if (access(path, X_OK) == 0)
			return (ft_free_str(temp), path);
		free (path);
		i++;
	}
	ft_free_str(temp);
	return (NULL);
}
