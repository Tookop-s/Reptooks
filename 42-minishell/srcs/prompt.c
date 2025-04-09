/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:56:18 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/04 14:20:13 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_got_signal = 0;

int	ft_prompt(t_mini *mini)
{
	char	*input;
	int		i;
	int		exit_code;

	if (!mini)
		return (0);
	if (init_signal_handler() == -1)
		return (-1);
	// while (1)
	// {
	i = 0;
	input = readline("minishell $ >> ");
	g_got_signal = 0;
	if (!input)
		handle_eof(mini, input);
	else if (input && *input)
	{
		add_history(input);
		mini->og_cmd = ft_lexing(input, mini);
		if (!mini->og_cmd)
		{
			// continue;
		}
		else
		{
			mini->og_cmd = ft_grammar(mini->og_cmd, mini);
			if (!mini->og_cmd)
			{
				// continue;
			}
			else
			{
				mini->node = ft_parsing(mini->og_cmd, mini);
				if (!mini->node)
				{
					free_mini(mini, input);
					// continue;
				}
				else
				{
					while (mini->node[i])
					{
						mini->node[i] = ft_expand(mini->node[i], mini);
						if (!mini->node[i])
							break ;
						mini->last_exit = ft_exec(mini->node[i], mini);
						i++;
					}
					if (dup2(mini->stdin_copy, STDIN_FILENO) == -1 || \
						dup2(mini->stdout_copy, STDOUT_FILENO) == -1)
						return (EXIT_FAILURE);
				}
			}
			free_mini_loop(mini);
			free(input);
		}
		free_mini_loop(mini);
	}
	// }
	exit_code = mini->last_exit;
	return (exit_code);
}
