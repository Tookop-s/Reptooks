/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:16:12 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:43:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
//add a new list element/node to the end of the list
// #include<stdio.h>

// int main()
// {
// 	t_list *l = ((void*)0);
// 	t_list *m = ft_lstnew(ft_strdup("OK"));
// 	ft_lstadd_back(&l, m);
// 	printf("%d\n",strcmp(l->content, "OK"));
// 	printf("%s\n", (char *)l->content);
// 	free(l);
// }