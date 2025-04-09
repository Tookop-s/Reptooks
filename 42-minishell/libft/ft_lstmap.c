/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:40 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/21 19:09:50 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;
	void	*cont;

	if (!lst || !f || !del)
		return (0);
	cont = f(lst->content);
	new_list = ft_lstnew(cont);
	if (!new_list)
	{
		del(cont);
		return (NULL);
	}
	temp = new_list;
	lst = lst->next;
	while (lst)
	{
		cont = f(lst->content);
		new_list->next = ft_lstnew(cont);
		if (!new_list->next)
			return (del(cont), ft_lstclear(&temp, del), NULL);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (temp);
}

//	Itère sur la liste ’lst’ et applique la fonction
//	’f ’au contenu de chaque élément. Crée une nouvelle
//	liste résultant des applications successives de
//	’f’. La fonction ’del’ est là pour détruire le
//	contenu d’un élément si nécessaire.