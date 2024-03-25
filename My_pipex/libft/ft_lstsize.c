/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:30:58 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 13:34:10 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

//return the size of the list
// #include<stdio.h>
// int main()
// {
// 	t_list *l = ft_lstnew(ft_strdup("a"));
// 	l->next = ft_lstnew(ft_strdup("b"));
// 	l->next->next = ft_lstnew(ft_strdup("c"));
// 	printf("%d\n", ft_lstsize(l));
// }