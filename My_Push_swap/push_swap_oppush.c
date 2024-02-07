/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_oppush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:37:41 by anferre           #+#    #+#             */
/*   Updated: 2024/02/06 11:45:07 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_push(t_stack **head_move, t_stack **head_receive)
{
	t_stack	*temppile;

	if (ft_stacksize(*head_move) >= 1)
	{
		temppile = *head_move;
		*head_move = (*head_move)->next;
		temppile->next = *head_receive;
		*head_receive = temppile;
	}
}

void	ft_pa(t_stack **head_a, t_stack **head_b)
{
	ft_push(head_b, head_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **head_a, t_stack **head_b)
{
	ft_push(head_a, head_b);
	write(1, "pb\n", 3);
}
