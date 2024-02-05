/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:18:02 by anferre           #+#    #+#             */
/*   Updated: 2024/02/05 14:03:50 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_get_n(int size)
{
	int	n;

	n = 0;
	if (size < 300)
		n = 4;
	else
		n = 6;
	return (n);
}

void	ft_sort_in_block(t_stack **head_a, t_stack **head_b, int size, int j)
{
	int	n;
	int	i;
	int	t;
	int	temp_size;

	n = ft_get_n(size);
	i = n / 2;
	t = 0;
	temp_size = ft_stacksize(*head_a);
	while (t++ <= temp_size && ft_stacksize(*head_a) > 3)
	{
		if ((*head_a)->index < (size / n * (i - j + 1)) \
		&& (*head_a)->index >= (size / n * (i - j)))
		{
			ft_pb(head_a, head_b);
			ft_rb(head_b);
		}
		else if ((*head_a)->index >= (size / n * (i + j - 1)) \
		&& (*head_a)->index <= (size / n * (i + j)))
		{
			ft_pb(head_a, head_b);
		}
		else
			ft_ra(head_a);
	}
}

void	ft_sort_in_b(t_stack **head_a, t_stack **head_b, int size)
{
	int	j;

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

void	ft_sort(t_stack **head_a, t_stack **head_b)
{
	int	size;

	size = ft_stacksize(*head_a);
	if (size <= 2)
	{
		if (ft_is_sorted(*head_a))
			exit(0);
		else
			ft_sa(head_a);
		exit(0);
	}
	ft_sort_in_b(head_a, head_b, size);
	ft_sort_three(head_a);
	ft_sort_in_a(head_a, head_b, size);
	ft_order(head_a);
}
