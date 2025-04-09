/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:26:39 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 14:47:41 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_if_built_in(char *cmd)
{
	int		i;
	char	**built_in_cmds;

	built_in_cmds = get_built_in_cmds();
	if (built_in_cmds == NULL)
		return (0);
	i = 0;
	while (built_in_cmds[i])
	{
		if (ft_strcmp(cmd, built_in_cmds[i]) == 0)
		{
			free(built_in_cmds);
			return (1);
		}
		i++;
	}
	free(built_in_cmds);
	return (0);
}

char	**get_built_in_cmds(void)
{
	char	**built_in_cmds;

	built_in_cmds = malloc(sizeof(char *) * 8);
	if (built_in_cmds == NULL)
		return (NULL);
	built_in_cmds[0] = "echo";
	built_in_cmds[1] = "cd";
	built_in_cmds[2] = "unset";
	built_in_cmds[3] = "export";
	built_in_cmds[4] = "env";
	built_in_cmds[5] = "exit";
	built_in_cmds[6] = "pwd";
	built_in_cmds[7] = NULL;
	return (built_in_cmds);
}

int	ft_do_built_in(char **cmd, t_mini *mini, t_bool is_pipe)
{
	int	exit;

	exit = 0;
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (exit = ft_echo(cmd));
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (exit = ft_cd(cmd, mini));
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (exit = ft_unset(cmd, mini));
	else if (ft_strcmp(cmd[0], "export") == 0)
		return (exit = ft_export(cmd, mini));
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (exit = ft_env(cmd, mini, 0));
	else if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd, mini, is_pipe);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (exit = ft_pwd(cmd));
	return (EXIT_FAILURE);
}
