/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:34:36 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:59:52 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

//return the last node of a list 
//  #include<stdio.h>
// int main()
// {
// 	t_list *l = ft_lstnew(ft_strdup("a"));
// 	l->next = ft_lstnew(ft_strdup("b"));
// 	l->next->next = ft_lstnew(ft_strdup("c"));
// 	printf("%s\n", (char *)l->content);
// 	printf("%s\n", (char *)l->next->content);
// 	printf("%s\n", (char *)l->next->next->content);
// 	printf("last node = %s\n", (char *)ft_lstlast(l)->content);
// }