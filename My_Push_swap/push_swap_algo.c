/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:18:02 by anferre           #+#    #+#             */
/*   Updated: 2024/02/02 18:04:21 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_sort_in_block(t_stack **head_a, t_stack **head_b, int size, int j)
{
	int n;
	int i;
	int t;
	int temp_size;
	
	n = 6; /*determiner le coefficient*/
	i = n / 2;
	t = 0;
	temp_size = ft_stacksize(*head_a);
	while (t++ <= temp_size && ft_stacksize(*head_a) > 3)
	{
		if ((*head_a)->index < (size / n * (i - j + 1)) && (*head_a)->index >= (size / n * (i - j)))
		{
			ft_pb(head_a, head_b);
			ft_rb(head_b);
		}
		else if ((*head_a)->index >= (size / n * (i + j - 1)) && (*head_a)->index <= (size / n * (i + j)))
		{
			ft_pb(head_a, head_b);
		}
		else
			ft_ra(head_a);
	}
}

void	ft_sort_in_b(t_stack **head_a, t_stack **head_b, int size)
{
	int j;
	
	j = 1;
	while (ft_stacksize(*head_a) > 3)
	{
		ft_sort_in_block(head_a, head_b, size, j);
		j++;
	}
}


void	ft_sort_three(t_stack **head_a)
{
	t_stack	*temppile;
	int		index[3];

	temppile = *head_a;
	index[0] = temppile->index;
	temppile = temppile->next;
	index[1] = temppile->index;
	temppile = temppile->next;
	index[2] = temppile->index;
	if (index[0] < index[1] && index[1] > index[2] && index[0] < index[2])
		ft_sa(head_a);
	else if (index[0] > index[1] && index[0] < index[2] && index[1] < index[2])
		ft_sa(head_a);
	else if (index[0] > index[1] && index[1] > index[2])
		ft_sa(head_a);
}

void	ft_init_ops(t_stack **head_b)
{
	t_stack *tempile;
	
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

int	ft_ops_a(t_stack *head_a, int index)
{
	int ct;
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

void	ft_calculate_ops(t_stack **head_a, t_stack **head_b, int size_a)
{
	int i;
	int temp;
	int size_b;
	t_stack	*temppile;

	i = 0;
	temppile = *head_b;
	while (temppile)
	{
		size_a = ft_stacksize(*head_a);
		size_b = ft_stacksize(*head_b);
		if (i < size_b / 2)
			temppile->rb = i;
		else
			temppile->rrb = size_b - i;
		temp = ft_ops_a(*head_a, temppile->index);
		if (temp < size_a / 2)
			temppile->ra = temp;
		else
			temppile->rra = size_a - temp;
		i++;
		temppile = temppile->next;
	}
	
}

void	ft_optimise_rr_rrr(t_stack **head_b)
{
	t_stack *temppile;

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

t_stack *ft_short_path(t_stack *head_b)
{
	t_stack *temppile;

	temppile = head_b;
	while (head_b)
	{
		if (head_b->totops < temppile->totops)
			temppile = head_b;
		head_b = head_b->next;
	}
	return (temppile);
}

void	ft_do_ops(t_stack **head_a, t_stack **head_b, t_stack *temppile)
{
	while (temppile->ra--)
		ft_ra(head_a);
	while (temppile->rb--)
		ft_rb(head_b);
	while (temppile->rr--)
		ft_rr(head_a, head_b);
	while (temppile->rra--)
		ft_rra(head_a);
	while (temppile->rrb--)
		ft_rrb(head_b);
	while (temppile->rrr--)
		ft_rrr(head_a, head_b);
	while (temppile->pa--)
		ft_pa(head_a, head_b);
}

void	ft_sort_in_a(t_stack **head_a, t_stack **head_b, int size)
{
	t_stack *temppile;

	while (head_b)
	{
		ft_init_ops(head_b);
		ft_calculate_ops(head_a, head_b, size);
		ft_optimise_rr_rrr(head_b);
		temppile = ft_short_path(*head_b);
		ft_do_ops(head_a, head_b, temppile);
	}
}


void	ft_sort(t_stack **head_a, t_stack **head_b)
{
	int size;
	
	size = ft_stacksize(*head_a);
	if (size <= 2)
	{
		if(ft_is_sorted(*head_a))
			exit(0);
		else
			ft_sa(head_a);
		exit(0);
	}
	ft_sort_in_b(head_a, head_b, size);
	ft_sort_three(head_a);
	ft_sort_in_a(head_a, head_b, size);
	// ft_order(head_a); /* a faire */
}