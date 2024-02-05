/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:58:59 by anferre           #+#    #+#             */
/*   Updated: 2024/02/05 14:02:00 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	ft_is_sorted(t_stack *head_a)
{
	int	i;

	i = 0;
	while (head_a)
	{
		if (head_a->index != i)
			return (0);
		i++;
		head_a = head_a->next;
	}
	return (1);
}
