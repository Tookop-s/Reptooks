/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:36:22 by anferre           #+#    #+#             */
/*   Updated: 2024/02/05 17:38:34 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	if (argc == 1)
		return (1);
	head_a = ft_stacknew();
	head_b = NULL;
	head_a = ft_parse(argv, argc, head_a);
	if (!head_a)
		return ( 1);
	if (ft_is_sorted(head_a))
		return (ft_stackclear(&head_a), 0);
	ft_sort(&head_a, &head_b);
	ft_stackclear(&head_a);
	return (0);
}
