/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:18:50 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 13:44:53 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

//These functions convert lowercase letters to uppercase, and vice versa.
// #include<stdio.h>

// int main()
// {
// 	int c = 'a';
// 	printf("%d", ft_toupper(c));
// 	return (0);
// }
