/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:11:54 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:18:50 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_quotes(t_token *token, char *input, size_t i)
{
	if (input[i] == '"')
	{
		i++;
		while (input[i] && input[i] != '"')
			i++;
		while (input[i] && input[i] != ' ' && input[i] != '\t' && \
		input[i] != '\n')
		while (input[i] && input[i] != ' ' && input[i] != '\t' && \
		input[i] != '\n')
			i++;
		return (token->type = token_word, token->priority = prio_cmds, i);
	}
	if (input[i] == '\'')
	{
		i++;
		while (input[i] && input[i] != '\'')
			i++;
		while (input[i] && input[i] != ' ' && input[i] != '\t' && \
		input[i] != '\n')
		while (input[i] && input[i] != ' ' && input[i] != '\t' && \
		input[i] != '\n')
			i++;
		return (token->type = token_word, token->priority = prio_cmds, i);
	}
	return (i);
}

static int	ft_pipe_or_and(t_token *token, size_t len, char *input, size_t i)
{
	if (i > 0)
		return (token->type = token_word, token->priority = prio_cmds, i);
	if (input[i] == '|')
	{
		if ((i + 1) < len && input[i + 1] == '|')
		{
			token->type = token_or;
			token->priority = prio_and_or;
			i += 1;
		}
		else
		{
			token->type = token_pipe;
			token->priority = prio_piped;
		}
		return (i + 1);
	}
	if (input[i] == '&' && (i + 1) < len && input[i + 1] == '&')
	{
		token->type = token_and_and;
		return (token->priority = prio_and_or, i + 2);
	}
	return (i);
}

static int	ft_par_nl(t_token *token, char *input, size_t i)
{
	if (input[i] == '(')
	{
		if (i > 0)
			return (token->type = token_word, token->priority = prio_cmds, i);
		token->type = token_left_par;
		return (token->priority = prio_parrenthesis, i + 1);
	}
	if (input[i] == ')')
	{
		if (i > 0)
			return (token->type = token_word, token->priority = prio_cmds, i);
		token->type = token_right_par;
		return (token->priority = prio_parrenthesis, i + 1);
	}
	if (input[i] == '\n')
	{
		if (i > 0)
			return (token->type = token_word, token->priority = prio_cmds, i);
		return (token->type = token_newline, i + 1);
	}
	return (i);
}

static int	ft_redir(t_token *token, size_t len, char *input, size_t i)
{
	if (i > 0)
		return (token->type = token_word, token->priority = prio_cmds, i);
	if (input[i] == '<')
	{
		if ((i + 1) < len && input[i + 1] == '<')
		{
			token->type = token_here_doc;
			i += 1;
		}
		else
			token->type = token_left_dir;
		token->priority = prio_cmds;
	}
	if (input[i] == '>')
	{
		if ((i + 1) < len && input[i + 1] == '>')
		{
			token->type = token_dright_dir;
			i += 1;
		}
		else
			token->type = token_right_dir;
		token->priority = prio_cmds;
	}
	return (i + 1);
}

size_t	ft_locate_token(char *input, t_token *token, int i)
{
	size_t	len;

	len = ft_strlen(input);
	while (input[i] == ' ' || input[i] == '\t' || (input[i] == '\n' && \
	token->prev == NULL))
	while (input[i] == ' ' || input[i] == '\t' || (input[i] == '\n' && \
	token->prev == NULL))
		i++;
	if (input[i] == '\0' && token->prev == NULL)
		return (-1);
		return (-1);
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			return (ft_quotes(token, input, i));
		if (input[i] == '|' || input[i] == '&')
			return (ft_pipe_or_and(token, len, input, i));
		if (input[i] == '(' || input[i] == ')' || input[i] == '\n')
			return (ft_par_nl(token, input, i));
		if (input[i] == ' ' || input[i] == '\t')
			return (token->type = token_word, token->priority = prio_cmds, i);
		if (input[i] == '<' || input[i] == '>')
			return (ft_redir(token, len, input, i));
		i++;
	}
	return (token->type = token_word, token->priority = prio_cmds, i);
}
