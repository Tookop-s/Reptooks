/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_utils1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:46:04 by anferre           #+#    #+#             */
/*   Updated: 2024/02/07 16:04:11 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap_checker.h"

t_ops	*ft_opsnew(void)
{
	t_ops	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->buff = NULL;
	element->next = NULL;
	return (element);
}

void	ft_opsclear(t_ops **stack)
{
	t_ops	*temp;

	if (!stack)
		return ;
	while ((*stack) != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (temp->buff)
			free(temp->buff);
		free(temp);
	}
	*stack = NULL;
}

void	ft_clear(t_stack **head, t_ops **ops)
{
	if (ops)
		ft_opsclear(ops);
	if (head)
		ft_stackclear(head);
}

void	ft_ko(void)
{
	write(2, "KO/n", 3);
}
