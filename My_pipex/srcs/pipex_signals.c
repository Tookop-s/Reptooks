/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:21:01 by anferre           #+#    #+#             */
/*   Updated: 2024/03/26 11:29:38 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/pipex.h>

int	ft_wifexited(int status)
{
	return (WIFEXITED(status));
}

int	ft_wexitstatus(int status)
{
	return (WEXITSTATUS(status));
}

int	ft_wifsignaled(int status)
{
	return (WIFSIGNALED(status));
}

int	ft_wtermsig(int status)
{
	return (WTERMSIG(status));
}

int	ft_signal(int status, t_cmd *cmd, pid_t *child)
{
	int	exit_status;
	int	signal_nb;

	if (ft_wifexited(status))
	{
		exit_status = ft_wexitstatus(status);
		ft_free_all(cmd, cmd->nb_cmd);
		free(child);
		exit(exit_status);
	}
	else if (ft_wifsignaled(status))
	{
		signal_nb = ft_wtermsig(status);
		ft_free_all(cmd, cmd->nb_cmd);
		free(child);
		exit(signal_nb);
	}
	return (0);
}
