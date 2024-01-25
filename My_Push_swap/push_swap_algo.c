/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:40:44 by anferre           #+#    #+#             */
/*   Updated: 2024/01/25 16:43:48 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_put_all_b(t_stack **head_a, t_stack **head_b, int nbp)
{
	while (ft_stacksize(*head_a) > 1)
	{
		
		if ((*head_a)->index > (nbp / 2))
		{
			ft_pb(head_a, head_b);
		}
		else
		{
			ft_pb(head_a, head_b);
			ft_rb(head_b);
		}
	}
}

int	ft_get_next_index(int index, t_stack *head)
{
	int	nextindex;
	
	nextindex = 0;
	while (head)
	{
		if (head->index == index + 1)
			return (nextindex);
		nextindex++;
		head = head->next;
	}
	return (0);
}

int	ft_get_prev_index(int index, t_stack *head)
{
	int	previndex;
	
	previndex = 0;
	while (head)
	{
		if (head->index == index - 1)
			return (previndex);
		previndex++;
		head = head->next;
	}
	return (0);
}

void	ft_sort(t_stack **head_a, t_stack **head_b)
{
	int	size_a;
	int	size_b;
	int nextindex;
	int previndex;
	t_stack *temppile;

	size_a = ft_stacksize(*head_a);
	if (size_a <= 2)
	{
		if(ft_is_sorted(*head_a))
			exit(0);
		else
			ft_sa(head_a);
	}
	ft_put_all_b(head_a, head_b, size_a);
	
	while ((*head_a)->index != 0)
	{
		previndex = ft_get_prev_index((*head_a)->index, *head_b);
		size_b = ft_stacksize(*head_b);
		
			while ((size_b - previndex) != 0)
			{
				ft_rrb(head_b);
				previndex++;
			}
			ft_pa(head_a, head_b);
	}
	while (ft_stacklast(*head_a)->index != (size_a - 1))
	{
		temppile = *head_a;
		while (temppile->next != NULL)
			temppile = temppile->next;
		nextindex = ft_get_next_index(temppile->index, *head_b);
		size_b = ft_stacksize(*head_b);
		if (nextindex <= (size_b / 2))
		{
			while (nextindex)
			{
				ft_rb(head_b);
				nextindex--;
			}
			ft_pa(head_a, head_b);
			ft_ra(head_a);
		}
		else
		{
			while (nextindex < size_b)
			{
				ft_rrb(head_b);
				nextindex++;
			}
			ft_pa(head_a, head_b);
			ft_ra(head_a);
		}
		ft_stacksize(*head_a);
	}
}