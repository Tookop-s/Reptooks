/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:04:07 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:03:14 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_here_doc(char *lim, t_mini *mini, int j)
{
	int	fd;

	if (g_got_signal == 2)
		return (-1);
	g_got_signal = 3;
	fd = create_heredoc_file(mini);
	if (fd == -1)
		return (-1);
	if (ft_get_input(lim, fd, mini) == 0)
	{
		free(mini->heredoc->here_doc_file);
		close(fd);
		return (-1);
	}
	ft_add_new_heredoc_path(mini, j);
	free(mini->heredoc->here_doc_file);
	close(fd);
	return (fd);
}

int	create_heredoc_file(t_mini *mini)
{
	int		fd;
	char	*old_here_doc_file;

	old_here_doc_file = NULL;
	mini->heredoc->here_doc_file = ft_strdup(".here_doc");
	while (access(mini->heredoc->here_doc_file, F_OK) == 0)
	{
		old_here_doc_file = mini->heredoc->here_doc_file;
		mini->heredoc->here_doc_file = \
		ft_strjoin(mini->heredoc->here_doc_file, ".h_d");
		free(old_here_doc_file);
	}
	fd = open(mini->heredoc->here_doc_file, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		perror("open here_doc_file");
		free(mini->heredoc->here_doc_file);
		return (-1);
	}
	return (fd);
}

int	ft_get_input(char *lim, int fd, t_mini *mini)
{
	pid_t				pid;
	struct sigaction	sa_child;

	sa_child.sa_handler = handle_hd_child_signal;
	sa_child.sa_flags = SA_RESTART;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	if (pid == 0)
		handle_hd_child_process(lim, fd, sa_child, mini);
	else
	{
		return (handle_hd_parent_process(pid, mini));
	}
	return (0);
}

void	ft_add_new_heredoc_path(t_mini *mini, int j)
{
	char	**new_heredoc_paths;
	int		i;

	new_heredoc_paths = malloc(sizeof(char *) * (j + 2));
	if (new_heredoc_paths == NULL)
		return ;
	i = 0;
	while (i < j)
	{
		new_heredoc_paths[i] = mini->heredoc->heredoc_paths[i];
		i++;
	}
	new_heredoc_paths[j] = ft_strdup(mini->heredoc->here_doc_file);
	new_heredoc_paths[j + 1] = NULL;
	if (new_heredoc_paths[j] == NULL)
	{
		free(new_heredoc_paths);
		return ;
	}
	free(mini->heredoc->heredoc_paths);
	mini->heredoc->heredoc_paths = new_heredoc_paths;
}

void	ft_unlink_fds(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->heredoc->heredoc_paths[i] != NULL)
	{
		unlink(mini->heredoc->heredoc_paths[i]);
		free(mini->heredoc->heredoc_paths[i]);
		i++;
	}
	free(mini->heredoc->heredoc_paths);
	mini->heredoc->heredoc_paths = NULL;
}

// malloc str |
// do we need to handle n<< ? n = filedescriptor
// do we need to handle n<< ? n = filedescriptor
//  if LIMITER quoted then no expansion

// int	ft_here_doc(char *lim, t_mini *mini, int j)
// {
//     int		fd;
// 	char	*old_here_doc_file;

// 	old_here_doc_file = NULL;
//     if (g_got_signal == 2)
//         return (-1);
//     g_got_signal = 3;
// 	mini->heredoc->here_doc_file = ft_strdup(".here_doc");
// 	while (access(mini->heredoc->here_doc_file, F_OK) == 0)
// 	{
// 		old_here_doc_file = mini->heredoc->here_doc_file;
// 		mini->heredoc->here_doc_file = 
// ft_strjoin(mini->heredoc->here_doc_file, ".h_d");
// 		free(old_here_doc_file);
// 	}
// 	fd = open(mini->heredoc->here_doc_file, O_WRONLY | O_CREAT | O_TRUNC, 0600);
// 	if (fd == -1)
// 		return (perror("open here_doc_file"), -1);
//     if (ft_get_input(lim, fd, mini) == 0)
//     {
// 		free(mini->heredoc->here_doc_file);
//         close(fd);
//         return (-1);
//     }
//     ft_add_new_heredoc_path(mini, j);
// 	free(mini->heredoc->here_doc_file);
//     close(fd);
//     return (fd);
// }