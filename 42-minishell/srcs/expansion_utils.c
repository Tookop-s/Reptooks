/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:12:59 by anferre           #+#    #+#             */
/*   Updated: 2024/07/03 18:32:18 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//remove the quotes from the command
char	*ft_remove_quotes(char *str)
{
	int		i;
	int		j;
	char	quote;
	char	*tmp;

	i = 0;
	quote = 0;
	j = 0;
	tmp = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		if ((str[i] != '\'' && str[i] != '\"') || (quote && str[i] != quote))
		{
			tmp[j] = str[i];
			j++;
		}
		if (!quote && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		i++;
	}
	return (free(str), tmp);
}

//combines the command with the expanded command 
char	**ft_add_args(char **cmd, char **tmp)
{
	int		j;
	int		i;
	char	**new_cmd;

	j = 0;
	new_cmd = malloc(sizeof(char *) * (ft_strlen_2d((const char **)cmd) \
	+ ft_strlen_2d((const char **)tmp) + 1));
	if (!new_cmd)
		return (NULL);
	while (cmd && cmd[j])
	{
		new_cmd[j] = cmd[j];
		j++;
	}
	i = -1;
	while (tmp && tmp[++i])
	{
		new_cmd[j + i] = tmp[i];
	}
	new_cmd[j + i] = NULL;
	if (cmd)
		free(cmd);
	return (free(tmp), new_cmd);
}

char	**ft_trim_arg(char **cmd, int i)
{
	int		j;
	int		k;
	size_t	len;
	char	**tmp;

	j = 0;
	k = 0;
	len = ft_strlen_2d((const char **)cmd);
	tmp = malloc(sizeof(char *) * len);
	if (!tmp)
		return (NULL);
	while (cmd[j])
	{
		if (j != i)
		{
			tmp[k] = ft_strdup(cmd[j]);
			k++;
		}
		free(cmd[j]);
		j++;
	}
	tmp[k] = NULL;
	return (free(cmd), tmp);
}

char	**ft_swap_cmd(char **cmd, char **tmp_cmd, t_bool swapped, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (cmd[i] && swapped == true)
	{
		swapped = false;
		j = i + 1;
		while (cmd[j])
		{
			if (ft_strcmp(tmp_cmd[i], tmp_cmd[j]) > 0)
			{
				swapped = true;
				tmp = cmd[i];
				cmd[i] = cmd[j];
				cmd[j] = tmp;
				tmp = tmp_cmd[i];
				tmp_cmd[i] = tmp_cmd[j];
				tmp_cmd[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (cmd);
}

//return 1 if there is a dollar in the argument outside of quotes
int	ft_dol_in_quotes(char *str)
{
	int		i;
	int		dquote;

	i = 0;
	dquote = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			dquote = (dquote + 1) % 2;
		if (str[i] == '$' && dquote == 0)
			return (0);
		i++;
	}
	return (1);
}
