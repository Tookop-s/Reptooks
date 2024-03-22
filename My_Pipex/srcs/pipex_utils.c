/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:45:27 by anferre           #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2024/03/22 15:43:52 by anferre          ###   ########.fr       */
=======
/*   Updated: 2024/03/12 15:06:11 by anferre          ###   ########.fr       */
>>>>>>> parent of b445d40 (working ! need to fix check return and clean)
=======
/*   Updated: 2024/03/21 13:09:11 by anferre          ###   ########.fr       */
>>>>>>> parent of 0d45b30 (it doesn't work anymore =\)
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
	newcmd->next = NULL;
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

<<<<<<< HEAD
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
=======
void	ft_free_args(char ***args, t_cmd *cmd)
{
	int i;
	
	i = 0;
	while (i < cmd->nb_cmd)	
	{
		ft_free_split(args[i]);
>>>>>>> parent of 0d45b30 (it doesn't work anymore =\)
		i++;
	}
	free(args);
}

<<<<<<< HEAD
void	ft_free_path(char **str)
=======
void	ft_free_path(char **str, t_cmd *cmd)
>>>>>>> parent of 0d45b30 (it doesn't work anymore =\)
{
	int	i;

	i = 0;
<<<<<<< HEAD
	while (str[i])
=======
	while (i < cmd->nb_cmd)
>>>>>>> parent of 0d45b30 (it doesn't work anymore =\)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

<<<<<<< HEAD
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
=======
void	ft_free_split(char **str)
>>>>>>> parent of 0d45b30 (it doesn't work anymore =\)
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
