/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_oprotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:37:41 by anferre           #+#    #+#             */
/*   Updated: 2024/02/06 11:45:00 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_rotate(t_stack **head)
{
	t_stack	*temppile;
	t_stack	*curpile;

	if (ft_stacksize(*head) >= 2)
	{
		temppile = *head;
		*head = (*head)->next;
		curpile = *head;
		while (curpile->next != NULL)
			curpile = curpile->next;
		curpile->next = temppile;
		temppile->next = NULL;
	}
}

void	ft_ra(t_stack **head_a)
{
	ft_rotate(head_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **head_b)
{
	ft_rotate(head_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **head_a, t_stack **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	write(1, "rr\n", 3);
}
