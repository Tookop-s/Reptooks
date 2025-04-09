/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:25:44 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:53:47 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n <= 0)
		num = num * (-1);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	result[digits] = '\0';
	if (result[digits--] == '0')
		result[digits] = num % 10 + '0';
	while (digits >= 0)
	{
		result[digits] = num % 10 + '0';
		num = num / 10;
		digits--;
	}
	if (n <= 0 && n != 0)
		result[0] = '-';
	return (result);
}

//	La fonction ft_itoa convertit un entier n en une chaîne
//	de caractères correspondante. La chaîne résultante est
//	allouée dynamiquement, et un pointeur vers cette
//	nouvelle chaîne est renvoyé.

// #include <stdio.h>

// int main() 
// {
//     int n = -0045;
//     char *str;

//     str = ft_itoa(n);

//     printf("La chaîne équivalente à &%s&\n", str);

//     return 0;
// }