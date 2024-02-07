/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:55:41 by anferre           #+#    #+#             */
/*   Updated: 2024/02/07 16:12:45 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "push_swap.h"

typedef struct s_ops
{
	char			*buff;
	struct s_ops	*next;
}					t_ops;

		/*Utils*/
t_ops	*ft_opsnew(void);
void	ft_ko(void);
void	ft_opsclear(t_ops **stack);
void	ft_clear(t_stack **head, t_ops **ops);

		/*Utils_ops*/
void	ft_rr_no_write(t_stack **head_a, t_stack **head_b);
void	ft_ss_no_write(t_stack **head_a, t_stack **head_b);
void	ft_rrr_no_write(t_stack **head_a, t_stack **head_b);

#endif