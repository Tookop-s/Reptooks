void	ft_sort_in_a(t_stack **head_a, t_stack **head_b, int size_a)
{
	int	size_b;
	int nextindex;
	int previndex;
	t_stack *temppile;
	
	while ((*head_a)->index != 0)
	{
		previndex = ft_get_prev_index((*head_a)->index, *head_b);
		size_b = ft_stacksize(*head_b);
		if (previndex <= (size_b / 2))
		{
			while (previndex != 0)
			{
				ft_rb(head_b);
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

int	ft_short_path(t_stack *head_a, t_stack *head_b)
{
	t_stack *temppile;
	int	ct;

	ct = 0;
	temppile = head_a;
	head_a = head_a->next;
	while (head_a != NULL)
	{
		if (head_b->index > temppile->index && head_b->index < head_a->index)
			return (ct);
		if (temppile->index > head_a->index && head_b->index > temppile->index)
			return (ct);
		temppile = head_a;
		head_a = head_a->next;
		ct++;
	}
	return (0);
}

void	ft_sort_in_a(t_stack **head_a, t_stack **head_b, int size_a)
{
	int	closeindex;
	int ct;
	
	ct = 0;
	while (head_b != NULL)
	{
		closeindex = ft_short_path(*head_a, *head_b);
		size_a = ft_stacksize(*head_a);
		if (closeindex == size_a)
		{
			ft_pa(head_a, head_b);
			ct++;
			while ((*head_b)->index < (*head_a)->index && (*head_b)->index > ft_stacklast(*head_a)->index)
			{
				ft_pa(head_a, head_b);
				ct++;
			}
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
		else if (closeindex == 0)
		{
			
			ft_pa(head_a, head_b);
			ct++;
		}
		while (ct)
		{
			ft_ra(head_a);
			ct--;
		}
	}
}