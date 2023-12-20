/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintestgnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:14 by anferre           #+#    #+#             */
/*   Updated: 2023/12/20 16:30:25 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_lst_size(t_list *lst)
{
	unsigned int	i;

	i = 0;
	if (!lst)
		return (1);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	if (i == 0)
		i += 1;
	return (i);
}

char	*ft_strdup(char *s)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_lstnew_back(char *str, t_list **lst)
{
	t_list	*newlst;
	t_list	*temp;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
		return (ft_free(lst), NULL);
	if (*lst != NULL)
	{
		temp = *lst;
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		(*lst)->next = newlst;
		*lst = temp;
	}
	else
		*lst = newlst;
	newlst->str = ft_strdup(str);
	newlst->next = NULL;
	if (!newlst->str)
		return (ft_free(lst), NULL);
	return (*lst);
}

void	*ft_free(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!*lst)
		return (NULL);
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
	*lst = NULL;
	return (lst);
}

int	ft_check_index_new_line(t_list *lst)
{
	unsigned int	i;

	i = 0;
	if (!lst)
		return (-1);
	while (lst->next != NULL)
		lst = lst->next;
	while (lst->str[i] != '\0')
	{
		if (lst->str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_buff_to_lst(t_list **lst, int fd)
{
	int		nb_char;
	char	*buff;
	t_list	*temp;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(lst), -1);
	nb_char = read(fd, buff, BUFFER_SIZE);
	buff[nb_char] = '\0';
	if (nb_char != 0)
	{
		temp = ft_lstnew_back(buff, lst);
		free(buff);
		if (temp == NULL)
			return (-1);
		return (nb_char);
	}
	else
		return (free(buff), 0);
}

char	*ft_fill_line(t_list *lst)
{
	unsigned int	k;
	unsigned int	i;
	char			*line;
	t_list			*temp;

	k = 0;
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	line = malloc((BUFFER_SIZE * (ft_lst_size(lst)- 1) \
	+ ft_strlen(temp->str) + 1) * sizeof(char));
	if (!line)
		return (ft_free(&lst), NULL);
	while (lst)
	{
		i = 0;
		while (lst->str[i] != '\0' )
		{
			if (lst->str[i] == '\n')
				return (line[k++] = '\n', line[k++] = '\0', line);
			line[k++] = lst->str[i++];
		}
		lst = lst->next;
	}
	return (line[k++] = '\0', line);
}

t_list	*ft_copy_del_lst(t_list **lst, int nb_char)
{
	t_list			*newlst;
	t_list			*temp;
	int				index;

	index = ft_check_index_new_line(*lst);
	temp = *lst;
	if ((index + 1) < nb_char)
	{
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		newlst = malloc(sizeof(t_list));
		if (!newlst)
			return (ft_free(lst), NULL);
		newlst->str = ft_strdup(&(*lst)->str[index + 1]);
		newlst->next = NULL;
		*lst = temp;
		ft_free(lst);
		if (!newlst->str)
			return (free(newlst), NULL);
		return (newlst);
	}
	else
		return (ft_free(lst), NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;
	int				nl_index;
	int				nb_char;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (ft_free(&lst), NULL);
	if (!lst)
	{
		nb_char = ft_buff_to_lst(&lst, fd);
		if (nb_char < 0)
			return (NULL);
	}
	else
		nb_char = ft_strlen(lst->str);
	nl_index = ft_check_index_new_line(lst);
	while (nl_index < 0 && nb_char != 0)
	{
		nb_char = ft_buff_to_lst(&lst, fd);
		if (nb_char < 0)
			return (NULL);
		nl_index = ft_check_index_new_line(lst);
	}
	line = ft_fill_line(lst);
	if (!line)
		return(NULL);
	lst = ft_copy_del_lst(&lst, nb_char);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
	const char *path = "/home/anferre/sgoinfre/goinfre/Perso/anferre/MyGit/My_Get_next_line/test.txt";
	int fd;             
	char	*str = "start";

	fd=open(path, O_RDONLY);
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("LINE = $%s$ \n", str);
		free (str);
	}
	printf("%d", close(fd));
	return (0);
}