/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:58:59 by anferre           #+#    #+#             */
/*   Updated: 2024/02/05 17:31:00 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

//parse when the arg is a string
void	ft_parse_split(t_stack *pile_a, t_stack **head_a, int j, char **str)
{
	while (str[j])
	{
		if (ft_check_str(str[j]))
		{
			pile_a->nb = ft_atoi(str[j]);
			if (ft_check_int(pile_a->nb, *head_a) > 1)
				return (ft_error(), ft_free(str, head_a), exit(1));
		}
		else
			return (ft_error(), ft_free(str, head_a), exit(1));
		if (str[++j])
		{
			pile_a->next = ft_stacknew();
			pile_a = pile_a->next;
		}
	}
	ft_free(str, NULL);
}

//parse when the args are separated
void	ft_parse_argv(char **argv, int argc, t_stack **head_a, t_stack *pile_a)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (ft_check_str(argv[i]))
		{
			pile_a->nb = ft_atoi(argv[i]);
			if (ft_check_int(pile_a->nb, *head_a) > 1)
				return (ft_error(), ft_stackclear(head_a), exit(1));
		}
		else
			return (ft_error(), ft_stackclear(head_a), exit(1));
		if (i < argc - 1)
		{
			pile_a->next = ft_stacknew();
			pile_a = pile_a->next;
		}
		i++;
	}
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
		ft_parse_split(pile_a, &head_a, j, str);
	}
	else
	{
		ft_parse_argv(argv, argc, &head_a, pile_a);
	}
	ft_rank_stack(head_a);
	return (head_a);
}
