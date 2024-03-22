/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:19:02 by anferre           #+#    #+#             */
/*   Updated: 2024/03/22 15:48:16 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	ft_pipex_childs(int p_fd[2][2], char** env, t_cmd *cmd, int i)
{
	close(pipe_fd[i % 2][1]);
	close(pipe_fd[(i + 1) % 2][0]);
	if (i > 0)
		dup2(pipe_fd[i % 2][0], STDIN_FILENO);
	close(pipe_fd[i % 2][0]);
	if (i < cmd->nb_cmd - 1)
		dup2(pipe_fd[(i + 1) % 2][1], STDOUT_FILENO);
	close(pipe_fd[(i + 1) % 2][1]);
	execve(cmd->path[i], &cmd->args[i][1], env);
	return (perror("execve"), -1);
}

int	ft_pipex_parent(int pipe_fd[2][2], t_cmd *cmd, int i, char **argv, pid_t *child)
{
	if (i == cmd->nb_cmd - 1)
	{
		close(pipe_fd[(i + 1) % 2][0]);
		if (ft_write_output(pipe_fd[i % 2][1], argv, cmd) == -1)
			return (close(pipe_fd[(i + 1) % 2][1]), -1);
		close(pipe_fd[(i + 1) % 2][1]);
	}
	close(pipe_fd[i % 2][1]);
	close(pipe_fd[i % 2][0]);
	if (pipe(pipe_fd[i % 2]) == -1)
		return (perror("pipe_1 error"), -1);
	return (0);
}

int	ft_pipex(char** env, t_cmd *cmd, char **argv)
{
	int		p_fd[2][2];
	pid_t	child[cmd->nb_cmd];
	int		i;

	i = 0;
	if (pipe(pipe_fd[i]) == -1)
		return (perror("pipe_1 error"), -1);
	if (pipe(pipe_fd[i + 1]) == -1)
		return (perror("pipe_2 error"), -1);
	if (cmd->H_D == true)
		ft_get_input(pipe_fd[0][1]);
	else
	{
		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd == -1)
			return (perror("open infile"), -1);
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
	while (i < cmd->nb_cmd)
	{
		child[i] = fork();
		if (child[i] < 0)
			return (perror("fork"), ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), -1);
		if (child[i] == 0)
		{
			if (ft_pipex_childs(p_fd, env, cmd, i) == -1)
				return(close(cmd->std_fd[0]), close(cmd->std_fd[1]), -1);
		}
		if (child[i] > 0)
			if (ft_pipex_parent(pipe_fd, cmd, i, argv, child) != 0)
				return (-1);
		i++;
	}
	while (i != 0)
	{
		waitpid(child[i], &status, 0);
		i--;
	}
	return (0);
}

int	ft_get_input(int pipe_fd)
{
	int		b_read;
	char	buff[BUFF_SIZE];
	
	while ((b_read = read(STDIN_FILENO, buff, BUFF_SIZE)) > 0)
		if (write(pipe_fd, buff, b_read) != b_read)
			return (perror("write"), -1);
	dup2(pipe_fd, STDIN_FILENO);
	close(pipe_fd);
	return (0);
}

int	ft_write_output(int pipe_fd, char **argv, t_cmd *cmd)
{
	char	buff[BUFF_SIZE];
	int		b_read;
	int		outfile_fd;
	int		i;
	
	if (cmd->H_D == true)
		i = cmd->nb_cmd + 3; 
	else
		i = cmd->nb_cmd + 2; 
	outfile_fd = open(argv[i], O_WRONLY);
	while ((b_read = read(pipe_fd, buff, BUFF_SIZE)) > 0)
    	if (write(outfile_fd, buff, b_read) != b_read)
			return (perror("write"), -1);
	return (0);
}

int	ft_check_files(char **argv, t_cmd *cmd)
{
	int		i;
	t_bool	error;

	i = 0;
	error = false;
	if (ft_strcmp(argv[1], "here_doc") == 0)
		cmd->H_D = true;
	else if (access(argv[1], R_OK) == -1)
	{
		perror(argv[1]);
		error = true;
	}
	while(argv[i + 1])
		i++;
	if (access(argv[i], W_OK) == -1)
	{
		perror(argv[i]);
		error = true;
	}
	if (error == true)
		return (-1);
	if (cmd->H_D == true)
		i -= 1;
	return (i);
}

char 	*ft_find_in_env(char *env, char *cmd)
{
	char	**temp;
	char	*path;
	int		i;

	i = 0;
	temp = ft_split(env, ':');
	while (temp[i])
	{
		path = ft_strjoin(temp[i], cmd);
		if (access(path, X_OK) == 0)
			return (ft_free_split(temp), path);
		i++;
	}
	ft_free_s(temp);
	return (NULL);
}

char	*ft_check_env(char **env, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	cmd = ft_strjoin("/", cmd);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = ft_find_in_env(env[i], cmd);
			if (path)
				return (path);
		}
		i++;
	}
	return (ft_error("command not found : ", cmd, "\n"), NULL);
}

int	ft_build_args(char **argv, t_cmd *cmd, char **env)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	cmd->path = malloc(sizeof(char*) * cmd->nb_cmd);
	if (!cmd->path)
		return (free(cmd), -1);
	cmd->args = malloc(sizeof(char**) * cmd->nb_cmd);
	if (!cmd->args)
		return (ft_unlink(cmd->fd),ft_free_path(cmd->path), -1);
	if (cmd->fd > 0)
		i = 3;
	while (argv[i + 1] != NULL)
	{
		cmd->args[j] = ft_split(argv[i], ' ');
		if (!cmd->args)
			return (ft_unlink(cmd->fd), ft_free_args(cmd->args), ft_free_path(cmd->path), -1);
		cmd->path[j] = ft_check_env(env, cmd->args[j][0]);
		if (!cmd->path[j])
			return (ft_unlink(cmd->fd), ft_free_args(cmd->args), ft_free_path(cmd->path), -1);
		i++;
		j++;
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{STDIN_FILENO
	t_cmd	*cmd;
	
	if (argc < 5 || !env)
		return(perror("Args"), -1);
	cmd = ft_newcmd();
	if (!cmd)
		return (perror("cmd"), -1);
	cmd->nb_cmd = ft_check_files(argv, cmd) - 2;
	if (cmd->nb_cmd <= 0)
		return (free(cmd),-1);
	if (ft_build_args(argv, cmd, env) < 0)
		return (free(cmd), -1);
	ft_pipex(env, cmd, argv);
	return (0);
}

/*tests that doesn't work :  
./pipex Tools_pipex/test1.txt "grep a1" "wc -w" Tools_pipex/test2.txt

*/