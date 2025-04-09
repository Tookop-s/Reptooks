/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:04:15 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 16:06:23 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_rm_var(char **env, int i)
{
	int		j;
	int		k;
	char	**new_env;

	j = 0;
	k = 0;
	new_env = malloc(sizeof(char *) * (ft_strlen_2d((const char **)env)));
	if (!new_env)
		return (NULL);
	while (env[j])
	{
		if (j != i)
		{
			new_env[k] = env[j];
			k++;
		}
		j++;
	}
	new_env[k] = NULL;
	free(env);
	return (new_env);
}

int	ft_unset(char **args, t_mini *mini)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!args[1] || ft_strcmp(args[1], "") == 0)
		return (EXIT_SUCCESS);
	if (args[1] && args[1][0] == '-')
		return (ft_error("unset:", args[j], ": invalid option"), 2);
	while (args[j])
	{
		while (mini->env[i])
		{
			if (ft_strncmp(args[j], mini->env[i], ft_strlen(args[j])) \
					== 0 && mini->env[i][ft_strlen(args[j])] == '=')
			{
				mini->env = ft_rm_var(mini->env, i);
				return (EXIT_SUCCESS);
			}
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}
