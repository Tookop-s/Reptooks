/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:49:19 by anferre           #+#    #+#             */
/*   Updated: 2024/03/30 17:34:55 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static int	ft_redirect(t_cmd	*cmd, char **argv, int p_fd[2][2])
{
	if ((cmd->i) > 0)
	{
		if (dup2(p_fd[(cmd->i) % 2][0], STDIN_FILENO) == -1)
			return (perror("dup2 failed"), -1);
	}
	else if ((cmd->i) == 0)
		if (ft_input(argv) == -1)
			return (-1);
	if ((cmd->i) < cmd->nb_cmd - 1)
	{
		if (dup2(p_fd[((cmd->i) + 1) % 2][1], STDOUT_FILENO) == -1)
			return (perror("dup2 failed"), -1);
	}
	else
	{
		if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
			return (perror("dup2 failed"), -1);
	}
	return (0);
}

static int	ft_pipex_childs(int p_fd[2][2], char **env, t_cmd *cmd, char **argv)
{
	if (ft_redirect(cmd, argv, p_fd) == -1)
		return (-1);
	ft_c_fd(p_fd[((cmd->i) + 1) % 2], p_fd[(cmd->i) % 2], cmd->std_fd);
	if (cmd->path[(cmd->i)] == NULL)
		return (ft_free_all(cmd, cmd->nb_cmd), exit (127), -1);
	execve(cmd->path[(cmd->i)], cmd->args[(cmd->i)], env);
	if ((cmd->i) < cmd->nb_cmd - 1)
		perror("execve");
	ft_free_all(cmd, cmd->nb_cmd);
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

static int	ft_wait(t_cmd *cmd, int p_fd[2][2], pid_t *child)
{
	int		status;
	int		i;

	status = 0;
		i = 0;
	while (i < cmd->nb_cmd)
	{
		if ((waitpid(child[i], &status, 0) < 0))
			return (perror("waitpid"), -1);
		if (status != 0 && i == cmd->nb_cmd - 1)
			ft_exit(status, cmd, p_fd);
		status = 0;
		i++;
	}
	i--;
	if (cmd->path[i] == NULL)
	{
		ft_c_fd(p_fd[i % 2], p_fd[(i + 1) % 2], cmd->std_fd);
		ft_free_all(cmd, cmd->nb_cmd);
		free(child);
		exit(127);
	}
	ft_c_fd(p_fd[i % 2], p_fd[(i + 1) % 2], cmd->std_fd);
	return (0);
}

int	ft_pipex(char **env, t_cmd *cmd, char **argv)
{
	int		p_fd[2][2];

	if (ft_create_pipes(cmd, p_fd) < 0)
		return (-1);
	while (++(cmd->i) < cmd->nb_cmd)
	{
		cmd->child[(cmd->i)] = fork();
		if (cmd->child[(cmd->i)] < 0)
			return (perror("fork"), ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), -1);
		if (cmd->child[(cmd->i)] == 0)
			if (ft_pipex_childs(p_fd, env, cmd, argv) == -1)
				return (ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), -1);
		if (cmd->child[(cmd->i)] > 0)
			if (ft_pipex_parent(p_fd, cmd, (cmd->i)) != 0)
				return (-1);
	}
	if ((ft_wait(cmd, p_fd, cmd->child)) == -1)
		return (-1);
	return (0);
}
