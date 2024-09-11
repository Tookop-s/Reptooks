/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:02:30 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 19:08:33 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*p;

	if (!lst || !f || !del)
		return (NULL);
	p = f(lst->content);
	new = ft_lstnew(p);
	if (!new)
		return (del(p), NULL);
	temp = new;
	lst = lst->next;
	while (lst != NULL)
	{
		p = f(lst->content);
		new->next = ft_lstnew(p);
		if (!new->next)
			return (del(p), ft_lstclear(&temp, del), NULL);
		lst = lst->next;
		new = new->next;
	}
	return (temp);
}
// creates a new list with the content of lst modified by the function f 
// void	*f(void *content)
// {
// 	unsigned int i = 0;
// 	char *s;
// 	void *p;
// 	s = content;
// 	while (s[i])
// 	{
// 		 if (s[i] >= 'a' && s[i] <= 'z')
// 	 		s[i] -= 32;
// 		i++;
// 	}
// 	p = s;
// 	return (p);
// }
// void del(void *content)
// {
// 		free(content);
// }
// #include<stdio.h>
// int main()
// {
// 	t_list *l = ft_lstnew(ft_strdup("abc"));
// 	t_list *me;
// 	l->next = ft_lstnew(ft_strdup(" c d u"));
// 	l->next->next = ft_lstnew(ft_strdup(" p l   tr"));
// 	me = ft_lstmap(l, &f, del);
// 	printf("%p\n", me->content);
// 	printf("%p\n", me->next->content);
// 	printf("%p\n", me->next->next->content);
// }
