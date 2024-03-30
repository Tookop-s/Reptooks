/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:50:37 by anferre           #+#    #+#             */
/*   Updated: 2024/03/29 13:51:01 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

//get the input from stdin and then redirect the here_doc to stdin
int	ft_get_input(char **argv, t_cmd *cmd)
{
	int		b_read;
	char	buff[BUFF_SIZE];

	cmd->h_d_fd = open("here_doc.txt", O_CREAT | O_RDWR, 0600);
	if (cmd->h_d_fd == -1)
		return (-1);
	b_read = read(STDIN_FILENO, buff, BUFF_SIZE);
	if (b_read < 0)
		return (perror("read STDIN"), -1);
	while (b_read > 0 && ft_strncmp(argv[2], buff, ft_strlen(argv[2])) != 0)
	{
		if (write(cmd->h_d_fd, buff, b_read) != b_read)
			return (perror("write"), -1);
		b_read = read(STDIN_FILENO, buff, BUFF_SIZE);
		if (b_read < 0)
			return (perror("read STDIN"), -1);
		if (ft_strncmp(argv[2], buff, ft_strlen(argv[2])) == 0)
			break ;
	}
	close(cmd->h_d_fd);
	if (ft_redirect_input("here_doc.txt", cmd->h_d_fd) < 0)
		return (perror("redirect here_doc"), -1);
	return (0);
}

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

//if here_doc get the input if not redirect the infile
int	ft_input(t_cmd *cmd, int p_fd[2][2], char **argv)
{
	int	fd;

	fd = 0;
	if (cmd->h_d == true)
	{
		if ((ft_get_input(argv, cmd)) == -1)
			ft_c_fd(p_fd[0], p_fd[1], NULL);
	}
	else
	{
		if ((ft_redirect_input(argv[1], fd)) == -1)
			ft_c_fd(p_fd[0], p_fd[1], NULL);
	}
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
	if (ft_input(cmd, p_fd, argv) == -1)
		return (close(cmd->std_fd[0]), close(cmd->std_fd[1]), -1);
	return (0);
}

int	ft_wait(t_cmd *cmd, int *status, pid_t *child, int p_fd[2][2])
{
	int	i;

	i = 0;
	while (i < cmd->nb_cmd)
	{
		if ((waitpid(child[i], status, 0) < 0))
			return (perror("waitpid"), -1);
		if (*status != 0 && i == cmd->nb_cmd - 1)
			ft_exit(*status, cmd, p_fd);
		*status = 0;
		i++;
	}
	return (i - 1);
}
