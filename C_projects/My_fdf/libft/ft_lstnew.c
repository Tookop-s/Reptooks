/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:55:36 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 18:12:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

//creates and allocate a new list element/node
// #include<stdio.h>
// int main()
// {
// 	t_list *l = ft_lstnew(ft_strdup("abc"));
// 	printf("%s\n", (char *)l->content);
// 	free(l);
// }