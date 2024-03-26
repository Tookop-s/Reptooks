/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:35:14 by anferre           #+#    #+#             */
/*   Updated: 2024/03/26 16:30:04 by anferre          ###   ########.fr       */
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

# define BUFF_SIZE 1024

typedef enum e_bool
{
	true = 1,
	false = 0
}			t_bool;

typedef struct s_cmd
{
	int				nb_cmd;
	int				std_fd[2];
	int				outfile_fd;
	pid_t			*child;
	t_bool			h_d;
	char			***args;
	char			**path;
}					t_cmd;

		/*EXEC*/
int		ft_pipex(char **env, t_cmd *cmd, char **argv);
int		ft_get_input(int pipe_fd);
int		ft_redirect_input(char **argv, int p_fd[2][2]);
int		ft_input(t_cmd *cmd, int p_fd[2][2], char **argv);
int		ft_create_pipes(t_cmd *cmd, char **argv, int p_fd[2][2]);
int		ft_exit(int status, t_cmd *cmd);

		/*UTILS*/
void	*ft_newcmd(void);
void	ft_free_all(t_cmd *cmd, int nb);
void	ft_free_a(char ***args, int nb);
void	ft_free_p(char **str, int nb);
void	ft_free_s(char **str);
void	ft_c_fd(int *pipe_fd1, int *pipe_fd2, int *std_fd);
void	ft_error(char *str1, char *str2, char *str3);

#endif