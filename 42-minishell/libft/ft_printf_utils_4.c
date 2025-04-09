/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:08:18 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:30 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_ptr(unsigned long ptr)
{
	int	length;

	length = 0;
	if (ptr >= 16)
	{
		length += ft_put_ptr((unsigned long)ptr / 16);
		length += ft_put_ptr((unsigned long)ptr % 16);
	}
	else
	{
		if (ptr <= 9)
		{
			ft_print_char((ptr + '0'));
			length++;
		}
		else
		{
			ft_print_char((ptr - 10 + 'a'));
			length++;
		}
	}
	return (length);
}

int	ft_print_ptr(unsigned long long *ptr)
{
	unsigned long	nbr;
	int				to_print;

	nbr = (unsigned long) ptr;
	to_print = 0;
	if (ptr == 0)
	{
		to_print += write(1, "(nil)", 5);
		return (to_print);
	}
	to_print += write(1, "0x", 2);
	to_print += ft_put_ptr(nbr);
	return (to_print);
}
