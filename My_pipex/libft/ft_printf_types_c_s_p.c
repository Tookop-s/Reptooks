/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types_c_s_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:24:24 by anferre           #+#    #+#             */
/*   Updated: 2024/02/13 17:48:14 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	ft_simplechar(char c, int *count)
{
	ft_putchar(c);
	(*count)++;
}

void	ft_string(char *str, int *count)
{
	unsigned int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	i = ft_strlen(str);
	write(1, str, i);
	*count += i;
}

void	ft_putptr(unsigned long address, int *count)
{
	if (address >= 16)
	{
		ft_putptr(address / 16, count);
		ft_putptr(address % 16, count);
	}
	else
	{
		if (address < 10)
			ft_putchar(address + '0');
		else
			ft_putchar(address - 10 + 'a');
		*count += 1;
	}
}

void	ft_ptr(void *ptr, int *count)
{
	unsigned long	address;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	*count += 2;
	ft_putptr(address, count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
