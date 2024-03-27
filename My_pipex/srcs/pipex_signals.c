/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:21:01 by anferre           #+#    #+#             */
/*   Updated: 2024/03/27 15:14:08 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/pipex.h>

int	ft_exit(int status, t_cmd *cmd)
{
	int	exit_status;

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		ft_free_all(cmd, cmd->nb_cmd);
		exit(exit_status);
	}
	if (WIFSIGNALED(status))
		exit_status = WTERMSIG(status);
	return (0);
}
