/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:45:27 by anferre           #+#    #+#             */
/*   Updated: 2024/03/21 13:09:11 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	*ft_newcmd()
{
	t_cmd	*newcmd;

	newcmd = malloc(sizeof(t_cmd));
	if (!newcmd)
		return (NULL);
	newcmd->cmd_index = 2;
	newcmd->fd = -1;
	newcmd->nb_cmd = 0;
	newcmd->H_D = false;
	return (newcmd);
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

void	ft_free_args(char ***args, t_cmd *cmd)
{
	int i;
	
	i = 0;
	while (i < cmd->nb_cmd)	
	{
		ft_free_split(args[i]);
		i++;
	}
	free(args);
}

void	ft_free_path(char **str, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->nb_cmd)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_split(char **str)
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
