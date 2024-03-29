/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:19:02 by anferre           #+#    #+#             */
/*   Updated: 2024/03/29 13:35:13 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static int	ft_check_files(char **argv, t_cmd *cmd)
{
	int		i;

	i = 0;
	if (access(argv[1], R_OK) == -1)
		perror(argv[1]);
	while (argv[i + 1])
		i++;
	if (access(argv[i], F_OK) != -1)
	{
		if (access(argv[i], W_OK) == -1)
			perror(argv[i]);
		cmd->out_fd = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0600);
	}
	else if (access(argv[i], F_OK) == -1)
		cmd->out_fd = open(argv[i], O_WRONLY | O_CREAT | O_EXCL, 0600);
	if (cmd->out_fd < 0)
		return (free(cmd), exit(1), -1);
	return (i);
}

static char	*ft_find_in_env(char *env, char *cmd)
{
	char	**temp;
	char	*path;
	int		i;

	i = 0;
	temp = ft_split(env, ':');
	if (!temp)
		return (NULL);
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

static char	*ft_check_env(char **env, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	cmd = ft_strjoin("/", cmd);
	while (env[i] && cmd)
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = ft_find_in_env(env[i], cmd);
			if (path)
				return (free(cmd), path);
		}
		i++;
	}
	return (ft_error("command not found : ", cmd, "\n"), free(cmd), NULL);
}

static int	ft_build_args(char **argv, t_cmd *cmd, char **env)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	cmd->path = malloc(sizeof(char *) * cmd->nb_cmd);
	if (!cmd->path)
		return (free(cmd), -1);
	cmd->args = malloc(sizeof(char **) * cmd->nb_cmd);
	if (!cmd->args)
		return (ft_free_p(cmd->path, j), free(cmd), -1);
	while (argv[i + 1] != NULL)
	{
		cmd->args[j] = ft_split(argv[i], ' ');
		if (!cmd->args[j])
			return (ft_free_all(cmd, j), -1);
		cmd->path[j] = ft_check_env(env, cmd->args[j][0]);
		i++;
		j++;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;

	if (argc != 5 || !env)
		return (1);
	cmd = ft_newcmd();
	if (!cmd)
		return (perror("cmd"), -1);
	cmd->nb_cmd = ft_check_files(argv, cmd) - 2;
	if (cmd->nb_cmd <= 0)
		return (free(cmd), -1);
	cmd->child = malloc(sizeof(pid_t) * cmd->nb_cmd);
	if (!cmd->child)
		return (-1);
	if (ft_build_args(argv, cmd, env) < 0)
		return (-1);
	if (ft_pipex(env, cmd, argv) < 0)
		return (ft_free_all(cmd, cmd->nb_cmd), 127);
	ft_free_all(cmd, cmd->nb_cmd);
	return (0);
}

/*tests that doesn't work :  
./pipex Tools_pipex/test1.txt "grep a1" "wc -w" Tools_pipex/test2.txt

*/