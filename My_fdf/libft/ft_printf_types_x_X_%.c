/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types_x_X_%.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:24:24 by anferre           #+#    #+#             */
/*   Updated: 2024/01/03 17:22:39 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putnbr_base(unsigned int nb, char *base, int *count)
{
	long	nb2;
	int		baselen;

	nb2 = nb;
	baselen = 16;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 *= -1;
		(*count)++;
	}
	if (nb2 >= 16)
		ft_putnbr_base(nb2 / baselen, base, count);
	ft_putchar(base[nb2 % baselen]);
	(*count)++;
	return (*count);
}
