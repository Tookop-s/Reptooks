/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:58:59 by anferre           #+#    #+#             */
/*   Updated: 2024/01/24 14:46:22 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//check that the str has the good format
int	ft_check_str(char *str)
{
	int	i;
	
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (str[i] && (str[i] < '0' || str[i] > '9'))
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

void	*ft_parse(char **argv, int argc, t_stack *head_a)
{
	int		i;
	int 	j;
	t_stack *pile_a;
	char	**str;

	i = 1;
	j = 0;
	pile_a = head_a;
	if (argc == 2)
	{
	 	str = ft_split(argv[1], ' ');
		while (str[j])
		{
			if (ft_check_str(str[j]))
			{
				pile_a->nb = ft_atoi(str[j]);
				if (ft_check_int(pile_a->nb, head_a) > 1)
					return (ft_error(), NULL);
			}
			else
				return (ft_error(), NULL);
			if (str[++j])
			{
				pile_a->next = ft_stacknew();
				pile_a = pile_a->next;
			}
		}
	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free (str);
	}
	else
	{
		while (i <= argc - 1)
		{
			if (ft_check_str(argv[i]))
			{
				pile_a->nb = ft_atoi(argv[i]);
				if (ft_check_int(pile_a->nb, head_a) > 1)
					return (ft_error(), NULL);
			}
			else
				return (ft_error(), NULL);
			if (i < argc - 1)
			{
				pile_a->next = ft_stacknew();
				pile_a = pile_a->next;
			}
			i++;
		}
	}
	ft_rank_stack(head_a);
	return (head_a);
}

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
