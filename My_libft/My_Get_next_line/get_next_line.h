/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:38:44 by anferre           #+#    #+#             */
/*   Updated: 2024/01/08 16:09:07 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

int		ft_check_index_new_line(t_list *lst);
int		ft_buff_to_lst(t_list **lst, int fd);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);
char	*ft_fill_line(t_list *lst);
char	*ft_lst_to_line(char *line, t_list *lst);
void	*ft_free(t_list **lst);
void	*ft_lstnew_back(char *str, t_list **lst);
t_list	*ft_copy_del_lst(t_list **lst, int nb_char);
size_t	ft_strindex(const char *s, char c);

#endif