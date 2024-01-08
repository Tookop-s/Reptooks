/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:36:34 by anferre           #+#    #+#             */
/*   Updated: 2024/01/08 16:18:52 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strindex(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	if (s[i] == '\n' && c =='\n')
		i++;
	return (i);
}

char	*ft_lst_to_line(char *line, t_list *lst)
{
	unsigned int	i;
	unsigned int	k;

	k = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i] != '\0')
		{
			if (lst->str[i] == '\n')
				return (line[k++] = '\n', line[k++] = '\0', line);
			line[k++] = lst->str[i++];
		}
		lst = lst->next;
	}
	line[k++] = '\0';
	return (line);
}

char	*ft_strdup(char *s)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc((ft_strindex(s, '\0') + 1) * sizeof(char));
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
		return (*lst = NULL, NULL);
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
	*lst = NULL;
	lst = NULL;
	return (lst);
}
