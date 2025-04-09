/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:26:42 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/02 14:47:41 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_heredoc(t_command *command, t_mini *mini, int i, int *j)
{
	if (command->redir_type[i] != NULL && command->redir_type[i + 1] \
		!= NULL && *(command->redir_type[i]) == token_here_doc && \
		*(command->redir_type[i + 1]) == token_here_doc)
	{
		if (mini == NULL || mini->heredoc == NULL)
			return (EXIT_FAILURE);
		if (ft_here_doc(command->redir_dest[i], mini, *j) == -1)
			return (EXIT_FAILURE);
		(*j)++;
	}
	else if (*(command->redir_type[i]) == token_here_doc)
	{
		if (mini == NULL || mini->heredoc == NULL)
			return (EXIT_FAILURE);
		if (ft_here_doc(command->redir_dest[i], mini, *j) == -1)
			return (EXIT_FAILURE);
		if (mini->heredoc->heredoc_paths[*j] == NULL)
			return (EXIT_FAILURE);
		if (ft_heredoc_redir(mini->heredoc->heredoc_paths[*j]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ft_unlink_fds(mini);
		(*j)++;
	}
	return (EXIT_SUCCESS);
}

int	handle_redirections(t_command *command, t_mini *mini, int i, int j)
{
	while (command->redir_type[i] != NULL && g_got_signal != 2)
	{
		if (*(command->redir_type[i]) == token_left_dir)
		{
			if (ft_left_redir(command->redir_dest[i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		if (handle_heredoc(command, mini, i, &j) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		else if (*(command->redir_type[i]) == token_right_dir)
		{
			if (ft_right_redir(command->redir_dest[i], 0) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (*(command->redir_type[i]) == token_dright_dir)
		{
			if (ft_right_redir(command->redir_dest[i], 1) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_heredoc_redir(char *heredoc_path)
{
	int	fd;

	fd = open(heredoc_path, O_RDONLY);
	if (fd == -1 && g_got_signal != 2)
	{
		perror("Error opening heredoc file for reading");
		exit (130);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_left_redir(char *redir_dest)
{
	int	fd;

	fd = open(redir_dest, O_RDONLY);
	if (fd == -1)
	{
		ft_error(redir_dest, NULL, ": No such file or directory");
		return (EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_right_redir(char *redir_dest, int append)
{
	int	fd;

	if (append)
		fd = open(redir_dest, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(redir_dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening file for writing");
		return (EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
