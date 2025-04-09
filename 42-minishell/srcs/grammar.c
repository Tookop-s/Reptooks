/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:45:15 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:18:37 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_start_token(t_token_type type, int *par_count)
{
	if (type == token_word)
		return (0);
	else if (type == token_left_par)
		return ((*par_count)++, 0);
	else if (type == token_left_dir || type == token_right_dir)
		return (0);
	else if (type == token_here_doc || type == token_dright_dir)
		return (0);
	return (1);
}

static int	ft_end_token(t_token *token, int *par_count)
{
	if (token->type == token_word)
		return (0);
	else if (token->type == token_right_par)
		return ((*par_count)--, 0);
	return (1);
}

void	ft_syntax_error(t_token *token, t_token *next)
{
	if (next == NULL && token->prev && !ft_islogic(token->prev) && \
	(ft_islogic(token)))
		ft_error("syntax error: ", NULL, "unexpected end of file");
	else
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		if ((!token->next && (ft_isredir(token) && token->prev && \
		token->prev->type == token_word)) || (!token->next && ft_isredir(token) \
		&& !token->prev) || (ft_isredir(token) && token->prev && \
		ft_islogic(token->prev) && token->prev->prev))
			ft_putstr_fd("newline", 2);
		else if (ft_token_error(token))
			ft_putstr_fd(token->input, 2);
		else if ((ft_islogic(token) && token->prev && ft_islogic(token->prev) \
		&& !token->prev->prev) || (ft_islogic(token) && token->prev && \
		token->prev->type == token_right_par) || ((ft_isredir(token) || \
		ft_ispar(token)) && token->prev && ft_islogic(token->prev)) || \
		(ft_isredir(token) && token->prev && \
		token->prev->type == token_right_par) || (token->type == token_left_par \
		&& token->prev && token->prev->type == token_right_par) || \
		(ft_isredir(token) && token->prev && \
		token->prev->type == token_right_par))
			ft_putstr_fd(token->prev->input, 2);
		ft_putstr_fd("'\n", 2);
	}
}

static void	*ft_grammar_check(t_token *tokens)
{
	t_token	*prev;
	t_token	*head;
	int		par_count;

	prev = tokens;
	head = tokens;
	par_count = 0;
	if (ft_start_token(tokens->type, &par_count) == 0)
	{
		tokens = tokens->next;
		tokens = ft_syntax(tokens, prev, &par_count);
		if (tokens == NULL)
			return (ft_destroy_token(head), NULL);
		if (tokens->prev)
			prev = tokens->prev;
		if (ft_end_token(tokens, &par_count) == 0)
			if (par_count == 0)
				return (head);
	}
	if (tokens != prev)
		return (ft_syntax_error(tokens, tokens->next), \
		ft_destroy_token(head), NULL);
	return (ft_syntax_error(tokens, tokens->next), \
	ft_destroy_token(head), NULL);
}

void	*ft_grammar(t_og_cmd *head_c, t_mini *mini)
{
	t_og_cmd	*current;

	current = head_c;
	while (current != NULL)
	{
		if (current->token == NULL)
			return (free(head_c), mini->last_exit = 2, NULL);
		else if (current->token->next == NULL && \
		current->token->type == token_word)
		{
			current = current->next;
			continue ;
		}
		else if (current->token->next == NULL)
			return (ft_syntax_error(current->token, NULL), \
			ft_destroy_token(current->token), mini->last_exit = 2, NULL);
		current->token = ft_grammar_check(current->token);
		if (current->token == NULL)
			return (free(head_c), mini->last_exit = 2, NULL);
		current = current->next;
	}
	return (head_c);
}
