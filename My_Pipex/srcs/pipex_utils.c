/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:45:27 by anferre           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/22 15:43:52 by anferre          ###   ########.fr       */
=======
/*   Updated: 2024/03/12 15:06:11 by anferre          ###   ########.fr       */
>>>>>>> parent of b445d40 (working ! need to fix check return and clean)
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	*ft_newcmd()
{
	t_cmd	*newcmd;

	newcmd = malloc(sizeof(t_cmd));
	if (!newcmd)
		return (NULL);
	newcmd->nb_cmd = 0;
	newcmd->next = NULL;
	newcmd->H_D = false;
	return (newcmd);
}

void	ft_free_all(t_cmd *cmd, int nb)
{
	ft_free_a(cmd->args, nb);
	ft_free_p(cmd->path, nb);
	free(cmd);
}

void	ft_free_a(char ***args, int nb)
{
	int i;
	
	i = 0;
	while (i < nb && args[i])	
	{
		ft_free_s(args[i]);
		i++;
	}
	free(args);
}

void	ft_error(char *str1, char *str2, char *str3)
{
	if (str1)
		write(2, str1, ft_strlen(str1));
	if (str2)
		write(2, str2, ft_strlen(str2));
	if (str3)
		write(2, str3, ft_strlen(str3));
}

void	ft_free_args(char ***args)
{
	int i;
	int	j;
	
	i = 0;
	j = 0;
	while (args[i])	
	{
		j = 0;
		while (args[i][j])
		{
			free(args[i][j]);
			j++;
		}
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_free_path(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_unlink(int fd)
{
	if (fd >= 3)
		unlink("infile.txt");
}

<<<<<<< HEAD
void	ft_unlink(int fd)
{
	if (fd >= 3)
		unlink("infile.txt");
}

void	ft_free_s(char **str)
=======
void	ft_free_split(char **str)
>>>>>>> parent of b445d40 (working ! need to fix check return and clean)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free (str);
}

void	ft_c_fd(int *pipe_fd1, int *pipe_fd2, int *std_fd)
{
	if (std_fd)
	{
		close(std_fd[0]);
		close(std_fd[1]);
	}
	if (pipe_fd1)
	{
		close(pipe_fd1[1]);
		close(pipe_fd1[0]);
	}
	if (pipe_fd2)
	{
		close(pipe_fd2[1]);
		close(pipe_fd2[0]);
	}
}