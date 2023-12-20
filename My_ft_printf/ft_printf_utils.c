/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:34:31 by anferre           #+#    #+#             */
/*   Updated: 2023/12/20 12:30:01 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	ft_strchr(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1])
			return (str[i + 1]);
		i++;
	}
	return (0);
}

int	ft_strpercent(const char *str)
{
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && str[i + 1] != '%')
			ct++;
		i++;
	}
	return (ct);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr(int nb, int *count)
{
	long nb2;

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

int ft_putnbr_base(int nb, char *base, int *count)
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

char	*ft_reversestr(char *str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			temp;

	i = 0;
	j = 0;
	while(str[i])
		i++;
	k = i - 1;
	while (j < k)
	{
		temp = str[k];
		str[k] = str[j];
		str[j] = temp;
		j++;
		k--;
	}
	return (str);
}
