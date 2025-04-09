/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:06:34 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:17:35 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_single_quote(char *cmd, int i, t_bool *expand)
{
	i++;
	if (cmd[i] && cmd[i] == '$')
		*expand = false;
	i++;
	while (cmd[i] && cmd[i] != '\'')
		i++;
	return (i);
}

char	*ft_handle_double_quote(char *cmd, int *i, t_bool *expand, t_mini *mini)
{
	char	*tmp;
	char	*tmp2;

	(*i)++;
	while (cmd[(*i)] && cmd[(*i)] != '\"')
	{
		if (cmd[(*i)] && cmd[(*i)] == '$' && cmd[(*i) + 1] && \
		(ft_isalnum(cmd[(*i) + 1]) == 1 || cmd[(*i) + 1] == '_'))
		{
			tmp = ft_substr(cmd, 0, (*i));
			tmp2 = ft_handle_dollar(&cmd[(*i)], mini, expand);
			free(cmd);
			cmd = ft_strjoin(tmp, tmp2);
			free(tmp);
			free(tmp2);
			(*i) = -1;
			*expand = false;
			break ;
		}
		(*i)++;
	}
	return (cmd);
}

char	*ft_dollar(char *cmd, int *i, t_bool *expand, t_mini *mini)
{
	char	*tmp;
	char	*tmp2;

	if (cmd[(*i) + 1] && (cmd[(*i) + 1] == '?'))
	{
		tmp2 = ft_expand_var(cmd, mini, 1, expand);
		free(cmd);
		cmd = tmp2;
	}
	else if (cmd[(*i) + 1] && (cmd[(*i) + 1] == '\'' || cmd[(*i) + 1] == '\"'))
		cmd = ft_trim_dol_quotes(cmd, (*i));
	else
	{
		tmp = ft_substr(cmd, 0, (*i));
		tmp2 = ft_handle_dollar(&cmd[(*i)], mini, expand);
		free(cmd);
		cmd = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		(*i) = -1;
		*expand = true;
	}
	return (cmd);
}

char	*ft_loop_dol(char *cmd, t_bool *expand, t_mini *mini, t_bool *split_w)
{
	int	i;

	i = -1;
	while (cmd && cmd[++i])
	{
		if (cmd[i] == '\'')
			i = ft_handle_single_quote(cmd, i, expand);
		else if (cmd[i] == '\"')
			cmd = ft_handle_double_quote(cmd, &i, expand, mini);
		else if (cmd[i] && cmd[i] == '$' && cmd[i + 1])
		{
			if (((cmd[i + 1] && !ft_isalnum(cmd[i + 1]) && cmd[i + 1] != '_') \
			|| !cmd[i + 1]) && cmd[i + 1] != '?' && cmd[i + 1] != '\'' && \
			cmd[i + 1] != '\"')
				continue ;
			cmd = ft_dollar(cmd, &i, expand, mini);
			if (i == -1)
			{
				*split_w = false;
				continue ;
			}
		}
	}
	return (cmd);
}

char	**ft_search_dol(char *cmd, t_mini *mini, t_bool *expand)
char	**ft_search_dol(char *cmd, t_mini *mini, t_bool *expand)
{
	t_bool	split_word;
	char	**split_cmd;
	char	*tmp;

	split_word = false;
	tmp = ft_loop_dol(cmd, expand, mini, &split_word);
	if (split_word && *expand)
	{
		split_cmd = ft_split_word(tmp);
		if (split_cmd)
			return (*expand = true, split_word = true, split_cmd);
	}
	split_cmd = malloc(sizeof(char *) * 2);
	if (!split_cmd)
		return (NULL);
	split_cmd[0] = tmp;
	split_cmd[1] = NULL;
	return (split_cmd);
}
