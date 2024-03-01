/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:36:31 by anferre           #+#    #+#             */
/*   Updated: 2024/03/01 16:26:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_index_new_line(t_lst *lst)
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

int	ft_buff_to_lst(t_lst **lst, int fd)
{
	int		nb_char;
	char	*buff;
	t_lst	*temp;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(lst), -1);
	nb_char = read(fd, buff, BUFFER_SIZE);
	buff[nb_char] = '\0';
	if (nb_char > 0)
	{
		temp = ft_lstnew_back(buff, lst);
		free(buff);
		if (temp == NULL)
			return (ft_free(lst), -1);
		return (nb_char);
	}
	else
		return (free(buff), -1);
}

char	*ft_fill_line(t_lst *lst)
{
	int		i;
	int		lstsize;
	char	*line;
	t_lst	*temp;

	i = 0;
	temp = lst;
	lstsize = 0;
	if (lst->next != NULL)
	{
		lstsize = ft_strindex(lst->str, '\n');
		i -= 1;
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	lstsize += BUFFER_SIZE * i + ft_strindex(lst->str, '\n');
	line = malloc((lstsize + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line = ft_lst_to_line(line, temp);
	return (line);
}

t_lst	*ft_copy_del_lst(t_lst **lst, int nb_char)
{
	t_lst			*newlst;
	t_lst			*temp;
	int				index;

	index = ft_check_index_new_line(*lst);
	temp = *lst;
	if ((index + 1) < nb_char && index >= 0)
	{
		while (temp->next != NULL)
			temp = temp->next;
		newlst = malloc(sizeof(t_lst));
		if (!newlst)
			return (ft_free(lst), NULL);
		newlst->str = ft_strdup(&temp->str[index + 1]);
		newlst->next = NULL;
		if (!newlst->str)
			return (free(newlst), ft_free(lst), NULL);
		ft_free(lst);
		return (newlst);
	}
	else
		return (ft_free(lst), NULL);
}

char	*get_next_line(int fd)
{
	static t_lst	*lst;
	char			*line;
	int				nb_char;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (ft_free(&lst), NULL);
	if (!lst)
	{
		nb_char = ft_buff_to_lst(&lst, fd);
		if (nb_char < 0 && !lst)
			return (NULL);
	}
	else
		nb_char = ft_strindex(lst->str, '\0');
	while (ft_check_index_new_line(lst) < 0 && nb_char > 0)
		nb_char = ft_buff_to_lst(&lst, fd);
	if (nb_char < 0 && !lst)
		return (NULL);
	line = ft_fill_line(lst);
	if (!line)
		return (ft_free(&lst), NULL);
	lst = ft_copy_del_lst(&lst, nb_char);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
// 	const char *path = "/home/anferre/sgoinfre/
//goinfre/Perso/anferre/MyGit/My_Get_next_line/test.txt";
// 	int fd;             
// 	char	*str = "start";
// 	fd =open(path, O_RDONLY);
// 	while (str != NULL)
// 	{
// 		str = get_next_line(fd);
// 		printf("LINE = $%s$ \n", str);
// 		free (str);
// 	}
// 	printf("%d", close(fd));
// 	return (0);
// }