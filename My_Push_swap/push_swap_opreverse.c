/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opreverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:37:41 by anferre           #+#    #+#             */
/*   Updated: 2024/02/06 11:45:03 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*temppile;
	t_stack	*curpile;

	curpile = *head;
	while (curpile->next->next != NULL)
		curpile = curpile->next;
	temppile = curpile;
	curpile = curpile->next;
	temppile->next = NULL;
	temppile = curpile;
	curpile = *head;
	(*head) = temppile;
	(*head)->next = curpile;
}

void	ft_rra(t_stack **head_a)
{
	ft_reverse_rotate(head_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **head_b)
{
	ft_reverse_rotate(head_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **head_a, t_stack **head_b)
{
	ft_reverse_rotate(head_a);
	ft_reverse_rotate(head_b);
	write(1, "rrr\n", 4);
}
