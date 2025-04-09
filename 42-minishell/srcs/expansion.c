/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:22:04 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:18:08 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//sort the command array
char	**ft_sort_cmd(char **cmd, int index)
{
	t_bool	swapped;
	char	**tmp_cmd;
	int		len;

	swapped = true;
	len = ft_strlen_2d((const char **)cmd) + 1;
	tmp_cmd = malloc(sizeof(char *) * len);
	if (!tmp_cmd)
		return (NULL);
	tmp_cmd = ft_dstr_tolower(cmd, tmp_cmd);
	if (!tmp_cmd)
		return (NULL);
	cmd = ft_swap_cmd(cmd, tmp_cmd, swapped, index);
	ft_destroy_char_d(tmp_cmd);
	return (cmd);
}

char	**ft_expand_pathname(char **tmp2, int *j)
{
	char	**tmp;
	char	**tmp3;

	tmp = ft_pathname_expansion(tmp2[(*j)]);
	if (!tmp)
		return (NULL);
	if (ft_strcmp(tmp[0], tmp2[(*j)]) == 0)
	{
		ft_destroy_char_d(tmp);
		return (tmp2);
	}
	tmp3 = ft_trim_asterisk(tmp2, tmp, *j);
	if (!tmp3)
		return (NULL);
	tmp2 = ft_sort_cmd(tmp3, (*j));
	if (!tmp2)
		return (NULL);
	return (tmp2);
}

char	**ft_sort_trim_cmd(char **tmp2, t_bool expand, t_bool dol_in_q, int *j)
{
	while (tmp2 && tmp2[(*j)])
	{
		if (ft_strcmp(tmp2[(*j)], "") == 0 && (*j) != 0 && dol_in_q == false)
		{
			tmp2 = ft_trim_arg(tmp2, (*j));
			if (!tmp2)
				return (NULL);
			break ;
		}
		else if (ft_strcmp(tmp2[(*j)], "") == 0 && (*j) == 0)
			return (NULL);
		if (tmp2[(*j)] && (ft_asterisk_in_quotes(tmp2[(*j)]) != 0 && \
		expand == true))
			tmp2 = ft_expand_pathname(tmp2, j);
		if (tmp2 && tmp2[(*j)] && (strchr(tmp2[(*j)], '\'') || \
		strchr(tmp2[(*j)], '\"')))
		{
			tmp2[(*j)] = ft_remove_quotes(tmp2[(*j)]);
			if (!tmp2[(*j)])
				return (NULL);
		}
		(*j)++;
	}
	return (tmp2);
}

char	**ft_build_expanded_cmd(t_node *node, t_mini *mini, int i)
{
	int		j;
	char	**tmp;
	char	**tmp2;
	t_bool	expand;
	t_bool	dol_in_quotes;

	j = 0;
	expand = true;
	tmp2 = NULL;
	while (node->command && node->command->cmd[i])
	{
		dol_in_quotes = ft_dol_in_quotes(node->command->cmd[i]);
		expand = true;
		tmp = ft_search_dol(node->command->cmd[i], mini, &expand);
		if (!tmp)
			return (NULL);
		tmp2 = ft_add_args(tmp2, tmp);
		if (!tmp2)
			return (NULL);
		tmp2 = ft_sort_trim_cmd(tmp2, expand, dol_in_quotes, &j);
		i++;
	}
	return (tmp2);
}

void	*ft_expand(t_node *node, t_mini *mini)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (node->left)
	{
		ft_expand(node->left, mini);
	}
	if (node->right)
		ft_expand(node->right, mini);
	tmp = ft_build_expanded_cmd(node, mini, i);
	if (node->command)
	{
		free(node->command->cmd);
		node->command->cmd = tmp;
	}
	return (node);
}
