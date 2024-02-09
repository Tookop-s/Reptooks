/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:58:59 by anferre           #+#    #+#             */
/*   Updated: 2024/02/09 11:13:35 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

//check that the str has the good format
int	ft_check_args(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 11)
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (0);
	return (1);
}

//check for min-max int and duplicates
int	ft_check_int(long nb, t_stack *head_a)
{
	int	i;

	i = 0;
	if (nb < -2147483648 || nb > 2147483647)
		return (2);
	while (head_a)
	{
		if (head_a->nb == nb)
			i++;
		head_a = head_a->next;
	}
	return (i);
}

//get the index for all of the stack
void	ft_rank_stack(t_stack *head_a)
{
	t_stack	*temppile;
	t_stack	*temppile2;
	long	nbtemp;
	int		index;

	temppile = head_a;
	temppile2 = head_a;
	while (temppile2)
	{
		nbtemp = temppile2->nb;
		index = 0;
		temppile = head_a;
		while (temppile)
		{
			if (nbtemp > temppile->nb)
				index++;
			temppile = temppile->next;
		}
		temppile2->index = index;
		temppile2 = temppile2->next;
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

void	ft_free(char **str, t_stack **head_a)
{
	int	j;

	j = 0;
	if (head_a)
		ft_stackclear(head_a);
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free (str);
}
