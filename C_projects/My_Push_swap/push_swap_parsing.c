/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:58:59 by anferre           #+#    #+#             */
/*   Updated: 2024/02/06 15:54:22 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

//parse when the arg is a string
int	ft_parse_split(t_stack *pile_a, t_stack **head_a, int j, char **str)
{
	while (str[j])
	{
		if (ft_check_args(str[j]))
		{
			pile_a->nb = ft_atoi(str[j]);
			if (ft_check_int(pile_a->nb, *head_a) > 1)
				return (ft_error(), ft_free(str, head_a), -1);
		}
		else
			return (ft_error(), ft_free(str, head_a), -1);
		if (str[++j])
		{
			pile_a->next = ft_stacknew();
			pile_a = pile_a->next;
		}
	}
	ft_free(str, NULL);
	return (0);
}

//parse when the args are separated
int	ft_parse_argv(char **argv, int argc, t_stack **head_a, t_stack *pile_a)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (ft_check_args(argv[i]))
		{
			pile_a->nb = ft_atoi(argv[i]);
			if (ft_check_int(pile_a->nb, *head_a) > 1)
				return (ft_error(), ft_stackclear(head_a), -1);
		}
		else
			return (ft_error(), ft_stackclear(head_a), -1);
		if (i < argc - 1)
		{
			pile_a->next = ft_stacknew();
			pile_a = pile_a->next;
		}
		i++;
	}
	return (0);
}

void	*ft_parse(char **argv, int argc, t_stack *head_a)
{
	int		j;
	char	**str;
	t_stack	*pile_a;

	j = 0;
	pile_a = head_a;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (ft_parse_split(pile_a, &head_a, j, str) < 0)
			return (NULL);
	}
	else
	{
		if (ft_parse_argv(argv, argc, &head_a, pile_a) < 0)
			return (NULL);
	}
	ft_rank_stack(head_a);
	return (head_a);
}
