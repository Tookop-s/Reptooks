/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:01:12 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:41 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(va_list args, const char after)
{
	int	print;

	print = 0;
	if (after == 'c')
		print += ft_print_char(va_arg(args, int));
	else if (after == 's')
		print += ft_print_str(va_arg(args, char *));
	else if (after == 'p')
		print += ft_print_ptr(va_arg(args, unsigned long long *));
	else if (after == 'd')
		print += ft_print_nbr(va_arg(args, int));
	else if (after == 'i')
		print += ft_print_nbr(va_arg(args, int));
	else if (after == 'u')
		print += ft_print_unsigned(va_arg(args, unsigned int));
	else if (after == 'x')
		print += ft_print_hexa(va_arg(args, unsigned int), after);
	else if (after == 'X')
		print += ft_print_hexa(va_arg(args, unsigned int), after);
	else if (after == '%')
		print += ft_print_percent();
	return (print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print;
	va_list	args;

	i = 0;
	print = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print = print + check(args, str[i + 1]);
			i += 2;
		}
		else
		{
			print = print + ft_print_char(str[i]);
			i++;
		}
	}
	va_end(args);
	return (print);
}

// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.