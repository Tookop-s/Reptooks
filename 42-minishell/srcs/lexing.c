/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:52:19 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/04 14:19:02 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//adds a new token to the token list
void	*ft_lst_new_back(t_token *token)
{
	t_token	*tmp;
	int		*used;

	tmp = malloc(sizeof(t_token));
	if (!tmp)
		return (NULL);
	used = malloc(sizeof(int));
	if (!used)
		return (free(tmp), NULL);
	*used = 0;
	tmp->next = NULL;
	tmp->input = NULL;
	tmp->used = used;
	tmp->type = none;
	tmp->priority = wrong;
	tmp->prev = token;
	if (token != NULL)
		token->next = tmp;
	return (tmp);
}

//returns the splited input
char	*ft_copy_input(char *input, int i, int len)
{
	while (input[i] == ' ' || input[i] == '\t')
		i++;
	return (ft_substr(input, i, (len - i)));
}

t_token	*ft_pass_alloc(char **input, int len, t_token *token, t_mini *mini)
{
	while (len-- > 0)
		(*input)++;
	while (**input == ' ' || **input == '\t')
		(*input)++;
	if (**input != '\0')
	{
		token = ft_lst_new_back(token);
		if (token == NULL)
			return (ft_destroy_token(mini->token), NULL);
	}
	return (token);
}

void	*ft_og_cmd(t_token *head_t)
{
	t_og_cmd	*current;

	current = malloc(sizeof(t_og_cmd));
	if (!current)
		return (ft_destroy_token(head_t), NULL);
	current->next = NULL;
	current->token = head_t;
	return (current);
}
}

//identifies the tokens and build the list of tokens
void	*ft_lexing(char *input, t_mini *mini)
{
	t_token		*token;
	int			len;
	int			i;

	token = ft_lst_new_back(NULL);
	if (token == NULL)
		return (NULL);
	mini->token = token;
	while (*input)
	{
		i = 0;
		len = ft_locate_token(input, token, i);
		if (len == -1)
			return (ft_destroy_token(mini->token), NULL);
		token->input = ft_copy_input(input, i, len);
		if (token->input == NULL)
			return (ft_destroy_token(mini->token), NULL);
		token = ft_pass_alloc(&input, len, token, mini);
		if (token == NULL)
			return (NULL);
	}
	mini->og_cmd = ft_og_cmd(mini->token);
	return (mini->og_cmd);
}
