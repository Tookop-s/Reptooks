/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:50:57 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 14:47:41 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec(t_node *node, t_mini *mini)
{
	int	left_result;

	left_result = 0;
	if (node == NULL)
		return (0);
	if (node->left != NULL && node->operator->type != token_pipe)
		left_result = ft_exec(node->left, mini);
	if (node->operator != NULL && left_result != -1)
	{
		if (ft_do_operator(node, left_result, mini) == 0)
			if (node->right != NULL)
				ft_exec(node->right, mini);
	}
	else if (node->command != NULL)
		mini->last_exit = execute_command(node, mini);
	return (mini->last_exit);
}

int	ft_do_operator(t_node *node, int left, t_mini *mini)
{
	if (node->operator == NULL)
		return (fprintf(stderr, "Error: NULL pointer encountered.\n"), \
		EXIT_FAILURE);
	if (node->operator->type == token_and_and)
	{
		if (left == 0)
			return (0);
		else
			return (1);
	}
	else if (node->operator->type == token_or)
	{
		if (left != 0)
			return (0);
		else
			return (1);
	}
	else if (node->operator->type == token_pipe)
	{
		mini->last_exit = ft_pipex(node, mini);
		return (1);
	}
	else
		return (1);
}

int	execute_command(t_node *node, t_mini *mini)
{
	if (node->command->redir_dest != NULL && node->command->redir_type != NULL)
		mini->last_exit = do_redir(node->command, mini);
	else
	{
		if (node->command->cmd == NULL)
		{
			fprintf(stderr, "Error: NULL pointer encountered.\n");
			return (EXIT_FAILURE);
		}
		mini->last_exit = exec_cmd(node->command->cmd, mini);
	}
	return (mini->last_exit);
}

int	do_redir(t_command *command, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mini->last_exit = 0;
	if (dup2(mini->stdin_copy, STDIN_FILENO) == -1 || \
		dup2(mini->stdout_copy, STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	if (command == NULL || mini == NULL)
		return (EXIT_FAILURE);
	if (handle_redirections(command, mini, i, j) == EXIT_FAILURE)
		mini->last_exit = EXIT_FAILURE;
	if (command->cmd != NULL && mini->last_exit == 0)
	{
		mini->last_exit = exec_cmd(command->cmd, mini);
	}
	return (mini->last_exit);
}
