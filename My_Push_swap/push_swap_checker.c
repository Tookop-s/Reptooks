/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:46:04 by anferre           #+#    #+#             */
/*   Updated: 2024/02/12 12:44:44 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap_checker.h"

//read from stdin and fill ops
static void	*ft_read_ops(t_ops **ops)
{
	int		nbchar;
	t_ops	*tempops;
	char	*str;

	tempops = *ops;
	str = malloc(sizeof(char) * 256);
	if (!str)
		return (NULL);
	nbchar = 1;
	while (nbchar > 0 && tempops)
	{
		nbchar = read(0, str, sizeof(str));
		if (nbchar < 0)
			return (ft_error(), (void *) 1);
		str[nbchar] = '\0';
		tempops->buff = ft_strdup(str);
		if (nbchar)
			tempops->next = ft_opsnew();
		tempops = tempops->next;
	}
	free(str);
	if (nbchar < 0)
		return (ft_error(), NULL);
	return ((void *) 0);
}

//extract op by op
static char	*ft_cpy_ops(t_ops **ops, int *index, char *str)
{
	int	i;

	i = 0;
	while (*ops)
	{
		while ((*ops)->buff[(*index)] != '\n' && (*ops)->buff[(*index)])
		{
			str[i] = (*ops)->buff[(*index)];
			i++;
			(*index)++;
		}
		if ((*ops)->buff[(*index)] == '\n')
		{
			str[i] = '\0';
			(*index)++;
			return (str);
		}
		else
			*index = 0;
		(*ops) = (*ops)->next;
	}
	return (free(str), str = NULL);
}

//check if the str is part of the ops and execute the ops otherwise error
static int	ft_do_ops_checker(char *str, t_stack **head_a, t_stack **head_b)
{
	if (ft_strncmp(str, "ra", 3) == 0)
		ft_rotate(head_a);
	else if (ft_strncmp(str, "rb", 3) == 0)
		ft_rotate(head_b);
	else if (ft_strncmp(str, "rr", 3) == 0)
		ft_rr_no_write(head_a, head_b);
	else if (ft_strncmp(str, "pa", 3) == 0)
		ft_push(head_b, head_a);
	else if (ft_strncmp(str, "pb", 3) == 0)
		ft_push(head_a, head_b);
	else if (ft_strncmp(str, "sb", 3) == 0)
		ft_swap(head_b);
	else if (ft_strncmp(str, "sa", 3) == 0)
		ft_swap(head_a);
	else if (ft_strncmp(str, "ss", 3) == 0)
		ft_ss_no_write(head_a, head_b);
	else if (ft_strncmp(str, "rra", 4) == 0)
		ft_reverse_rotate(head_a);
	else if (ft_strncmp(str, "rrb", 4) == 0)
		ft_reverse_rotate(head_b);
	else if (ft_strncmp(str, "rrr", 4) == 0)
		ft_rrr_no_write(head_a, head_b);
	else
		return (-1);
	return (0);
}

//execute all of the ops
static int	ft_exec_ops(t_ops **ops, t_stack **head_a)
{
	char	*str;
	int		i;
	t_stack	*head_b;
	t_ops	*temp;

	i = 0;
	temp = *ops;
	head_b = NULL;
	str = malloc (sizeof(char) * 4);
	if (!str)
		return (-1);
	while (str)
	{
		str = ft_cpy_ops(&temp, &i, str);
		if (!str)
			break ;
		if (ft_do_ops_checker(str, head_a, &head_b) < 0)
			return (ft_error(), ft_clear(head_a, ops), free(str), exit(1), 1);
	}
	if (head_b || (!(ft_is_sorted(*head_a))))
		return (ft_stackclear(&head_b), free(str), -1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_ops	*ops;

	head_a = ft_stacknew();
	if (argc == 1)
		return (ft_stackclear(&head_a), 1);
	ops = ft_opsnew();
	head_a = ft_parse(argv, argc, head_a);
	if (!head_a)
		return (ft_clear(&head_a, &ops), 1);
	if (ft_is_sorted(head_a))
		return (ft_clear(&head_a, &ops), write(1, "OK\n", 3), 0);
	ft_read_ops(&ops);
	if (ft_exec_ops(&ops, &head_a) < 0)
		return (ft_clear(&head_a, &ops), ft_ko(), 1);
	ft_clear(&head_a, &ops);
	write(1, "OK\n", 3);
	return (0);
}
