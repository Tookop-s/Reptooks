/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:37:54 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:20:08 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//create the pipes used by the childs 
int	ft_create_pipes(t_mini *mini, int p_fd[2][2])
{
	if (pipe(p_fd[0]) == -1)
		return (perror("pipe_1"), -1);
	if (pipe(p_fd[1]) == -1)
		return (ft_c_fd(p_fd[0], NULL, NULL), perror("pipe_2"), -1);
	mini->cmd->std_fd[0] = dup(STDIN_FILENO);
	if (mini->cmd->std_fd[0] == -1)
		return (ft_c_fd(p_fd[0], p_fd[1], NULL), perror("dup STDIN"), -1);
	mini->cmd->std_fd[1] = dup(STDOUT_FILENO);
	if (mini->cmd->std_fd[1] == -1)
	{
		close(mini->cmd->std_fd[0]);
		return (ft_c_fd(p_fd[0], p_fd[1], NULL), perror("dup_STDOUT"), -1);
	}
	return (0);
}

static int	ft_wait(t_cmd *cmd, int p_fd[2][2], pid_t *child, t_mini *mini)
{
	int		status;
	int		i;

	status = 0;
	i = 0;
	while (i < cmd->nb_cmd)
	{
		if ((waitpid(child[i], &status, 0) < 0))
		{
			return (perror("waitpid"), -1);
		}
		if (status != 0 && i == cmd->nb_cmd - 1)
		{
			if (WIFEXITED(status))
				mini->last_exit = WEXITSTATUS(status);
		}
		else
		{
			mini->last_exit = status;
		}
		status = 0;
		i++;
	}
	ft_c_fd(p_fd[i % 2], p_fd[(i + 1) % 2], cmd->std_fd);
	return (i--, 0);
}

void	*ft_newcmd(t_node *node)
{
	t_cmd	*newcmd;

	newcmd = malloc(sizeof(t_cmd));
	if (!newcmd)
		return (NULL);
	newcmd->nb_cmd = ft_count_cmd(node);
	newcmd->child = malloc(sizeof(pid_t) * newcmd->nb_cmd);
	if (!newcmd->child)
		return (NULL);
	newcmd->i = malloc(sizeof(int));
	if (!newcmd->i)
		return (NULL);
	*(newcmd->i) = 0;
	newcmd->node = node;
	return (newcmd);
}

int	ft_fork(t_mini *mini, t_node *node)
{
	while (*(mini->cmd->i) < mini->cmd->nb_cmd)
	{
		mini->cmd->child[*(mini->cmd->i)] = fork();
		if (mini->cmd->child[*(mini->cmd->i)] < 0)
			return (perror("fork"), ft_c_fd(mini->cmd->p_fd[0], \
			mini->cmd->p_fd[1], mini->cmd->std_fd), -1);
			return (perror("fork"), ft_c_fd(mini->cmd->p_fd[0], \
			mini->cmd->p_fd[1], mini->cmd->std_fd), -1);
		if (mini->cmd->child[*(mini->cmd->i)] == 0)
		{
			if (node->command)
				ft_pipex_childs(mini->env, node->command, mini);
			else
				ft_pipex_childs(mini->env, node->left->command, mini);
			return (-1);
		}
		if (mini->cmd->child[*(mini->cmd->i)] > 0)
			if (ft_pipex_parent(mini) != 0)
				return (-1);
		node = node->right;
		(*(mini->cmd->i))++;
	}
	return (0);
}

int	ft_pipex(t_node *node, t_mini *mini)
{
	g_got_signal = 1;
	mini->cmd = ft_newcmd(node);
	mini->is_pipe = 1;
	if (!mini->cmd)
		return (-1);
	if (ft_create_pipes(mini, mini->cmd->p_fd) < 0)
		return (-1);
	if (ft_fork(mini, node) < 0)
		return (-1);
	if ((ft_wait(mini->cmd, mini->cmd->p_fd, mini->cmd->child, mini)) == -1)
	{
		return (-1);
	}
	ft_free_all_pipex(mini);
	g_got_signal = 0;
	mini->is_pipe = 0;
	return (mini->last_exit);
}
