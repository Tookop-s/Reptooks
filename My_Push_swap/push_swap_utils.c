/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:58:59 by anferre           #+#    #+#             */
/*   Updated: 2024/01/24 14:59:12 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

t_stack	*ft_stacknew(void)
{
	t_stack	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->nb = 0;
	element->next = NULL;
	return (element);
}

int	ft_stacksize(t_stack *head)
{
	unsigned int	size;

	if (!head)
		return (0);
	size = 1;
	while (head->next != NULL)
	{
		head = head->next;
		size++;
	}
	return (size);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while ((*stack) != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}