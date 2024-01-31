/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:40:44 by anferre           #+#    #+#             */
/*   Updated: 2024/01/31 13:31:12 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_put_all_b(t_stack **head_a, t_stack **head_b, int size_a)
{
	int	size;

	size = ft_stacksize(*head_a);
	while (head_a && size > 0)
	{
		if ((*head_a)->index < (size_a / 3))
		{
			ft_pb(head_a, head_b);
			ft_rb(head_b);
		}
		else if ((*head_a)->index > ((size_a / 3) * 2))
			ft_ra(head_a);
		else 
			ft_pb(head_a, head_b);
		size--;
		if (ft_stacksize(*head_b) > 3)
		{
			if ((*head_b)->next->index > (*head_b)->index)
				if ((*head_b)->next->index > (*head_b)->next->next->index)
					if ((*head_b)->next->next->index < (*head_b)->index)
						ft_sb(head_b);
		}
		if (ft_stacksize(*head_b) == 2)
			if ((*head_b)->next->index >(*head_b)->index)
				ft_sb(head_b);
	}
	while (ft_stacksize(*head_a) > 3)
	{
		if (ft_stacksize(*head_b) == (((size / 3) * 2) + 2))
			if ((*head_b)->next->index >(*head_b)->index)
				ft_sb(head_b);
		ft_pb(head_a, head_b);
		if (ft_stacksize(*head_b) > 3)
			if ((*head_b)->next->index > (*head_b)->index)
				if ((*head_b)->next->index > (*head_b)->next->next->index)
					if ((*head_b)->next->next->index < (*head_b)->index)
						ft_sb(head_b);
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
	return (-1);
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
	return (-1);
}

int	ft_short_path(t_stack *head_a, t_stack *head_b)
{
	t_stack *temppile;
	int		ct;

	ct = 1;
	temppile = head_a;
	head_a = head_a->next;
	while (head_a != NULL)
	{
		if (head_b->index > temppile->index && head_b->index < head_a->index)
			return (ct);
		if (temppile->index > head_a->index && head_b->index > temppile->index )
			return (ct);
		if (temppile->index > head_a->index && head_b->index < head_a->index )
			return (ct);
		temppile = head_a;
		head_a = head_a->next;
		ct++;
	}
	return (ct);
}

int	ft_choose_path(int nextindex, int previndex, int closeindex, int size_a, int size_b)
{
	int diffnext;
	int	diffprev;
	int	diffclose;
	
	if (closeindex <= size_a/2)
		diffclose = closeindex;
	else
		diffclose = size_a - closeindex;
	if (nextindex < 0)
		diffnext = size_a + size_b;
	else if (nextindex <= size_b/2)
		diffnext = nextindex;
	else
		diffnext = size_b - nextindex;
	if (previndex < 0)
		diffprev = size_a + size_b;
	else if (previndex <= size_b/2)
		diffprev = previndex;
	else
		diffprev = size_b - previndex;
	if (diffprev <= diffnext && diffprev <= diffclose)
		return(0);
	else if (diffnext < diffprev && diffnext < diffclose)
		return (1);
	else
		return (2);
}

void	ft_check_opti_b(t_stack **head_b, t_stack **head_a)
{
	while ((*head_a)->index - ft_stacklast(*head_b)->index < (*head_a)->index - (*head_b)->index)
		ft_rrb(head_b);
}

void	ft_sort_in_a(t_stack **head_a, t_stack **head_b, int size_a, int size_b)
{
	int	path;
	int ct;
	int nextindex;
	int previndex;
	int	closeindex;
	int temp;
	
	temp = size_b;
	ct = 0;
	while (*head_b != NULL)
	{
		ft_check_opti_b(head_b, head_a);
		nextindex = ft_get_next_index(ft_stacklast(*head_a)->index, *head_b);
		previndex = ft_get_prev_index((*head_a)->index, *head_b);
		closeindex = ft_short_path(*head_a, *head_b);
		size_b = ft_stacksize(*head_b);
		size_a = ft_stacksize(*head_a);
		path = ft_choose_path(nextindex, previndex, closeindex, size_a, size_b);
		if (path == 0)/*previndex*/
		{
			
			if (previndex <= (size_b / 2))
			{
				while (previndex != 0)
				{
					ft_rb(head_b);
					ct++;
					previndex--;
				}
				ft_pa(head_a, head_b);
			}
			else
			{
				while ((size_b - previndex) != 0)
				{
					ft_rrb(head_b);
					previndex++;
				}
				ft_pa(head_a, head_b);
			}
		}
		else if (path == 1)/*nextindex*/
		{
			if (nextindex <= (size_b / 2))
			{
				while (nextindex)
				{
					ft_rb(head_b);
					ct++;
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
		}
		else if (path == 2)/*closeindex*/
		{
			if (closeindex == size_a || closeindex == 0)
			{
				ft_pa(head_a, head_b);
				while ((*head_b)->index < (*head_a)->index && (*head_b)->index > ft_stacklast(*head_a)->index)
					ft_pa(head_a, head_b);
			}
			else if (closeindex > 0 && closeindex < size_a)
			{
				if (closeindex <= size_a / 2)
				{
					while (closeindex)
					{
						ft_ra(head_a);
						closeindex--;
					}
					ft_pa(head_a, head_b);
				}
				else
				{
					while (closeindex != size_a)
					{
						ft_rra(head_a);
						closeindex++;
					}
					ft_pa(head_a, head_b);
				}
			}
		}
	}

}

void	ft_order(t_stack **head_a)
{
	while ((*head_a)->index != 0)
		ft_rra(head_a);
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

void	ft_sort(t_stack **head_a, t_stack **head_b)
{
	int	size_a;
	int size_b;

	size_a = ft_stacksize(*head_a);
	size_b = ft_stacksize(*head_b);
	if (size_a <= 2)
	{
		if(ft_is_sorted(*head_a))
			exit(0);
		else
			ft_sa(head_a);
	}
	ft_put_all_b(head_a, head_b, size_a);
	ft_sort_three(head_a);
	ft_sort_in_a(head_a, head_b, size_a, size_b);
	ft_order(head_a);
}