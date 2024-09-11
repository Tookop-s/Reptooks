/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types_d_i_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:24:24 by anferre           #+#    #+#             */
/*   Updated: 2024/01/03 17:22:07 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	*count = ft_putnbr_unsigned(u, count);
}

int	ft_putnbr(int nb, int *count)
{
	long	nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 *= -1;
		(*count)++;
	}
	if (nb2 > 9)
		ft_putnbr(nb2 / 10, count);
	ft_putchar((nb2 % 10) + '0');
	(*count)++;
	return (*count);
}

int	ft_putnbr_unsigned(unsigned int nb, int *count)
{
	long	nb2;

	nb2 = nb;
	if (nb2 > 9)
		ft_putnbr(nb2 / 10, count);
	ft_putchar((nb2 % 10) + '0');
	(*count)++;
	return (*count);
}
