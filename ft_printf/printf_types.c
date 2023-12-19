/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:24:24 by anferre           #+#    #+#             */
/*   Updated: 2023/12/19 18:17:25 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
		write(1,"(null)", 6);
		*count += 6;
		return ;
	}
	i = ft_strlen(str);
	write(1, str, i);
	*count += i;
}

void	ft_ptr(void *ptr, int *count)
{
	char			addressstr[20];
	unsigned long	address;
	char			digit;
	unsigned int	i;

	i = 0;
	if (!ptr)
	{
		write(1,"(nil)", 5);
		*count += 5;
		return ;
	}
	address = (unsigned long)ptr;
	while (address > 0)
	{
		digit = address % 16;
		if (digit < 10)
			digit += '0';
		else
			digit = digit - 10 + 'a';
		addressstr[i] = digit;
		i++;
		address /= 16;
	}
	addressstr[i++] = 'x';
	addressstr[i++] = '0';
	ft_reversestr(addressstr);
	write(1, addressstr, i);
	*count += 14;
}

void	ft_decimal(int j, int *count)
{
	*count = ft_putnbr(j, count);
}

void	ft_int(int j, int *count)
{
	*count = ft_putnbr(j, count);
}

void	ft_unsigneddeci(unsigned int u, int *count)
{
	*count = ft_putnbr(u, count);
	
}

void	ft_lowerhex(unsigned int h, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	*count = ft_putnbr_base(h, base, count);
}

void	ft_upperhex(unsigned int h, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	*count = ft_putnbr_base(h, base, count);
}

void	ft_percent(int *count)
{
	ft_putchar('%');
	(*count)++;
}