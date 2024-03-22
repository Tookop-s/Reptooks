/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:19:02 by anferre           #+#    #+#             */
/*   Updated: 2024/03/22 15:11:37 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	ft_pipex_childs(int p_fd[2][2], char** env, t_cmd *cmd, int i)
{
	close(p_fd[i % 2][1]);
	if (dup2(p_fd[i % 2][0], STDIN_FILENO) == -1)
	{
		ft_c_fd(p_fd[(i + 1) % 2], NULL, cmd->std_fd);
		return(close(p_fd[i % 2][0]), -1);
	}
	close(p_fd[i % 2][0]);
	if (dup2(p_fd[(i + 1) % 2][1], STDOUT_FILENO) == -1)
	{
		ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd);
		return (-1);
	}
	close(p_fd[(i + 1) % 2][0]);
	close(p_fd[(i + 1) % 2][1]);
	close(cmd->std_fd[0]);
	close(cmd->std_fd[1]);
	execve(cmd->path[i], cmd->args[i], env);
	return (perror("execve"), -1);
}

int	ft_pipex_parent(int p_fd[2][2], t_cmd *cmd, int i)
{
	if (dup2(cmd->std_fd[0], STDIN_FILENO) == -1)
		return(ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), -1);
	if (dup2(cmd->std_fd[1], STDOUT_FILENO) == -1)
		return(ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), -1);
	close(p_fd[i % 2][1]);
	close(p_fd[i % 2][0]);
	if (i < cmd->nb_cmd - 1)
		if (pipe(p_fd[i % 2]) == -1)
		{
			ft_c_fd(p_fd[(i + 1) % 2], NULL, cmd->std_fd);
			return (perror("pipe"), -1);
		}
	return (0);
}

int	ft_redirect_input(char **argv, int p_fd[2][2], t_cmd *cmd)
{
	int	fd;
	
	if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), perror("open infile"), -1);
	if (dup2(fd, p_fd[0][1]) == -1)
		return (ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd), perror("dup cmd->fd"), -1);
	close(fd);
	return (0);
}

int	ft_create_pipes(t_cmd *cmd, char **argv, int p_fd[2][2])
{
	if (pipe(p_fd[0]) == -1)
		return (perror("pipe_1"), -1);
	if (pipe(p_fd[1]) == -1)
		return (ft_c_fd(p_fd[0], NULL, NULL), perror("pipe_2"), -1);
	if ((cmd->std_fd[0] = dup(STDIN_FILENO)) == -1)
		return (ft_c_fd(p_fd[0], p_fd[1], NULL), perror("dup STDIN"), -1);
	if ((cmd->std_fd[1] = dup(STDOUT_FILENO)) == -1)
	{
		close(cmd->std_fd[0]);
		return (ft_c_fd(p_fd[0], p_fd[1], NULL), perror("dup_STDOUT"), -1);
	}
	if (cmd->H_D == true)
		if ((ft_get_input(p_fd[0][1])) == -1)
		{
			ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd);
			return (perror("dup_STDOUT"), -1);
		}
	if (cmd->H_D == false)
		if((ft_redirect_input(argv, p_fd, cmd)) == -1)
		{
			ft_c_fd(p_fd[0], p_fd[1], cmd->std_fd);
			return (perror("dup_STDOUT"), -1);
		}
	return (0);
}

int	ft_wait_write(t_cmd *cmd, int p_fd[2][2], char **argv, pid_t *child)
{
	int		status;
	int 	i;
	
	i = 0;
	while (i < cmd->nb_cmd)
	{
		waitpid(child[i], &status, 0);
		i++;
	}
	i--;
	close(cmd->std_fd[0]);
	close(cmd->std_fd[1]);
	close(p_fd[i % 2][1]);
	close(p_fd[i % 2][0]);
	close(p_fd[(i + 1) % 2][1]);
	if (ft_write_output(p_fd[(i + 1) % 2][0], argv, cmd) == -1)
		return (close(p_fd[(i + 1) % 2][0]), -1);
	close(p_fd[(i + 1) % 2][0]);
	return (0);
}

int	ft_pipex(char** env, t_cmd *cmd, char **argv)
{
	int		p_fd[2][2];
	pid_t	child[cmd->nb_cmd];
	int		i;

	i = 0;
	if (ft_create_pipes(cmd, argv, p_fd) < 0)
		return (-1);
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
			if (ft_pipex_parent(p_fd, cmd, i) != 0)
				return (-1);
		i++;
	}
	if ((ft_wait_write(cmd, p_fd, argv, child)) == -1)
		return (-1);
	return (0);
}

int	ft_get_input(int pipe_fd)
{
	int		b_read;
	char	buff[BUFF_SIZE];
	
	while ((b_read = read(STDIN_FILENO, buff, BUFF_SIZE)) > 0)
		if (write(pipe_fd, buff, b_read) != b_read)
			return (perror("write"), -1);
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
	if (cmd->H_D == false)
	{
		if ((outfile_fd = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0600)) < 0)
			return (perror("Open_Outfile"), -1);
	}
	else 
	{
		if ((outfile_fd = open(argv[i], O_WRONLY | O_CREAT | O_APPEND, 0600)) < 0)
			return (perror("Open_Outfile"), -1);
	}
	while ((b_read = read(pipe_fd, buff, BUFF_SIZE)) > 0)
    	if (write(outfile_fd, buff, b_read) != b_read)
			return (close(outfile_fd), perror("write"), -1);
	close(outfile_fd);
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
			return (ft_free_s(temp), path);
		free (path);
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
		return (ft_free_p(cmd->path, j), free(cmd), -1);
	if (cmd->H_D == true)
		i = 3;
	while (argv[i + 1] != NULL)
	{
		cmd->args[j] = ft_split(argv[i], ' ');
		if (!cmd->args)
			return (ft_free_all(cmd, j), -1);
		cmd->path[j] = ft_check_env(env, cmd->args[j][0]);
		if (!cmd->path[j])
			return (ft_free_all(cmd, j), -1);
		i++;
		j++;
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
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
		return (-1);
	if (ft_pipex(env, cmd, argv) < 0)
		return (ft_free_all(cmd, cmd->nb_cmd), -1);
	ft_free_all(cmd, cmd->nb_cmd);
	return (0);
}

/*tests that doesn't work :  
./pipex Tools_pipex/test1.txt "grep a1" "wc -w" Tools_pipex/test2.txt

*/