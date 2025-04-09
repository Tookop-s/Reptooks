/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:37:14 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 18:26:34 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_not_valid(char *str)
{
	t_bool	is_neg;
	int		len;

	is_neg = false;
	if (*str == '-' || *str == '+')
	{
		is_neg = (*str == '-');
		str++;
	}
	len = ft_strlen(str);
	if (len > 19)
		return (1);
	else if (len == 19)
	{
		if (is_neg && ft_strcmp(str, "9223372036854775808") > 0)
			return (1);
		else if (!is_neg && ft_strcmp(str, "9223372036854775807") > 0)
			return (1);
	}
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (1);
	}
	return (0);
}

int	next_exit(char **args, t_mini *mini, char *arg_code, int exit_code)
{
	int	i;

	i = 0;
	if (args[1] && mini)
	{
		while (arg_code[i])
		{
			if (ft_is_not_valid(arg_code))
			{
				ft_error("exit:", args[1], " : numeric argument required\n");
				exit(2);
			}
			i++;
		}
		if (ft_atoi(args[1]) < 0)
			exit_code = ft_atoi(args[1]) % 256;
		else
			exit_code = ft_atoi(args[1]) % 256;
		if (exit_code > 255)
			return (ft_error("exit:", args[1], ": wrong numeric argument\n"), 1);
		if (args[2])
			return (perror("exit: too many arguments\n"), 1);
	}
	return (exit_code);
}

void	ft_exit(char **args, t_mini *mini, t_bool is_pipe)
{
	int		exit_code;
	char	*arg_code;

	exit_code = 0;
	arg_code = args[1];
	exit_code = next_exit(args, mini, arg_code, exit_code);
	if (exit_code == 1)
		return ;
	if (is_pipe == false)
		write(1, "exit\n", 5);
	close(mini->stdin_copy);
	close(mini->stdout_copy);
	free_mini(mini, NULL);
	free(mini);
	exit(exit_code);
}

char	*ft_get_home(char **env)
{
	int		i;
	char	*home;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=s", 5) == 0)
		{
			home = ft_strdup(env[i] + 5);
			return (home);
		}
		i++;
	}
	return (NULL);
}

int	ft_cd(char **args, t_mini *mini)
{
	char	*home;

	if (!args[1] || strcmp(args[1], "~") == 0)
	{
		home = ft_get_home(mini->env);
		if (!home)
			return (ft_error("cd:", args[1], " HOME not set"), EXIT_FAILURE);
		if (chdir(home) == -1)
			return (perror("chdir error"), EXIT_FAILURE);
	}
	else if (args[2])
	{
		perror("cd: too many arguments\n");
		return (EXIT_FAILURE);
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			perror("ft_cd error");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

// void	ft_exit(char **args, t_mini *mini, t_bool is_pipe)
// {
// 	int		exit_code;
// 	char	*arg_code;
// 	int		i;	

// 	i = 0;
// 	exit_code = 0;
// 	arg_code = args[1];
// 	if (args[1] && mini)
// 	{
// 		while (arg_code[i])
// 		{
// 			if (ft_is_not_valid(arg_code))
// 			{
// 				ft_error("exit:", args[1], " : numeric argument required\n");
// 				exit(2);
// 			}
// 			i++;
// 		}
// 		if (ft_atoi(args[1]) < 0)
// 			exit_code = ft_atoi(args[1]) % 256;
// 		else
// 			exit_code = ft_atoi(args[1]) % 256;
// 		if (exit_code > 255)
// 		{
// 			ft_error("exit:", args[1], ": wrong numeric argument\n");
// 			return ;
// 		}
// 		if (args[2])
// 		{
// 			perror("exit: too many arguments\n");
// 			return ;
// 		}
// 	}
// 	if (is_pipe == false)
// 		write(1, "exit\n", 5);
// 	close(mini->stdin_copy);
// 	close(mini->stdout_copy);
// 	free_mini(mini, NULL);
// 	free(mini);
// 	exit(exit_code);
// }
