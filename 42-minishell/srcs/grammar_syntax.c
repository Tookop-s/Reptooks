/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:33:42 by anferre           #+#    #+#             */
/*   Updated: 2024/07/03 18:37:58 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_islogic(t_token *token)
{
	if (token)
	{
		if (token->type == token_pipe || token->type == token_and_and || \
		token->type == token_or)
			return (1);
	}
	return (0);
}

int	ft_isredir(t_token *token)
{
	if (token)
	{
		if (token->type == token_left_dir || token->type == token_right_dir \
		|| token->type == token_here_doc || token->type == token_dright_dir)
			return (1);
	}
	return (0);
}

int	ft_ispar(t_token *token)
{
	if (token)
	{
		if (token->type == token_left_par || token->type == token_right_par)
			return (1);
	}
	return (0);
}

int	ft_token_error(t_token *token)
{
	if ((!token->next && (ft_isredir(token) && token->prev && \
	token->prev->prev && (token->prev->type == token_word || \
	token->prev->type == token_left_par))) || (!token->prev && \
	(ft_islogic(token) || token->type == token_right_par)) \
	|| (ft_islogic(token) && token->prev && ft_islogic(token->prev) && \
	token->prev->prev) || (ft_isredir(token) && token->prev && \
	ft_isredir(token->prev)) || (ft_ispar(token) && token->prev && \
	ft_isredir(token->prev)) || (ft_ispar(token) && token->prev && \
	token->prev->prev && ft_isredir(token->prev->prev)) || \
	(ft_islogic(token) && token->prev && ft_isredir(token->prev)) || \
	(token->type == token_right_par && token->prev && \
	token->prev->type == token_left_par))
		return (1);
	return (0);
}
