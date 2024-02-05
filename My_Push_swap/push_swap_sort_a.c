/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:18:02 by anferre           #+#    #+#             */
/*   Updated: 2024/02/05 15:50:15 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_do_ops_2(t_stack **head_a, t_stack **head_b, t_stack *temppile)
{
	while (temppile->rra)
	{
		ft_rra(head_a);
		temppile->rra--;
	}
	while (temppile->rrb)
	{
		ft_rrb(head_b);
		temppile->rrb--;
	}
	while (temppile->rrr)
	{
		ft_rrr(head_a, head_b);
		temppile->rrr--;
	}
}

//execute the different operations
void	ft_do_ops(t_stack **head_a, t_stack **head_b, t_stack *temppile)
{
	while (temppile->ra)
	{
		ft_ra(head_a);
		temppile->ra--;
	}
	while (temppile->rb)
	{
		ft_rb(head_b);
		temppile->rb--;
	}
	while (temppile->rr)
	{
		ft_rr(head_a, head_b);
		temppile->rr--;
	}
	ft_do_ops_2(head_a, head_b, temppile);
	while (temppile->pa)
	{
		ft_pa(head_a, head_b);
		temppile->pa--;
	}
}		

void	ft_sort_in_a(t_stack **head_a, t_stack **head_b, int size)
{
	t_stack	*temppile;

	while (*head_b)
	{
		ft_init_ops(head_b);
		ft_calculate_ops(head_a, head_b, size);
		ft_optimise_rr_rrr(head_b);
		temppile = ft_short_path(*head_b);
		ft_do_ops(head_a, head_b, temppile);
	}
}

//get the index 0 to the top of the stack
void	ft_order(t_stack **head_a)
{
	int	size_a;

	size_a = ft_stacksize(*head_a);
	while ((*head_a)->index != 0)
	{
		if ((*head_a)->index > size_a / 2)
			ft_ra(head_a);
		else
			ft_rra(head_a);
	}
}
