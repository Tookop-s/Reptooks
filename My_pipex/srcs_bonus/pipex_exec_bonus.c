/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:49:19 by anferre           #+#    #+#             */
/*   Updated: 2024/03/29 13:35:44 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

static int	ft_pipex_childs(int p_fd[2][2], char **env, t_cmd *cmd, int i)
{
	close(p_fd[i % 2][1]);
	if (i > 0)
	{
		if (dup2(p_fd[i % 2][0], STDIN_FILENO) == -1)
		{
			ft_c_fd(p_fd[(i + 1) % 2], p_fd[i % 2], cmd->std_fd);
			return (close(p_fd[i % 2][0]), -1);
		}
	}
	close(p_fd[i % 2][0]);
	if (dup2(p_fd[(i + 1) % 2][1], STDOUT_FILENO) == -1)
	{
		ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd);
		return (-1);
	}
	if (cmd->h_d == true)
		close(cmd->h_d_fd);
	ft_c_fd(p_fd[(i + 1) % 2], NULL, cmd->std_fd);
	if (cmd->path[i] == NULL)
		return (ft_free_all(cmd, cmd->nb_cmd), exit (127), -1);
	execve(cmd->path[i], cmd->args[i], env);
	if (i < cmd->nb_cmd - 1)
		perror("execve");
	exit(errno);
}

static int	ft_pipex_parent(int p_fd[2][2], t_cmd *cmd, int i)
{
	if (dup2(cmd->std_fd[0], STDIN_FILENO) == -1)
		return (ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), -1);
	if (dup2(cmd->std_fd[1], STDOUT_FILENO) == -1)
		return (ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), -1);
	close(p_fd[i % 2][1]);
	close(p_fd[i % 2][0]);
	if (i < cmd->nb_cmd - 1)
	{
		if (pipe(p_fd[i % 2]) == -1)
		{
			ft_c_fd(p_fd[(i + 1) % 2], NULL, cmd->std_fd);
			return (perror("pipe"), -1);
		}
	}
	return (0);
}

static int	ft_write_output(int pipe_fd, t_cmd *cmd)
{
	char	buff[BUFF_SIZE];
	int		b_read;

	b_read = read(pipe_fd, buff, BUFF_SIZE);
	while (b_read > 0)
	{
		if (write(cmd->out_fd, buff, b_read) != b_read)
			return (close(cmd->out_fd), perror("write"), -1);
		b_read = read(pipe_fd, buff, BUFF_SIZE);
	}
	return (close(cmd->out_fd), 0);
}

static int	ft_wait_write(t_cmd *cmd, int p_fd[2][2], pid_t *child)
{
	int		status;
	int		i;

	status = 0;
	i = ft_wait(cmd, &status, child);
	if (i < 0)
		return (-1);
	if (cmd->path[i] == NULL)
	{
		ft_c_fd(p_fd[i % 2], p_fd[(i + 1) % 2], cmd->std_fd);
		ft_free_all(cmd, cmd->nb_cmd);
		free(child);
		exit(127);
	}
	ft_c_fd(p_fd[i % 2], NULL, cmd->std_fd);
	close(p_fd[(i + 1) % 2][1]);
	if (ft_write_output(p_fd[(i + 1) % 2][0], cmd) != 0)
		return (close(p_fd[(i + 1) % 2][0]), -1);
	close(p_fd[(i + 1) % 2][0]);
	return (0);
}

int	ft_pipex(char **env, t_cmd *cmd, char **argv)
{
	int		p_fd[2][2];
	int		i;

	i = -1;
	if (ft_create_pipes(cmd, argv, p_fd) < 0)
		return (-1);
	while (++i < cmd->nb_cmd)
	{
		cmd->child[i] = fork();
		if (cmd->child[i] < 0)
			return (perror("fork"), ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), -1);
		if (cmd->child[i] == 0)
			if (ft_pipex_childs(p_fd, env, cmd, i) == -1)
				return (ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), -1);
		if (cmd->child[i] > 0)
			if (ft_pipex_parent(p_fd, cmd, i) != 0)
				return (-1);
	}
	if ((ft_wait_write(cmd, p_fd, cmd->child)) == -1)
		return (free(cmd->child), -1);
	return (0);
}
