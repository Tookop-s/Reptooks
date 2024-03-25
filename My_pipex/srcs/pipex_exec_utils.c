/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:50:37 by anferre           #+#    #+#             */
/*   Updated: 2024/03/25 18:01:17 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/pipex.h>

int	ft_get_input(int pipe_fd)
{
	int		b_read;
	char	buff[BUFF_SIZE];

	b_read = read(STDIN_FILENO, buff, BUFF_SIZE);
	while (b_read > 0)
	{
		if (write(pipe_fd, buff, b_read) != b_read)
			return (perror("write"), -1);
		b_read = read(STDIN_FILENO, buff, BUFF_SIZE);
	}
	return (0);
}

int	ft_redirect_input(char **argv, int p_fd[2][2])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		close(p_fd[1][1]);
	else if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(p_fd[1][1]);
	}
	if (fd > 0)
		close(fd);
	return (0);
}

int	ft_input(t_cmd *cmd, int p_fd[2][2], char **argv)
{
	if (cmd->h_d == true)
	{
		if ((ft_get_input(p_fd[0][1])) == -1)
			close(p_fd[1][1]);
	}
	if (cmd->h_d == false)
	{
		if ((ft_redirect_input(argv, p_fd)) == -1)
			close(p_fd[1][1]);
	}
	return (0);
}

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
	if (ft_input(cmd, p_fd, argv) == -1)
		return (-1);
	return (0);
}
