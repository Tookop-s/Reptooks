/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:34:36 by anferre           #+#    #+#             */
/*   Updated: 2023/12/20 12:29:53 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
	int		i;
	char	c;
	int 	count;
	int		*ct;
	va_list args;

	i = 0;
	count = 0;
	va_start(args, s);
	c = ft_strchr(s, '%');
	ct = &count;
	while(s[i])
	{
		while(s[i] != '%')
		{
			ft_putchar(s[i]);
			i++;
			count++;
		}
		if (s[i] == '%')
			i += 2;
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
		
		c = ft_strchr(&s[i], '%');
	}
	va_end(args);
	return (*ct);
}
