/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mini_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:48:00 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:05:05 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *str1, char *str2, char *str3)
{
	write(2, "Minishell: ", 12);
	if (str1)
		write(2, str1, ft_strlen(str1));
	if (str2 && &str2[1] && str2[0] != '\n')
		write(2, &str2[1], ft_strlen(&str2[1]));
	if (str3)
		write(2, str3, ft_strlen(str3));
	write(2, "\n", 1);
}

void	ft_c_fd(int *pipe_fd1, int *pipe_fd2, int std_fd[2])
{
	if (std_fd)
	{
		close(std_fd[0]);
		close(std_fd[1]);
	}
	if (pipe_fd1)
	{
		close(pipe_fd1[1]);
		close(pipe_fd1[0]);
	}
	if (pipe_fd2)
	{
		close(pipe_fd2[1]);
		close(pipe_fd2[0]);
	}
}

void	ft_free_all_pipex(t_mini *mini)
{
	ft_c_fd(mini->cmd->p_fd[0], mini->cmd->p_fd[1], mini->cmd->std_fd);
	free(mini->cmd->child);
	free(mini->cmd->i);
	free(mini->cmd);
}

char	*ft_prepare_cmd(char **cmd, t_mini *mini, t_bool is_pipe)
{
	char	*prepared_cmd;

	if (ft_strchr(cmd[0], '/') == NULL)
	{
		if (ft_check_if_built_in(cmd[0]))
		{
			if (ft_do_built_in(cmd, mini, is_pipe) == EXIT_FAILURE)
				return (mini->last_exit = EXIT_FAILURE, NULL);
			else
				return (mini->last_exit = EXIT_SUCCESS, NULL);
		}
		prepared_cmd = ft_check_env(mini->env, cmd[0]);
		if (prepared_cmd == NULL)
			return (mini->last_exit = 127, NULL);
		return (prepared_cmd);
	}
	else
	{
		if (access(cmd[0], X_OK) == -1)
		{
			perror("Invalid executable path");
			return (mini->last_exit = EXIT_FAILURE, NULL);
		}
		return (cmd[0]);
	}
}

//count the number of command in the pipeline 
int	ft_count_cmd(t_node *node)
{
	int		count;
	t_node	*tmp;

	count = 1;
	tmp = node;
	while (tmp->operator && tmp->operator->type == token_pipe)
	{
		count++;
		tmp = tmp->right;
	}
	return (count);
}
