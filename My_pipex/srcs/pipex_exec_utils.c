/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:50:37 by anferre           #+#    #+#             */
/*   Updated: 2024/03/29 13:35:18 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

//redirect the infile to stdin
int	ft_redirect_input(char *str, int fd)
{
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		fd = open("/dev/null", O_RDONLY);
		if (fd == -1)
			return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		return (perror("dup2 fd"), close(fd), -1);
	close(fd);
	return (0);
}

int	ft_input(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fd = open("/dev/null", O_RDONLY);
		if (fd == -1)
			return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		return (perror("dup2 fd"), close(fd), -1);
	close(fd);
	return (0);
}

//create the pipes used by the childs 
int	ft_create_pipes(t_cmd *cmd, char **argv, int p_fd[2][2])
{
	if (pipe(p_fd[0]) == -1)
		return (perror("pipe_1"), -1);
	if (pipe(p_fd[1]) == -1)
		return (ft_c_fd(p_fd[0], NULL, NULL), perror("pipe_2"), -1);
	cmd->std_fd[0] = dup(STDIN_FILENO);
	if (cmd->std_fd[0] == -1)
		return (ft_c_fd(p_fd[0], p_fd[1], NULL), perror("dup STDIN"), -1);
	cmd->std_fd[1] = dup(STDOUT_FILENO);
	if (cmd->std_fd[1] == -1)
	{
		close(cmd->std_fd[0]);
		return (ft_c_fd(p_fd[0], p_fd[1], NULL), perror("dup_STDOUT"), -1);
	}
	if (ft_input(argv) == -1)
		return (ft_c_fd(p_fd[0], p_fd[1], NULL), -1);
	return (0);
}

int	ft_wait(t_cmd *cmd, int *status, pid_t *child)
{
	int	i;

	i = 0;
	while (i < cmd->nb_cmd)
	{
		if ((waitpid(child[i], status, 0) < 0))
			return (perror("waitpid"), -1);
		if (*status != 0 && i == cmd->nb_cmd - 1)
			ft_exit(*status, cmd);
		*status = 0;
		i++;
	}
	return (i - 1);
}
