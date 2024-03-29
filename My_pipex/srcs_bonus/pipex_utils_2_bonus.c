/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:53:33 by anferre           #+#    #+#             */
/*   Updated: 2024/03/29 13:36:15 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

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

void	ft_error(char *str1, char *str2, char *str3)
{
	if (str1)
		write(2, str1, ft_strlen(str1));
	if (str2 && &str2[1])
		write(2, &str2[1], ft_strlen(&str2[1]));
	if (str3)
		write(2, str3, ft_strlen(str3));
}
