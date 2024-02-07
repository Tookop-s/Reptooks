/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:18:02 by anferre           #+#    #+#             */
/*   Updated: 2024/02/07 16:04:02 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_init_ops(t_stack **head_b)
{
	t_stack	*tempile;

	tempile = *head_b;
	while (tempile)
	{
		tempile->pa = 1;
		tempile->ra = 0;
		tempile->rb = 0;
		tempile->rr = 0;
		tempile->rra = 0;
		tempile->rrb = 0;
		tempile->rrr = 0;
		tempile->totops = 0;
		tempile = tempile->next;
	}	
}

//get the number of moves for the stack a
int	ft_ops_a(t_stack *head_a, int index)
{
	int		ct;
	t_stack	*temppile;

	ct = 0;
	if (index < head_a->index && index > ft_stacklast(head_a)->index)
		return (ct);
	temppile = head_a;
	head_a = head_a->next;
	ct++;
	while (head_a)
	{
		if (index < head_a->index && index > temppile->index)
			return (ct);
		else if (index > head_a->index && index > temppile->index \
		&& temppile->index > head_a->index)
			return (ct);
		else if (index < head_a->index && index < temppile->index \
		&& temppile->index > head_a->index)
			return (ct);
		temppile = head_a;
		head_a = head_a->next;
		ct++;
	}
	return (ct);
}

//get the number of moves for the stack b & calls ops_a
void	ft_calculate_ops(t_stack **head_a, t_stack **head_b, int size_a)
{
	int		i;
	int		temp;
	int		size_b;
	t_stack	*temppile;

	i = 0;
	temppile = *head_b;
	while (temppile)
	{
		size_a = ft_stacksize(*head_a);
		size_b = ft_stacksize(*head_b);
		if (i <= size_b / 2)
			temppile->rb = i;
		else
			temppile->rrb = size_b - i;
		temp = ft_ops_a(*head_a, temppile->index);
		if (temp <= size_a / 2)
			temppile->ra = temp;
		else
			temppile->rra = size_a - temp;
		i++;
		temppile = temppile->next;
	}
}

//transforms ra and rb in rr and rra and rrb in rrr
void	ft_optimise_rr_rrr(t_stack **head_b)
{
	t_stack	*temppile;

	temppile = *head_b;
	while (temppile)
	{
		while (temppile->ra && temppile->rb)
		{
			temppile->rr++;
			temppile->ra--;
			temppile->rb--;
		}
		while (temppile->rra && temppile->rrb)
		{
			temppile->rrr++;
			temppile->rra--;
			temppile->rrb--;
		}
		temppile->totops = temppile->pa + temppile->ra + temppile->rb \
		+ temppile->rr + temppile->rra + temppile->rrb + temppile->rrr;
		temppile = temppile->next;
	}
}

//get the t_stack node tha has the lowest nb of moves
t_stack	*ft_short_path(t_stack *head_b)
{
	t_stack	*temppile;

	temppile = head_b;
	while (head_b)
	{
		if (head_b->totops < temppile->totops)
			temppile = head_b;
		head_b = head_b->next;
	}
	return (temppile);
}
