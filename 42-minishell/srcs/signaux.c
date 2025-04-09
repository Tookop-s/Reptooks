/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:13:08 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/03 18:18:25 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		if (g_got_signal == 0 || g_got_signal == 2)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			g_got_signal = 0;
		}
		else if (g_got_signal == 1)
			write(1, "\n", 1);
	}
}

void	handle_eof(t_mini *mini, char *input)
{
	write(1, "exit\n", 5);
	if (dup2(mini->stdin_copy, STDIN_FILENO) == -1 || \
	dup2(mini->stdout_copy, STDOUT_FILENO) == -1)
		return ;
	close(mini->stdin_copy);
	close(mini->stdout_copy);
	free_mini_d_quit(mini, input);
	exit(0);
}

void	handle_hd_child_signal(int signal)
{
	char	*here_doc_file;
	char	*tmp;

	if (signal == SIGINT && g_got_signal == 3)
	{
		here_doc_file = ft_strdup(".here_doc");
		while (access(here_doc_file, F_OK) == 0)
		{
			unlink(here_doc_file);
			tmp = here_doc_file;
			here_doc_file = ft_strjoin(here_doc_file, ".h_d");
			free(tmp);
		}
		write(1, "\n", 1);
		exit(130);
	}
}

// g_got_signal == 0 needed to handle classic ctrl+c
// g_got_signal == 1 needed to handle pipes
// g_got_signal == 2 needed to avoid an entry in the 
//					next here_doc (handle multiple here_doc with sigint)
// g_got_signal == 3 needed to handle classic here_doc