/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:32:11 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/03 18:41:12 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_hd_child_process(char *lim, int fd, \
	struct sigaction sa_child, t_mini *mini)
{
	sigemptyset(&sa_child.sa_mask);
	if (sigaction(SIGINT, &sa_child, NULL) == -1)
	{
		perror("sigaction");
		exit(1);
	}
	handle_input(lim, fd, mini);
	free(mini->heredoc->here_doc_file);
	if (mini->is_pipe == 1)
		ft_free_all_pipex(mini);
	free_mini_childs(mini, NULL);
	close(fd);
	exit(0);
}

int	handle_hd_parent_process(pid_t pid, t_mini *mini)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		mini->last_exit = 130;
		g_got_signal = 2;
		return (0);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		mini->last_exit = 0;
		g_got_signal = 0;
		return (1);
	}
	else
	{
		mini->last_exit = WEXITSTATUS(status);
		return (0);
	}
}

void	handle_input(char *lim, int fd, t_mini *mini)
{
	char	*line;
	int		i;

	i = 1;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (mini->is_pipe == 1)
				ft_free_all_pipex(mini);
			handle_hd_eof(i, lim, mini, fd);
			exit(1);
		}
		if (ft_strcmp(line, lim) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		i++;
	}
}

char	*ft_remove_dol(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] == '"')
			i++;
		else
		{
			new_str[j] = str[i];
			i++;
			j++;
		}
	}
	return (free(str), new_str[j] = '\0', new_str);
}

void	handle_hd_eof(int i, char *lim, t_mini *mini, int fd)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(lim);
	tmp2 = ft_remove_dol(tmp);
	tmp = ft_remove_quotes(tmp2);
	printf("bash: warning: here-document at line %d delimited " \
	"by end-of-file (wanted `%s')\n", i, tmp);
	free(mini->heredoc->here_doc_file);
	free_mini_childs(mini, NULL);
	close(fd);
	free(tmp);
	exit(0);
}
