/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:37:41 by anferre           #+#    #+#             */
/*   Updated: 2024/01/24 16:28:48 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if 2 numbers swap
void	ft_swap(t_stack **head)
{
	t_stack	*temppile;
	t_stack	*curpile;
	
	curpile = *head;
	if (ft_stacksize(*head) >= 2)
	{
		temppile = curpile;
		curpile = curpile->next;
		*head = curpile;
		curpile = curpile->next;
		(*head)->next = temppile;
		temppile->next = curpile;
	}
}

void	ft_sa(t_stack **head_a)
{
	ft_swap(head_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **head_b)
{
	ft_swap(head_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **head_a, t_stack **head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
	write(1, "ss\n", 3);
}
