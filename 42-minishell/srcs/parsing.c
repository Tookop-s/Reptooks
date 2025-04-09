/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:26:51 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 16:15:04 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// MAIN PARSING FUNCTION

void	*ft_parsing(t_og_cmd *head_c, t_mini *mini)
{
	t_og_cmd	*current;
	t_node		**root;
	int			i;
	int			cmd_count;

	cmd_count = count_cmds(head_c);
	root = malloc(sizeof(t_node *) * (cmd_count + 1));
	if (root == NULL)
		return (NULL);
	root[cmd_count] = NULL;
	i = 0;
	current = head_c;
	while (current)
	{
		root[i] = build_tree(&current->token, 1);
		if (root[i] == NULL)
		{
			printf("Error: Parsing failed\n");
			return (NULL);
		}
		current = current->next;
		i++;
	}
	mini->node = root;
	return (root);
}

// BUILD THE TREE WITH PRIORITY ORDER && || | ( ) COMMANDS
t_node	*build_tree(t_token **token, t_priority_tree priority)
{
	t_token	*current;
	t_node	*node;

	node = NULL;
	if (*token == NULL)
	{
		return (NULL);
	}
	while (priority <= 4)
	{
		current = *token;
		while (current != NULL)
		{
			node = handle_current_token(&current, &priority, &node);
			if (node != NULL)
				return (node);
		}
		priority++;
	}
	return (node);
}

// CHECK IF THE CURRENT TOKEN IS AN OPERATOR &&, ||, |, () OR A COMMAND
t_node	*handle_current_token(t_token **current, t_priority_tree *priority,
	t_node **node)
{
	if (*((*current)->used) == 1)
	{
		*current = (*current)->next;
		return (NULL);
	}
	if ((*current)->type == token_left_par && *priority != 3
		&& *(*current)->used == 0)
	{
		*current = (ft_pass_parrenthesis(*current));
		if (*current == NULL)
			return (NULL);
	}
	*node = handle_and_or_pipe(current, priority, node);
	if (*node != NULL)
		return (*node);
	*node = handle_parenthesis(current, priority, node);
	if (*node != NULL)
		return (*node);
	*node = handle_command(current, priority, node);
	if (*node != NULL)
		return (*node);
	*current = (*current)->next;
	return (NULL);
}

// la fonction commence par la priorité la plus haute qui est la 1
// priority 1 = &&, ||
// priority 2 = |
// priority 3 = ()
// priority 4 = cmds