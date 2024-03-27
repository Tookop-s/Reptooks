/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:50:37 by anferre           #+#    #+#             */
/*   Updated: 2024/03/27 18:49:03 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/pipex.h>

//get the input from stdin and then redirect the here_doc to stdin
//maybe use strnstr to locate the EOF and get rid of it in the string
//but i think the diff from the tester comes from the input HERE_DOC=$'Hello\nHello\nHello\nEOF\n'
int	ft_get_input(char **argv, t_cmd *cmd)
{
	int		b_read;
	char	buff[BUFF_SIZE];

	cmd->h_d_fd = open("here_doc.txt",  O_CREAT | O_RDWR, 0600);
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
			break;
	}
	close(cmd->h_d_fd);
	cmd->h_d_fd = open("here_doc.txt",  O_CREAT | O_RDONLY, 0600);
	if (cmd->h_d_fd == -1)
		return (-1);
	if (dup2(cmd->h_d_fd, STDIN_FILENO) == -1)
		return (perror("dup2 h_d"), close(cmd->h_d_fd), -1);
	close(cmd->h_d_fd);
	return (0);
}

//redirect the infile to stdin
int	ft_redirect_input(char **argv)
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

//if here_doc get the input if not redirect the infile
int	ft_input(t_cmd *cmd, int p_fd[2][2], char **argv)
{
	if (cmd->h_d == true)
	{
		if ((ft_get_input(argv, cmd)) == -1)
			ft_c_fd(p_fd[0], p_fd[1], NULL);
	}
	else
	{
		if ((ft_redirect_input(argv)) == -1)
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
