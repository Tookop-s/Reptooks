/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:25:03 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:18:24 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_syntax2(t_token *tokens, t_token *prev)
{
	if (tokens->type == token_left_par && !((prev->type == token_and_and || \
		prev->type == token_or || prev->type == token_left_par \
		|| prev->type == token_pipe || !(prev->type == token_word && prev->prev \
		&& ft_isredir(prev->prev)))))
		return (ft_syntax_error(tokens, tokens->next), NULL);
	if (tokens->type == token_right_par && !((prev->type == token_word || \
		prev->type == token_right_par)))
		return (ft_syntax_error(tokens, tokens->next), NULL);
	if (tokens->type == token_here_doc && !((prev->type == token_word || \
		prev->type == token_left_par || prev->type == token_and_and || \
		prev->type == token_or || prev->type == token_pipe)))
		return (ft_syntax_error(tokens, tokens->next), NULL);
	if (tokens->type == token_dright_dir && !((prev->type == token_word || \
		prev->type == token_left_par || prev->type == token_and_and || \
		prev->type == token_or || prev->type == token_pipe)))
		return (ft_syntax_error(tokens, tokens->next), NULL);
	return (tokens);
}

t_token	*ft_syntax3(t_token *tokens, t_token *prev)
{
	if (tokens->type == token_right_dir && !((prev->type == token_word || \
		prev->type == token_left_par || prev->type == token_and_and || \
		prev->type == token_or || prev->type == token_pipe || \
		prev->type == token_right_par)))
		return (ft_syntax_error(tokens, tokens->next), NULL);
	if (tokens->type == token_left_dir && !((prev->type == token_word || \
		prev->type == token_left_par || prev->type == token_and_and || \
		prev->type == token_or || prev->type == token_pipe)))
		return (ft_syntax_error(tokens, tokens->next), NULL);
	if (tokens->type == token_pipe && !((prev->type == token_word || \
		prev->type == token_right_par)))
		return (ft_syntax_error(tokens, tokens->next), NULL);
	if (tokens->type == token_or && !((prev->type == token_word || \
		prev->type == token_right_par)))
		return (ft_syntax_error(tokens, tokens->next), NULL);
	return (tokens);
}

t_token	*ft_syntax(t_token *tokens, t_token *prev, int *par_count)
{
	t_token	*next;

	while (tokens->next != NULL)
	{
		if (tokens->type == token_left_par)
			(*par_count)++;
		if (tokens->type == token_right_par)
			(*par_count)--;
		next = tokens->next;
		if (tokens->type == token_word && (prev->type == token_right_par))
			return (ft_syntax_error(tokens, tokens->next), NULL);
		if (tokens->type == token_and_and && !((prev->type == token_word || \
		prev->type == token_right_par)))
			return (ft_syntax_error(tokens, tokens->next), NULL);
		if (!ft_syntax2(tokens, prev) || !ft_syntax3(tokens, prev))
			return (NULL);
		prev = tokens;
		tokens = tokens->next;
	}
	return (tokens);
}
