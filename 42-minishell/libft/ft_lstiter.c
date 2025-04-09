/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:24:11 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/22 12:11:54 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst)
	{
		while (lst != NULL)
		{
			temp = (lst)->next;
			f(lst->content);
			(lst) = temp;
		}
	}
	return ;
}

//	Itère sur la liste ’lst’ et applique la fonction
//	’f’ au contenu chaque élément.