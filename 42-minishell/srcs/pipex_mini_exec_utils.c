/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mini_exec_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:47:00 by anferre           #+#    #+#             */
/*   Updated: 2024/07/04 14:02:43 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//open acces dup
int	ft_open_access_dup(char *str, int flags, int std)
{
	int	fd;

	fd = open(str, flags, 0644);
	if (fd == -1)
	{
		ft_error(NULL, str, ": No such file or directory");
		return (EXIT_FAILURE);
	}
	if (access(str, F_OK) == -1)
	{
		ft_error(str, NULL, ": Permission denied");
		return (EXIT_FAILURE);
	}
	if (dup2(fd, std) == -1)
	{
		ft_error("dup2 failed", NULL, NULL);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (fd);
}

int	ft_input_redir(t_command *command, t_mini *mini, int tmp, int i)
{
	while (command->redir_type[++i] != NULL)
	{
		if (*(command->redir_type[i]) == token_left_dir || \
		*(command->redir_type[i]) == token_here_doc)
			tmp = i;
	}
	i = 0;
	if (tmp >= 0 && *(command->redir_type[tmp]) == token_left_dir)
	{
		if (ft_open_access_dup(command->redir_dest[tmp], \
		O_RDONLY, STDIN_FILENO) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (tmp >= 0 && *(command->redir_type[tmp]) == token_here_doc)
	{
		while (mini->heredoc->heredoc_paths[i + 1])
			i++;
		if (ft_heredoc_redir(mini->heredoc->heredoc_paths[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ft_unlink_fds(mini);
	}
	return (0);
}

int	ft_redir_files(t_command *command, t_mini *mini)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = -1;
	if (ft_input_redir(command, mini, tmp, i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	tmp = -1;
	while (command->redir_type[i] != NULL)
	{
		if (*(command->redir_type[i]) == token_right_dir || \
		*(command->redir_type[i]) == token_dright_dir)
			tmp = i;
		i++;
	}
	if (tmp >= 0 && *(command->redir_type[tmp]) == token_right_dir)
		ft_open_access_dup(command->redir_dest[tmp], \
		O_WRONLY | O_CREAT | O_TRUNC, STDOUT_FILENO);
	else if (tmp >= 0 && *(command->redir_type[tmp]) == token_dright_dir)
		ft_open_access_dup(command->redir_dest[tmp], \
		O_WRONLY | O_CREAT | O_APPEND, STDOUT_FILENO);
	return (0);
}

int	ft_redirect_pipes(t_mini *mini, int p_fd[2][2])
{
	if (*(mini->cmd->i) > 0)
	{
		if (dup2(p_fd[*(mini->cmd->i) % 2][0], STDIN_FILENO) == -1)
		{
			ft_error("dup2 failed", NULL, NULL);
			return (EXIT_FAILURE);
		}
	}
	if (*(mini->cmd->i) < mini->cmd->nb_cmd - 1)
	{
		if (dup2(p_fd[(*(mini->cmd->i) + 1) % 2][1], STDOUT_FILENO) == -1)
		{
			ft_error("dup2 failed", NULL, NULL);
			return (EXIT_FAILURE);
		}
	}
	return (0);
}

char	**ft_copy_dstr(char **str)
{
	char	**dstr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen_2d((const char **)str);
	dstr = malloc(sizeof(char *) * (len + 1));
	if (dstr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != NULL)
	{
		dstr[i] = ft_strdup(str[i]);
		if (dstr[i] == NULL)
		{
			return (NULL);
		}
		i++;
	}
	dstr[i] = NULL;
	return (dstr);
}
