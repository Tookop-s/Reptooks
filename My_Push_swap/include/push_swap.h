/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:36:51 by anferre           #+#    #+#             */
/*   Updated: 2024/01/30 17:16:02 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	long 			nb;
	int 			index;
	struct s_stack	*next;
}					t_stack;

		/*prints to delete !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
void	print_stack(t_stack *head, char c);
		/*Utils*/
void	ft_error(void);
void	ft_stackclear(t_stack **stack);
int		ft_stacksize(t_stack *head);
t_stack	*ft_stacknew(void);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_is_sorted(t_stack *head_a);

		/*Parsing*/
int		ft_check_str(char *str);
int		ft_check_int(long nb, t_stack *head_a);
void	ft_rank_stack(t_stack *head_a);
void	*ft_parse(char **str, int argc, t_stack *head_a);

		/*Operations*/
/*swap*/
void	ft_swap(t_stack **head);
void	ft_sa(t_stack **head_a);
void	ft_sb(t_stack **head_b);
void	ft_ss(t_stack **head_a, t_stack **head_b);
/*push*/
void	ft_push(t_stack **head_move, t_stack **head_receive);
void	ft_pa(t_stack **head_a, t_stack **head_b);
void	ft_pb(t_stack **head_a, t_stack **head_b);
/*rotate*/
void	ft_rotate(t_stack **head);
void	ft_ra(t_stack **head_a);
void	ft_rb(t_stack **head_b);
void	ft_rr(t_stack **head_a, t_stack **head_b);
/*reverse rotate*/
void	ft_reverse_rotate(t_stack **head);
void	ft_rra(t_stack **head_a);
void	ft_rrb(t_stack **head_b);
void	ft_rrr(t_stack **head_a, t_stack **head_b);

		/*Sorting*/

void	ft_sort(t_stack **head_a, t_stack **head_b);
void	ft_sort_in_a(t_stack **head_a, t_stack **head_b, int size_a, int size_b);
int		ft_get_prev_index(int index, t_stack *head);
int		ft_get_next_index(int index, t_stack *head);
void	ft_put_all_b(t_stack **head_a, t_stack **head_b, int size_a);

#endif