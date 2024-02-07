/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_old.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:40:44 by anferre           #+#    #+#             */
/*   Updated: 2024/02/02 16:53:35 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "include/push_swap.h"

/*
void	ft_put_all_b(t_stack **head_a, t_stack **head_b, int size_a);
void	ft_sort_in_a(t_stack **head_a, t_stack **head_b, int size_a, int size_b);
int		ft_get_prev_index(t_stack *head_a, t_stack *head_b, int	*ctprevindex);
int		ft_get_next_index(t_stack *head_a, t_stack *head_b, int	*ctnextindex);
int		ft_choose_path(int nextindex, int previndex, int closeindex, int size_a, int size_b, int ctnextindex, int ctprevindex);
*/

void	ft_put_all_b(t_stack **head_a, t_stack **head_b, int size_a)
{
	int	size;

	size = ft_stacksize(*head_a);
	while (head_a && size > 0 && ft_stacksize(*head_a) >  3)
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
		ft_pb(head_a, head_b);
		if (ft_stacksize(*head_b) == (((size / 3) * 2) + 2))
			if ((*head_b)->next->index >(*head_b)->index)
				ft_sb(head_b);
		if (ft_stacksize(*head_b) > 3)
			if ((*head_b)->next->index > (*head_b)->index)
				if ((*head_b)->next->index > (*head_b)->next->next->index)
					if ((*head_b)->next->next->index < (*head_b)->index)
						ft_sb(head_b);
	}
		
}

int	ft_get_next_index(t_stack *head_a, t_stack *head_b, int	*ctnextindex)
{
	int		nextindex;
	int		index;
	int 	ct;
	t_stack	*temppile;
	
	nextindex = 1;
	ct = 0;
	index = head_a->index;
	temppile = head_a;
	*ctnextindex = 0;
	while (head_a)
	{
		if (head_a->index == index + 1)
		{
			index++;
			head_a = temppile;
			*ctnextindex = ct;
			ct = 0;
		}
		else
		{
			head_a = head_a->next;
			ct++;
		}
	}
	while (head_b)
	{
		if (head_b->index == index + 1)
			return (nextindex);
		nextindex++;
		head_b = head_b->next;
	}
	return (-1);
}

int	ft_get_prev_index(t_stack *head_a, t_stack *head_b, int	*ctprevindex)
{
	int		previndex;
	int		index;
	int		ct;
	t_stack	*temppile;
	
	previndex = 0;
	ct = 0;
	index = head_a->index;
	temppile = head_a;
	*ctprevindex = 0;
	while (head_a)
	{
		if (head_a->index == index - 1)
		{
			index--;
			*ctprevindex = ct;
			head_a = temppile;
			ct = 0;
		}
		else
		{
			head_a = head_a->next;
			ct++;
		}
	}
	while (head_b)
	{
		if (head_b->index == index - 1)
			return (previndex);
		previndex++;
		head_b = head_b->next;
	}
	return (-1);
}

int	ft_shorter_path(t_stack *head_a, t_stack *head_b)
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

int	ft_choose_path(int nextindex, int previndex, int closeindex, int size_a, int size_b, int ctnextindex, int ctprevindex)
{
	int diffnext;
	int	diffprev;
	int	diffclose;
	
	if (closeindex <= size_a / 2)
		diffclose = closeindex;
	else
		diffclose = size_a - closeindex;
	if (nextindex < 0)
		diffnext = size_a + size_b;
	else if (nextindex <= size_b / 2)
	{
		if (ctnextindex <= size_a / 2)
			diffnext = nextindex + ctnextindex;
		else
			diffnext = nextindex + (size_a - ctnextindex);
	}
	else
	{
		if (ctnextindex <= size_a / 2)
			diffnext = size_b - nextindex + ctnextindex;
		else
			diffnext = (size_b - nextindex) + (size_a - ctnextindex);
	}
	if (previndex < 0)
		diffprev = size_a + size_b;
	else if (previndex <= size_b / 2)
	{
		if (ctprevindex <= size_a / 2)
			diffprev = previndex + ctprevindex;
		else
			diffprev = previndex + (size_a - ctprevindex);
	}
	else
	{
		if (ctprevindex <= size_a / 2)
			diffprev = size_b - previndex + ctprevindex;
		else
			diffprev = (size_b - previndex) + (size_a - ctprevindex);
	}
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
	int ctnextindex;
	int	ctprevindex;
	
	temp = size_b + 3;
	ct = 0;
	ctprevindex = 0;
	ctnextindex = 0;
	while (*head_b != NULL)
	{
		ft_check_opti_b(head_b, head_a);
		nextindex = ft_get_next_index(*head_a, *head_b, &ctnextindex);
		previndex = ft_get_prev_index(*head_a, *head_b, &ctprevindex);
		closeindex = ft_shorter_path(*head_a, *head_b);
		size_b = ft_stacksize(*head_b);
		size_a = ft_stacksize(*head_a);
		path = ft_choose_path(nextindex, previndex, closeindex, size_a, size_b, ctnextindex, ctprevindex);
		if (path == 0)/*previndex*/
		{
			if (ctprevindex<= (size_a / 2))
			{
				while (ctprevindex)
				{
					ft_ra(head_a);
					ctprevindex--;
				}
			}
			else
			{
				while (size_a - ctprevindex != 0)
				{
					ft_rra(head_a);
					ctprevindex++;
				}
			}
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
			if (ctnextindex<= (size_a / 2))
			{
				while (ctnextindex)
				{
					ft_ra(head_a);
					ctnextindex--;
				}
			}
			else
			{
				while (size_a - ctnextindex != 0)
				{
					ft_rra(head_a);
					ctnextindex++;
				}
			}
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
			}
			else if (closeindex > 0 && closeindex < size_a)
			{
				if (closeindex <= size_a / 2)
				{
					while (closeindex)#include "pushswap.h"
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
void	ft_sort_in_b
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
	ft_sort_in_b(head_a, head_b, size_a);
	ft_sort_three(head_a);
	ft_sort_in_a(head_a, head_b, size_a, size_b);
	ft_order(head_a);
}