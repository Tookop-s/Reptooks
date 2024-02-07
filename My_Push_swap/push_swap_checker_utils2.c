/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_utils2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:59:36 by anferre           #+#    #+#             */
/*   Updated: 2024/02/07 16:05:39 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap_checker.h"

void	ft_rr_no_write(t_stack **head_a, t_stack **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
}

void	ft_ss_no_write(t_stack **head_a, t_stack **head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
}

void	ft_rrr_no_write(t_stack **head_a, t_stack **head_b)
{
	ft_reverse_rotate(head_a);
	ft_reverse_rotate(head_b);
}
