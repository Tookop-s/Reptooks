/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:00:54 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 15:50:56 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **args)
{
	int	i;
	int	j;
	int	newline;

	newline = 1;
	i = 0;
	while (args[++i] && (args[i][0] == '-'))
	{
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break ;
		newline = 0;
	}
	while (args[i])
	{
		write(STDOUT_FILENO, args[i], strlen(args[i]));
		if (args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (newline == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}

int	check_length_and_compare(char *str, t_bool is_neg)
{
	int	len;

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
	return (0);
}

int	ft_pwd(char **args)
{
	char	*cwd;

	if (args[1] && args[1][0] == '-')
		return (ft_error("pwd:", args[1], ": invalid option"), 2);
	cwd = get_current_dir_name();
	if (cwd != NULL)
	{
		write(1, cwd, ft_strlen(cwd));
		write(1, "\n", 1);
		free(cwd);
	}
	else
	{
		perror("ft_pwd error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_env(char **args, t_mini *mini, int export)
{
	int	i;

	i = 0;
	if (!args[1])
	{
		while (mini->env[i])
		{
			if (export == 1)
				write(1, "declare -x ", 11);
			write (1, mini->env[i], ft_strlen(mini->env[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

// int ft_is_not_valid(char *str)
// {
// 	int 		i;
// 	int 		len;
// 	t_bool		is_neg;

// 	i = 0;
// 	if (str[0] == '-' || str[0] == '+')
// 	{
// 		if (str[0] == '-')
// 			is_neg = true;
// 		str++;
// 	}
// 	len = ft_strlen(str);
// 	if (len > 19)
// 		return (1);
// 	else if (len == 19)
// 	{
// 		if (is_neg && ft_strcmp(str, "9223372036854775808") > 0)
// 			return (1);
// 		else if (!is_neg && ft_strcmp(str, "9223372036854775807") > 0)
// 			return (1);
// 	}
// 	while (str[i])
// 	{
// 		if (ft_isdigit(str[i]) == 0)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

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
// 	exit(exit_code);
// }