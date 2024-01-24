/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:26:55 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 13:44:44 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

//These functions convert lowercase letters to uppercase, and vice versa.
// #include<stdio.h>

// int main()
// {
// 	int c = 'Z';
// 	printf("%d", ft_tolower(c));
// 	return (0);
// }
