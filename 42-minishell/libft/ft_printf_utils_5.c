/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:08:18 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/15 12:05:33 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hexa(unsigned int num, const char format)
{
	int	length;

	length = 0;
	if (num >= 16)
	{
		length += ft_put_hexa(num / 16, format);
		length += ft_put_hexa(num % 16, format);
	}
	else
	{
		if (num <= 9)
		{
			ft_print_char(num + '0');
			length++;
		}
		else
		{
			if (format == 'x')
				ft_print_char(num - 10 + 'a');
			if (format == 'X')
				ft_print_char(num - 10 + 'A');
			length++;
		}
	}
	return (length);
}

int	ft_print_hexa(unsigned int num, const char format)
{
	int	length;

	length = 0;
	if (num == 0)
	{
		length++;
		return (write(1, "0", 1));
	}
	else
		length = ft_put_hexa(num, format);
	return (length);
}
