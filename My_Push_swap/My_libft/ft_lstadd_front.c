/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:15:10 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:24:27 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

//add a new list element/node to the beginning of the list
// #include<stdio.h>

// int main()
// {
// 	t_list *l = ((void *)0);
// 	t_list *m = ft_lstnew(ft_strdup("OK"));
// 	ft_lstadd_front(&l, m);
// 	printf("%d\n", strcmp(l->content, "OK"));
// 	printf("%s\n", (char *)l->content);
// 	free(l);
// }