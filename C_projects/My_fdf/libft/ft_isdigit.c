/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:59:52 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:15:47 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
//check if c is a digit
// #include <stdio.h>

// int main()
// {
// 	int c = '0';
// 	printf("ma fonction : %d \n", ft_isdigit(c));
// 	printf("Fonction originelle : %d \n", isdigit(c));
// 	return (0);
// }