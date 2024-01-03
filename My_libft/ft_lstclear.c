/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:46:20 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:44:36 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}

// deletes and free the given element/node and every successors
// void del(void *lst)
// {
// 	free(lst);
// }
// #include<stdio.h>
// int main()
// {
// 	t_list *l = ((void*)0);
// 	t_list *m = ft_lstnew(ft_strdup("OK"));
// 	ft_lstadd_back(&l, m);
// 	printf("%s\n", (char *)m->content);
// 	ft_lstclear(&m, *del);
// 	printf("%s\n", (char *)m->content);
// }