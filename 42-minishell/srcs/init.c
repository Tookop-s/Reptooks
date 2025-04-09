/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:54:06 by anferre           #+#    #+#             */
/*   Updated: 2024/07/02 14:47:41 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_build_env(char **env)
{
	int		i;
	char	**tmp;
	size_t	len;

	i = 0;
	len = 0;
	while (env[len])
		len++;
	tmp = malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		return (NULL);
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		if (!tmp[i])
		{
			while (i > 0)
				free(tmp[--i]);
			free(tmp);
			return (NULL);
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

t_mini	*ft_init(char **env)
{
	t_mini	*mini;

	mini = malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->env = ft_build_env(env);
	mini->last_exit = 0;
	mini->nb_node = 0;
	mini->is_pipe = 0;
	mini->heredoc = malloc(sizeof(t_heredoc));
	if (!mini->heredoc)
	{
		free(mini->heredoc);
		free(mini->env);
		free(mini);
		return (NULL);
	}
	if (mini->heredoc)
		ft_memset(mini->heredoc, 0, sizeof(t_heredoc));
	mini->heredoc->heredoc_fd = -1;
	return (mini);
}

int	init_signal_handler(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		return (-1);
	}
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
