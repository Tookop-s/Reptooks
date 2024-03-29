/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_signals_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:21:01 by anferre           #+#    #+#             */
/*   Updated: 2024/03/29 13:36:02 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

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
