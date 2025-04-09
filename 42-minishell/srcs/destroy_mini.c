/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:16:03 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 14:47:41 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_mini_d_quit(t_mini *mini, char *input)
{
	if (mini)
	{
		if (mini->heredoc && mini->heredoc->heredoc_paths)
			free(mini->heredoc->heredoc_paths);
		if (mini->heredoc)
			free(mini->heredoc);
		if (mini->env)
			ft_destroy_env(mini->env);
		free(mini);
	}
	if (input)
		free(input);
}

void	free_mini_og_cmd(t_mini *mini, char *input)
{
	if (mini)
	{
		if (mini->og_cmd)
			ft_destroy_og_cmd(mini->og_cmd);
		if (mini->heredoc->heredoc_paths)
			ft_destroy_char_d(mini->heredoc->heredoc_paths);
		if (mini->heredoc)
			free(mini->heredoc);
		if (mini->env)
			ft_destroy_env(mini->env);
		if (input)
			free(input);
	}
}

void	free_mini_loop(t_mini *mini)
{
	if (mini)
	{
		if (mini->og_cmd)
			ft_destroy_og_cmd(mini->og_cmd);
		if (mini->node)
		{
			ft_destroy_node(mini->node);
			free(mini->node);
		}
		if (mini->heredoc->heredoc_paths)
			ft_destroy_char_d(mini->heredoc->heredoc_paths);
	}
}

void	free_mini(t_mini *mini, char *input)
{
	if (mini)
	{
		if (mini->og_cmd)
			ft_destroy_og_cmd(mini->og_cmd);
		if (mini->node)
		{
			ft_destroy_node(mini->node);
			free(mini->node);
		}
		if (mini->heredoc->heredoc_paths)
			ft_destroy_char_d(mini->heredoc->heredoc_paths);
		if (mini->heredoc)
			free(mini->heredoc);
		if (mini->env)
			ft_destroy_env(mini->env);
		if (input)
			free(input);
	}
}

void	free_mini_childs(t_mini *mini, char *input)
{
	if (mini)
	{
		if (mini->og_cmd)
			ft_destroy_og_cmd(mini->og_cmd);
		if (mini->node)
		{
			ft_destroy_node(mini->node);
			free(mini->node);
		}
		if (mini->heredoc->heredoc_paths)
			ft_destroy_char_d(mini->heredoc->heredoc_paths);
		if (mini->heredoc)
			free(mini->heredoc);
		if (mini->env)
			ft_destroy_env(mini->env);
		close(mini->stdin_copy);
		close(mini->stdout_copy);
		if (input)
			free(input);
		free(mini);
	}
}
