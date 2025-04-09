/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:38:06 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/03 18:42:17 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// GIVE ALL THE TOKENS TO THE LEFT UNTIL THE FIRST USED TOKEN
t_token	*ft_give_me_left(t_token *current)
{
	t_token	*head;
	t_token	*new_token;

	head = NULL;
	while (current != NULL && *current->used == 0)
	{
		new_token = malloc(sizeof(t_token));
		if (new_token == NULL)
			return (NULL);
		if (current != NULL)
		{
			*new_token = *current;
			new_token->next = head;
			head = new_token;
		}
		current = current->prev;
	}
	return (head);
}

// PASS THE PARENTHESIS
t_token	*ft_pass_parrenthesis(t_token *current)
{
	int	open_parentheses;

	open_parentheses = 0;
	while (current != NULL)
	{
		if (current->type == token_left_par)
			open_parentheses++;
		else if (current->type == token_right_par)
		{
			open_parentheses--;
			if (open_parentheses == 0)
			{
				if (current->next != NULL)
					return (current->next);
				else
					return (NULL);
			}
		}
		current = current->next;
	}
	return (NULL);
}

// MARK AS USED THE TOKENS INSIDE THE PARENTHESIS
t_token	*ft_using_parrenthesis(t_token *current)
{
	t_token	*head;
	int		open_parentheses;

	head = current;
	open_parentheses = 1;
	if (current != NULL && current->type == token_left_par)
	{
		*current->used = 1;
		current = current->next;
	}
	while (current != NULL)
	{
		if (current->type == token_left_par)
			open_parentheses++;
		else if (current->type == token_right_par && --open_parentheses == 0)
		{
			*current->used = 1;
			break ;
		}
		current = current->next;
	}
	return (head);
}

int	count_cmds(t_og_cmd *head_c)
{
	int			count;
	t_og_cmd	*current;

	count = 0;
	current = head_c;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
