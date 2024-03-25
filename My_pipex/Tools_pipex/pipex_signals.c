/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:21:01 by anferre           #+#    #+#             */
/*   Updated: 2024/03/25 16:38:11 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/pipex.h>

int	ft_wifexited(int status)
{
	return ((status & 0xff00) == 0);
}

int	ft_wexitstatus(int status)
{
	return ((status >> 8) & 0xff);
}

int	ft_wifsignaled(int status)
{
	return ((status & 0x7f) != 0 && !ft_wifexited(status));
}

int	ft_wtermsig(int status)
{
	return ((status) & 0x7f);
}

int	ft_signal(int status, t_cmd *cmd)
{
	int	exit_status;
	int	signal_nb;

	if (ft_wifexited(status))
	{
		exit_status = ft_wexitstatus(status);
		ft_free_all(cmd, cmd->nb_cmd);
		exit(exit_status);
	}
	else if (ft_wifsignaled(status))
	{
		signal_nb = ft_wtermsig(status);
		ft_free_all(cmd, cmd->nb_cmd);
		exit(signal_nb);
	}
	return (0);
}
