/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:40:25 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 14:47:41 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// CREATE A NODE FOR THE OPERATOR (&&, ||, |)
t_node	*ft_create_operator_node(t_token **token, t_priority_tree *priority,
	t_node **node)
{
	t_node	*new_node;

	if ((*token)->priority == *priority && ((*token)->priority == 1
			|| (*token)->priority == 2) && *(*token)->used == 0)
	{
		*(*token)->used = 1;
		new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
			return (NULL);
		new_node->operator = malloc(sizeof(t_token));
		if (new_node->operator == NULL)
		{
			free(new_node);
			return (NULL);
		}
		*(new_node->operator) = **token;
		new_node->command = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
		if (*node != NULL)
			new_node->left = *node;
		*node = new_node;
	}
	return (*node);
}

// HANDLE THE OPERATOR (&&, ||, |)
t_node	*handle_and_or_pipe(t_token **token, t_priority_tree *priority,
	t_node **node)
{
	t_token	*left_tokens;
	t_token	*right_tokens;

	*node = ft_create_operator_node(token, priority, node);
	if (*node == NULL)
		return (NULL);
	if ((*token)->prev != NULL)
	{
		left_tokens = ft_give_me_left((*token)->prev);
		(*node)->left = build_tree(&left_tokens, *priority);
		free_token_list(left_tokens);
	}
	if ((*token)->next != NULL)
	{
		right_tokens = (*token)->next;
		(*node)->right = build_tree(&right_tokens, *priority);
	}
	return (*node);
}

// HANDLE THE PARENTHESIS
t_node	*handle_parenthesis(t_token **token, t_priority_tree *priority,
	t_node **node)
{
	t_token	*sub_tokens;
	t_node	*sub_tree;

	if ((*token)->type == token_left_par && *priority == 3
		&& *(*token)->used == 0)
	{
		sub_tokens = ft_using_parrenthesis(*token);
		if (sub_tokens == NULL)
			return (NULL);
		sub_tree = build_tree(&sub_tokens, 1);
		if (sub_tree == NULL)
			return (NULL);
		if (*node == NULL)
			*node = sub_tree;
		else
		{
			if ((*node)->left == NULL)
				(*node)->left = sub_tree;
			else if ((*node)->right == NULL)
				(*node)->right = sub_tree;
		}
	}
	return (*node);
}
