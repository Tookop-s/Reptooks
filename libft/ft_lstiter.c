/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:58:16 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:56:36 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

//iterates the list and applies the funtion f to each node
// void	f(void *content)
// {
// 	unsigned int i = 0;
// 	char *s;
// 	s = content;
// 	while (s[i])
// 	{
// 		 if (s[i] >= 'a' && s[i] <= 'z')
// 	 		s[i] -= 32;
// 		i++;
// 	}
// 	return ;
// }
// #include<stdio.h>
// int main()
// {
// 	t_list *l = ft_lstnew(ft_strdup("a"));
// 	l->next = ft_lstnew(ft_strdup("b"));
// 	l->next->next = ft_lstnew(ft_strdup("c"));
// 	printf("%s\n", (char *)l->content);
// 	printf("%s\n", (char *)l->next->content);
// 	printf("%s\n", (char *)l->next->next->content);
// 	ft_lstiter(l, f);
// 	printf("%s\n", (char *)l->content);
// 	printf("%s\n", (char *)l->next->content);
// 	printf("%s\n", (char *)l->next->next->content);
// }