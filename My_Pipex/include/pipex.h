/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:40:09 by anferre           #+#    #+#             */
/*   Updated: 2024/03/12 17:02:01 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

#define BUFF_SIZE 1024

typedef enum e_bool
{
	true = 1 ,
	false = 0
} t_bool;

typedef struct s_cmd
{
	int				cmd_index;
	int				nb_cmd;
	int				fd;
	t_bool			H_D;
	char			***args;
	char			**path;
	struct s_cmd	*next;
}					t_cmd;

void	ft_error(char *str1, char *str2, char *str3);
void	ft_free_args(char ***args);
void	ft_unlink(int fd);
void	ft_free_path(char **str);
void	ft_free_split(char **str);
void	*ft_newcmd();
int		ft_get_input(int pipe_fd);
int		ft_write_output(int pipe_fd, char **argv, t_cmd *cmd);

#endif