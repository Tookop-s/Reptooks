/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:34:36 by anferre           #+#    #+#             */
/*   Updated: 2024/01/04 12:49:06 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char c, va_list args, int *ct)
{
	if (c == 'c')
		ft_simplechar((char)va_arg(args, int), ct);
	else if (c == 's')
		ft_string(va_arg(args, char *), ct);
	else if (c == 'p')
		ft_ptr(va_arg(args, char *), ct);
	else if (c == 'd')
		ft_decimal(va_arg(args, int), ct);
	else if (c == 'i')
		ft_int(va_arg(args, int), ct);
	else if (c == 'u')
		ft_unsigneddeci(va_arg(args, unsigned int), ct);
	else if (c == 'x')
		ft_lowerhex(va_arg(args, unsigned int), ct);
	else if (c == 'X')
		ft_upperhex(va_arg(args, unsigned int), ct);
	else if (c == '%')
		ft_percent(ct);
}

void	ft_browse(const char *s, va_list args, int *ct)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			ft_check(s[i + 1], args, ct);
			i += 2;
		}
		else
		{
			ft_putchar(s[i]);
			i++;
			(*ct)++;
		}
	}
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		*ct;
	va_list	args;

	count = 0;
	if (!s)
		return (0);
	va_start(args, s);
	ct = &count;
	ft_browse(s, args, ct);
	return (va_end(args), *ct);
}

// #include <stdio.h>

// int main()
// {
// 	int ct;
// 	unsigned nbr = 4294967295;
// 	ct = ft_printf("%u", nbr);
// 	printf("\n%d\n", ct);
// 	return (0);
// }
