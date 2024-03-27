/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:45:27 by anferre           #+#    #+#             */
/*   Updated: 2024/03/27 14:31:42 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/pipex.h>

void	*ft_newcmd(void)
{
	t_cmd	*newcmd;

	newcmd = malloc(sizeof(t_cmd));
	if (!newcmd)
		return (NULL);
	newcmd->nb_cmd = 0;
	newcmd->h_d = false;
	newcmd->outfile_fd = 0;
	return (newcmd);
}

void	ft_free_all(t_cmd *cmd, int nb)
{
	ft_free_a(cmd->args, nb);
	ft_free_p(cmd->path, nb);
	free(cmd->child);
	if (cmd->h_d == true)
		unlink("here_doc.txt");
	free(cmd);
}

void	ft_free_a(char ***args, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_free_s(args[i]);
		i++;
	}
	free(args);
}

void	ft_free_p(char **str, int nb)
{
	int	i;

	i = 0;
	while(i < nb)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_s(char **str)
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
