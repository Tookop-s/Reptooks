/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:36:34 by anferre           #+#    #+#             */
/*   Updated: 2023/12/15 12:51:24 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_lst_size(t_list *lst)
{
	unsigned int i;

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
	unsigned int	j;
	char			*str;

	j = 0;
	i = 0;
	while (s[j])
		j++;
	str = (char *)malloc((j + 1) * sizeof(str));
	if (!str)
		return (free(s), NULL);
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
		return (ft_free(lst), free(str), NULL);
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
	return (*lst);
}

void	*ft_free(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!*lst)
		return(NULL);
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

