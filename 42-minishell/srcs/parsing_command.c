/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:40:15 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 14:47:41 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// CREATE A NODE FOR THE COMMAND
t_node	*ft_create_command_node(t_token *current)
{
	t_node	*new_node;
	int		count;
	int		count_redirections;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->command = malloc(sizeof(t_command));
	if (new_node->command == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->command->redir_dest = NULL;
	new_node->command->redir_type = NULL;
	ft_count_redir_cmds(current, &count, &count_redirections);
	if (!ft_add_mem_to_redir(new_node, count, count_redirections))
	{
		ft_cleanup(new_node);
		return (NULL);
	}
	ft_fill_cmds_redir(new_node, current);
	new_node->command->path = NULL;
	new_node->operator = NULL;
	return (new_node->right = NULL, new_node->left = NULL, new_node);
}

// HANDLE THE COMMAND
t_node	*handle_command(t_token **token, t_priority_tree *priority,
	t_node **node)
{
	t_node	*new_node;

	if ((*token)->priority == 4 && *priority == 4)
	{
		new_node = ft_create_command_node(*token);
		if (new_node == NULL)
			return (NULL);
		*node = new_node;
	}
	return (*node);
}

// COUNT THE NUMBER OF COMMANDS AND REDIRECTIONS
void	ft_count_redir_cmds(t_token *current, int *count,
	int *count_redirections)
{
	t_token	*tmp;

	tmp = current;
	*count = 0;
	*count_redirections = 0;
	while (tmp != NULL)
	{
		if (tmp->type == token_word)
			(*count)++;
		else if (tmp->type >= token_left_dir && tmp->type <= token_dright_dir)
			(*count_redirections)++;
		tmp = tmp->next;
	}
}

// ADD MEMORY TO THE COMMANDS AND REDIRECTIONS
int	ft_add_mem_to_redir(t_node *new_node, int count, int count_redirections)
{
	new_node->command->cmd = malloc(sizeof(char *) * (count + 1));
	if (new_node->command->cmd == NULL)
		return (0);
	new_node->command->redir_dest = malloc(sizeof(char *)
			*(count_redirections + 1));
	if (new_node->command->redir_dest == NULL)
	{
		free(new_node->command->cmd);
		return (0);
	}
	new_node->command->redir_type = malloc(sizeof(int *)
			* (count_redirections + 1));
	if (new_node->command->redir_type == NULL)
	{
		free(new_node->command->cmd);
		free(new_node->command->redir_dest);
		return (0);
	}
	return (1);
}

// FILL THE COMMANDS AND REDIRECTIONS
void	ft_fill_cmds_redir(t_node *new_node, t_token *current)
{
	t_token	*tmp;
	int		i;
	int		j;

	tmp = current;
	i = 0;
	j = 0;
	while (tmp != NULL)
	{
		if (tmp->type == token_word && (tmp->prev == NULL || \
			(tmp->prev->type < 4 || tmp->prev->type > 7)))
			new_node->command->cmd[i++] = ft_strdup(tmp->input);
		else if (tmp->type >= token_left_dir && tmp->type <= token_dright_dir)
		{
			new_node->command->redir_dest[j] = tmp->next->input;
			new_node->command->redir_type[j] = malloc(sizeof(int));
			if (new_node->command->redir_type[j] == NULL)
				return ;
			*new_node->command->redir_type[j++] = tmp->type;
		}
		tmp = tmp->next;
	}
	new_node->command->cmd[i] = NULL;
	new_node->command->redir_dest[j] = NULL;
	new_node->command->redir_type[j] = NULL;
}
