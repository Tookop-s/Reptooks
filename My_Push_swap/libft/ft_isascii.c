/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:56:31 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:15:27 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
//check if c is part of the ascii table
// #include <stdio.h>

// int main()
// {
// 	int c; 
// 	c = 127; 
// 	printf("ma fonction : %d \n", ft_isascii(c));
// printf("Fonction originelle : %d \n", isascii(c));
// 	return(0);	
// }