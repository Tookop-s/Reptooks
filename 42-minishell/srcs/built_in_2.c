/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:27:40 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/03 17:04:46 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_var_name(char *var)
{
	int	i;

	i = 0;
	if (!var || (var[0] == '\0'))
		return (EXIT_FAILURE);
	if (ft_isalpha(var[0]) == 0 && var[0] != '_')
		return (EXIT_FAILURE);
	while (var[i] && var[i] != '=')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

char	*add_quotes_to_env_var(char *env_var)
{
	char	**split;
	char	*tmp;
	char	*tmp2;
	char	*result;

	split = ft_split(env_var, '=');
	if (split[1])
	{
		tmp = ft_strjoin(split[0], "=\"");
		tmp2 = ft_strjoin(tmp, split[1]);
		free(tmp);
		result = ft_strjoin(tmp2, "\"");
		free(tmp2);
	}
	else
		result = ft_strjoin(env_var, "=\"\"");
	ft_free_str(split);
	return (result);
}

char	**ft_add_quotes(char **env)
{
	int		i;
	char	*new_env_var;

	i = 0;
	while (env[i])
	{
		new_env_var = add_quotes_to_env_var(env[i]);
		free(env[i]);
		env[i] = new_env_var;
		i++;
	}
	return (env);
}

void	update_or_add_env_var(t_mini *mini, char *arg, char *tmp)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(arg, '=');
	if (!split)
		return ;
	while (mini->env[++i])
	{
		if (ft_strcmp(arg, mini->env[i]) == 0)
		{
			ft_free_str(split);
			return ;
		}
		else if (ft_strncmp(split[0], mini->env[i], ft_strlen(split[0])) == 0)
		{
			tmp = mini->env[i];
			mini->env[i] = ft_strdup(arg);
			free(tmp);
			ft_free_str(split);
			return ;
		}
	}
	mini->env = ft_add_file_name(mini->env, arg);
	ft_free_str(split);
}

int	ft_export(char **args, t_mini *mini)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = NULL;
	if (!args[1])
	{
		mini->env = ft_add_quotes(mini->env);
		ft_env(args, mini, 1);
		return (EXIT_SUCCESS);
	}
	while (args[++j])
	{
		if (ft_check_var_name(args[j]) == EXIT_FAILURE)
		{
			if (args[j][0] == '-')
				return (ft_error("export:", args[j], ": invalid option"), 2);
			else
				return (ft_error("export : ", args[j], \
				" : not a valid identifier"), 1);
		}
		update_or_add_env_var(mini, args[j], tmp);
	}
	return (EXIT_SUCCESS);
}

// char	**ft_add_quotes(char **env)
// {
// 	int		i;
// 	int		j;
// 	char	**split;
// 	char	*tmp;
// 	char	*tmp2;

// 	i = 0;
// 	while (env[i])
// 	{
// 		j = 0;
// 		while (env[i][j] && env[i][j] != '=')
// 			j++;
// 		if (env[i][j] == '=' && env[i][j + 1] != '\0')
// 		{
// 			split = ft_split(env[i], '=');
// 			if (split[1])
// 			{
// 				tmp = ft_strjoin(split[0], "=\"");
// 				tmp2 = ft_strjoin(tmp, split[1]);
// 				free(tmp);
// 				free(env[i]);
// 				env[i] = ft_strjoin(tmp2, "\"");
// 				ft_free_str(split);
// 				free(tmp2);
// 			}
// 		}
// 		else
// 		{
// 			tmp = ft_strjoin(env[i], "=\"\"");
// 			free(env[i]);
// 			env[i] = tmp;
// 		}
// 		i++;
// 	}
// 	return (env);
// }

// int	ft_export(char **args, t_mini *mini)
// {
// 	int		i;
// 	int		j;
// 	char	**split;
// 	char	*tmp;

// 	i = 0;
// 	j = 1;
// 	if (!args[1])
// 	{
// 		mini->env = ft_add_quotes(mini->env);
// 		ft_env(args, mini, 1);
// 		return (EXIT_SUCCESS);
// 	}
// 	while (args[j])
// 	{
// 		if (ft_check_var_name(args[j]) == EXIT_FAILURE)
// 		{
// 			if (args[j][0] == '-')
// 				return (ft_error("export:", args[j], 
//						": invalid option"), 2);
// 			else
// 				return (ft_error("export : ", args[j], 
//						" : not a valid identifier"), 1);
// 		}
// 		split = ft_split(args[j], '=');
// 		if (!split)
// 			return (EXIT_FAILURE);
// 		while (mini->env[i])
// 		{
// 			if (ft_strcmp(args[j], mini->env[i]) == 0)
// 			{
// 				ft_free_str(split);
// 				return (EXIT_SUCCESS);
// 			}
// 			else if (ft_strncmp(split[0], mini->env[i], 
//							ft_strlen(split[0])) == 0)
// 			{
// 				tmp = mini->env[i];
// 				mini->env[i] = ft_strdup(args[j]);
// 				free(tmp);
// 				break ;
// 			}
// 			i++;
// 		}
// 		mini->env = ft_add_file_name(mini->env, args[j], true);
// 		ft_free_str(split);
// 		j++;
// 	}
// 	return (EXIT_SUCCESS);
// }