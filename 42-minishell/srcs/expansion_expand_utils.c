/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_expand_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:26:32 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:06:51 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen_var(char *cmd, int *start)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	while (cmd[i] && cmd[i] != '$')
		i++;
	i++;
	*start = i;
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != '$' && \
	ft_isalnum(cmd[i]) == 1)
	{
		len++;
		i++;
	}
	return (len);
}

//get the value of the variable cmd in the env
char	*ft_get_in_env( char *cmd, char **env)
{
	int		i;
	char	*tmp;
	size_t	len;

	i = 0;
	len = ft_strlen(cmd);
	while (env[i])
	{
		if (ft_strncmp(env[i], cmd, len) == 0 && env[i][len] == '=')
		{
			tmp = ft_strdup(env[i] + len + 1);
			return (free(cmd), tmp);
		}
		i++;
	}
	return (free(cmd), tmp = ft_strdup(""));
}

//replace the $VAR by the value of the variable in the env
char	*ft_expand_var(char *str, t_mini *mini, int is_exit_status, \
t_bool *expand)
{
	char	*tmp;
	char	*tmp2;
	int		start;
	int		len;

	if (is_exit_status)
		return (tmp = ft_itoa(mini->last_exit));
	start = 0;
	len = ft_strlen_var(str, &start);
	tmp2 = ft_substr(str, start, len);
	tmp = ft_get_in_env(tmp2, mini->env);
	if (ft_strlen(tmp) != 0)
		*expand = true;
	return (tmp);
}

//look for the $ in the command and expand it
char	*ft_handle_dollar(char *cm, t_mini *mini, t_bool *expand)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	j = 0;
	tmp = ft_expand_var(&cm[j], mini, 0, expand);
	j++;
	while (cm[j] && cm[j] != ' ' && cm[j] != '\t' && cm[j] != '$' && \
	ft_isalnum(cm[j]) == 1)
		j++;
	tmp2 = ft_strjoin(tmp, &cm[j]);
	free(tmp);
	return (tmp2);
}

char	*ft_trim_dol_quotes(char *cmd, int j)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(cmd) - 2));
	if (!tmp)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] != '\'' && cmd[i] != '\"' && i != j)
		{
			tmp[j] = cmd[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	return (free(cmd), tmp);
}
