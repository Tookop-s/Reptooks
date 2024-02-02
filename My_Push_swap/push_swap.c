/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:36:22 by anferre           #+#    #+#             */
/*   Updated: 2024/02/02 15:08:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>



void	print_stack(t_stack *head, char c)
{
	printf("\nStack_%c\n", c);
	while (head)
	{
		printf("%ld, index = %d \n", head->nb, head->index);
		
		head = head->next;
	}
	printf("______________________\n\n");
}

int main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	
	head_a = ft_stacknew();
	head_b = NULL;
	if (argc == 1)
		return (1);
	head_a = ft_parse(argv, argc, head_a);
	if (!head_a)
		return (1);
	if (ft_is_sorted(head_a))
		return (0);
	ft_sort(&head_a, &head_b);
	print_stack(head_a, 'a');
	print_stack(head_b, 'b');
	ft_stackclear(&head_a);
	return (0);
}