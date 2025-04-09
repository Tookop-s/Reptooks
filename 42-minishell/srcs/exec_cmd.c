/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:31:54 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 16:57:15 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_cmd(char **cmd, t_mini *mini)
{
	pid_t	pid;

	if (ft_strchr(cmd[0], '/') == NULL)
	{
		if (ft_check_if_built_in(cmd[0]))
		{
			mini->last_exit = ft_do_built_in(cmd, mini, false);
			return (mini->last_exit);
		}
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
		handle_child_process(cmd, mini->env, mini);
	else if (pid > 0)
		return (handle_parent_process(pid));
	return (EXIT_SUCCESS);
}

int	handle_parent_process(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) < 0)
	{
		perror("waitpid failed");
		return (EXIT_FAILURE);
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (EXIT_FAILURE);
}

void	handle_child_process(char **cmd, char **env, t_mini *mini)
{
	char	*prep_cmd;

	prep_cmd = NULL;
	if (ft_strchr(cmd[0], '/') == NULL)
	{
		prep_cmd = ft_check_env(env, cmd[0]);
		if (prep_cmd == NULL)
		{
			free_mini_childs(mini, NULL);
			exit(127);
		}
	}
	else
	{
		if (access(cmd[0], X_OK) == -1)
		{
			if (cmd[0][0] == '.' && cmd[0][1] == '/')
				return (perror("Permission denied"), exit(126));
			else
				return (perror("Invalid executable path"), exit(127));
		}
		prep_cmd = cmd[0];
	}
	ft_child_exec_command(prep_cmd, cmd, env, mini);
}

void	ft_child_exec_command(char *prep_cmd, char \
	**cmd, char **env, t_mini *mini)
{
	close(mini->stdin_copy);
	close(mini->stdout_copy);
	execve(prep_cmd, cmd, env);
	free(prep_cmd);
	free_mini(mini, NULL);
	perror("exec failed");
	exit(EXIT_FAILURE);
}

// OK - Command n°17 'echo hola > bonjour  exit | cat -e bonjour'
// Output : hola exit$  and exit status : 0 are the same