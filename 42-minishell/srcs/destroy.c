/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:35:45 by anferre           #+#    #+#             */
/*   Updated: 2024/07/02 19:27:24 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//function to free the token list and the token input 
void	ft_destroy_token(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token;
		token = token->next;
		if (tmp->input)
		{
			free(tmp->input);
			tmp->input = NULL;
		}
		if (tmp->used)
		{
			free(tmp->used);
			tmp->used = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
}

void	ft_destroy_og_cmd(t_og_cmd *og_cmd)
{
	t_og_cmd	*tmp;

	if (!og_cmd)
		return ;
	while (og_cmd)
	{
		tmp = og_cmd;
		og_cmd = og_cmd->next;
		if (tmp->token)
			ft_destroy_token(tmp->token);
		free(tmp);
		tmp = NULL;
	}
}

void	ft_destroy_node(t_node **node)
{
	if (node == NULL || *node == NULL)
		return ;
	if ((*node)->left)
		ft_destroy_node(&(*node)->left);
	if ((*node)->right)
		ft_destroy_node(&(*node)->right);
	if ((*node)->command)
	{
		ft_destroy_command((*node)->command);
		(*node)->command = NULL;
	}
	if ((*node)->operator)
	{
		free((*node)->operator);
		(*node)->operator = NULL;
	}
	free(*node);
	*node = NULL;
}

void	ft_destroy_command_2(t_command *command)
{
	int	i;

	i = 0;
	if (command->cmd)
	{
		i = 0;
		while (command->cmd[i])
		{
			free(command->cmd[i]);
			command->cmd[i] = NULL;
			i++;
		}
		free(command->cmd);
		command->cmd = NULL;
	}
}

void	ft_destroy_command(t_command *command)
{
	int	i;

	if (command)
	{
		ft_destroy_command_2(command);
		if (command->redir_dest)
		{
			free(command->redir_dest);
			command->redir_dest = NULL;
		}
		if (command->redir_type)
		{
			i = 0;
			while (command->redir_type[i])
			{
				free(command->redir_type[i]);
				command->redir_type[i] = NULL;
				i++;
			}
			free(command->redir_type);
			command->redir_type = NULL;
		}
		free(command);
	}
}

// void ft_destroy_command(t_command *command)
// {
// 	int i;

// 	if (command)
// 	{

// 		if (command->cmd)
// 		{
// 			i = 0;
// 			while (command->cmd[i])
// 			{
// 				free(command->cmd[i]);
// 				command->cmd[i] = NULL;
// 				i++;
// 			}
// 			free(command->cmd);
// 			command->cmd = NULL;
// 		}
// 		if (command->redir_dest)
// 		{
// 			free(command->redir_dest);
// 			command->redir_dest = NULL;
// 		}
// 		if (command->redir_type)
// 		{
// 			i = 0;
// 			while (command->redir_type[i])
// 			{
// 				free(command->redir_type[i]);
// 				command->redir_type[i] = NULL;
// 				i++;
// 			}
// 			free(command->redir_type);
// 			command->redir_type = NULL;
// 		}
// 		free(command);
// 	}
// }