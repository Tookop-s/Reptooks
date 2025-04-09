/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:16:45 by gchamore          #+#    #+#             */
/*   Updated: 2024/07/03 18:41:23 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//function to free the env 
void	ft_destroy_char_d(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str[i])
	{
		free(tab_str[i]);
		tab_str[i] = NULL;
		i++;
	}
	free(tab_str);
	tab_str = NULL;
}

void	free_token_list(t_token *head)
{
	t_token	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_destroy_env(char **env)
{
	int	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		free(env[i]);
		env[i] = NULL;
		i++;
	}
	free(env);
	env = NULL;
}

void	ft_free_str(char **str)
{
	int	j;

	j = 0;
	while (str[j] != NULL)
	{
		free(str[j]);
		j++;
	}
	free (str);
}

// FREE THE NODE AND ITS CONTENT
void	ft_cleanup(t_node *node)
{
	if (node != NULL)
	{
		if (node->command != NULL)
		{
			if (node->command->cmd != NULL)
				free(node->command->cmd);
			if (node->command->redir_dest != NULL)
				free(node->command->redir_dest);
			if (node->command->redir_type != NULL)
				free(node->command->redir_type);
			free(node->command);
		}
		free(node);
	}
}
