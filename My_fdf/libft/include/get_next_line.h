/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:38:44 by anferre           #+#    #+#             */
/*   Updated: 2024/01/23 11:44:47 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_lst
{
	char			*str;
	struct s_lst	*next;
}					t_lst;

int		ft_check_index_new_line(t_lst *lst);
int		ft_buff_to_lst(t_lst **lst, int fd);
char	*get_next_line(int fd);
char	*ft_fill_line(t_lst *lst);
char	*ft_lst_to_line(char *line, t_lst *lst);
void	*ft_free(t_lst **lst);
void	*ft_lstnew_back(char *str, t_lst **lst);
t_lst	*ft_copy_del_lst(t_lst **lst, int nb_char);
size_t	ft_strindex(const char *s, char c);

#endif