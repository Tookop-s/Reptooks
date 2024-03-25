/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:41:35 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:45:01 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	else
	{
		del(lst->content);
		free(lst);
	}
}

//delete and free the memory of the given node
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
// 	ft_lstdelone(&m, *del);
// 	printf("%s\n", (char *)m->content);
// }