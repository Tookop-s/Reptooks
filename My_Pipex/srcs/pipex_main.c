/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:19:02 by anferre           #+#    #+#             */
/*   Updated: 2024/03/11 13:28:27 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

// int	ft_pipex(char** env, t_cmd *cmd)
// {
// 	int		pipe_fd[cmd->nb_cmd - 1][2];
// 	pid_t	child[cmd->nb_cmd];
// 	int		i;
// 	int		status;

// 	i = 0;	
// 	while (i < cmd->nb_cmd)
// 	{
// 		if (pipe(pipe_fd[i]) == -1)
// 			return (perror("pipe error"), 1);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < cmd->nb_cmd)
// 	{
// 		if ((child[i] = fork()) == 0)
// 		{
// 			execve(cmd->path, &cmd->args[i][1], env);
// 		}
// 	}
// 	if (child[i] > 0)
// 	{
// 		i = 0;
// 		while (i < cmd->nb_cmd - 1)
// 		{
// 			close(pipe_fd[i][0]);
// 			close(pipe_fd[i][1]);
// 			i++;
// 		}
// 		i = 0;
// 		while (i < cmd->nb_cmd)
// 		{
// 			waitpid(child[i], &status, 0);
// 		}
// 	}
// 	return (0);
// }

int	ft_get_input(char **argv, size_t len_limit)
{
	char	limiter[len_limit];
	char	*newline;
	int		fd;

	fd = open("infile.txt", O_RDWR | O_APPEND | O_CREAT , 0600);
	if (!fd)
		return(ft_error("open error : ", "infile.txt", "\n"), -1);
	ft_strlcpy(limiter, argv[2], ft_strlen(argv[2]) + 1);
	newline = get_next_line(0);
	while (newline != NULL && ft_strcmp(limiter, newline) != 0)
	{
		write(fd, newline, ft_strlen(newline));
		free(newline);
		newline = get_next_line(fd);
	}
	close (fd);
	return (fd);
}

int	ft_check(char **argv, char**env, t_cmd *cmd)
{
	int		i;

	i = 0;
	if (env)
	{}
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		cmd->fd = ft_get_input(argv, ft_strlen(argv[2]));
		i = 3;
	}
	else
		if (access(argv[1], R_OK) == -1)
			return (ft_error( "Permission denied : ", argv[1], "\n"), -1);
	while(argv[i + 1])
		i++;
	if (access(argv[i], W_OK) == -1)
		return (ft_unlink(cmd->fd), ft_error( "Permission denied : ", argv[1], "\n"), -1);
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
	ft_free_split(temp);
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
				return (free(cmd), path);
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
		return (-1);
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
{
	t_cmd	*cmd;
	
	if (argc)
	// 	return (perror("Arguments missing"), -1);
	// if (env)
	cmd = NULL;
	cmd = ft_newcmd();
	if (!cmd)
		return (-1);
	if (ft_check(argv, env, cmd) < 0)
		return (-1);
	if (ft_build_args(argv, cmd, env) < 0)
		return (-1);
	return (0);
}
/*
steps : 

check / build = ok 
for in/outfile (permissions, creation) --> file_check
and here_doc

build = ok
build the args array char *args[] --> build_args
look for the cmds path in the enpv --> get_path

build multiprocess =
create pipes (nb_cmd-1)
create 1 child for each cmd
execute the cmds 

wait and write = 
wait for all before writting to the outfile */
