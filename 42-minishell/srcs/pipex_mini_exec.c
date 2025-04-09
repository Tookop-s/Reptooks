/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mini_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:49:23 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:19:27 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_retreive_hd(t_command *command, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (command->redir_type[i] != NULL)
	{
		if (*(command->redir_type[i]) == token_here_doc)
		{
			if (ft_here_doc(command->redir_dest[i], mini, j++) == -1)
			{
				ft_free_all_pipex(mini);
				free_mini_childs(mini, NULL);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	return ;
}

int	ft_child_redir(t_command *command, t_mini *mini)
{
	ft_retreive_hd(command, mini);
	if (ft_redirect_pipes(mini, mini->cmd->p_fd) == EXIT_FAILURE)
	{
		ft_free_all_pipex(mini);
		free_mini_childs(mini, NULL);
		exit(1);
	}
	if (ft_redir_files(command, mini) == EXIT_FAILURE)
	{
		ft_free_all_pipex(mini);
		free_mini_childs(mini, NULL);
		exit(1);
	}
	return (0);
}

void	ft_exit_child(t_mini *mini, char *tmp, t_command *command)
{
	int	tmp_exit;

	tmp_exit = mini->last_exit;
	free(tmp);
	free(command->cmd[1]);
	ft_free_all_pipex(mini);
	free_mini_childs(mini, NULL);
	exit(tmp_exit);
}

int	ft_pipex_childs(char **env, t_command *command, t_mini *mini)
{
	char	*tmp;
	char	**dtmp;
	char	**env_tmp;

	ft_child_redir(command, mini);
	tmp = command->cmd[0];
	command->cmd[0] = ft_prepare_cmd(command->cmd, mini, true);
	ft_c_fd(mini->cmd->p_fd[(*(mini->cmd->i) + 1) % 2], \
	mini->cmd->p_fd[*(mini->cmd->i) % 2], mini->cmd->std_fd);
	if (command->cmd[0] == NULL)
		ft_exit_child(mini, tmp, command);
	dtmp = ft_copy_dstr(command->cmd);
	env_tmp = ft_copy_dstr(env);
	close(mini->stdin_copy);
	close(mini->stdout_copy);
	execve(dtmp[0], dtmp, env_tmp);
	perror("execve");
	ft_free_all_pipex(mini);
	free_mini(mini, NULL);
	free(mini);
	free(tmp);
	ft_destroy_char_d(dtmp);
	ft_destroy_char_d(env_tmp);
	exit(errno);
}

int	ft_pipex_parent(t_mini *mini)
{
	if (dup2(mini->cmd->std_fd[0], STDIN_FILENO) == -1)
		return (ft_c_fd(mini->cmd->p_fd[0], mini->cmd->p_fd[1], \
		mini->cmd->std_fd), -1);
		return (ft_c_fd(mini->cmd->p_fd[0], mini->cmd->p_fd[1], \
		mini->cmd->std_fd), -1);
	if (dup2(mini->cmd->std_fd[1], STDOUT_FILENO) == -1)
		return (ft_c_fd(mini->cmd->p_fd[0], mini->cmd->p_fd[1], \
		mini->cmd->std_fd), -1);
		return (ft_c_fd(mini->cmd->p_fd[0], mini->cmd->p_fd[1], \
		mini->cmd->std_fd), -1);
	close(mini->cmd->p_fd[*(mini->cmd->i) % 2][1]);
	close(mini->cmd->p_fd[*(mini->cmd->i) % 2][0]);
	if (*(mini->cmd->i) < mini->cmd->nb_cmd - 1)
	{
		if (pipe(mini->cmd->p_fd[*(mini->cmd->i) % 2]) == -1)
		{
			ft_c_fd(mini->cmd->p_fd[(*(mini->cmd->i) + 1) % 2], \
			NULL, mini->cmd->std_fd);
			ft_c_fd(mini->cmd->p_fd[(*(mini->cmd->i) + 1) % 2], \
			NULL, mini->cmd->std_fd);
			return (perror("pipe"), -1);
		}
	}
	return (0);
}
