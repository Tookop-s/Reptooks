/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:13:03 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:13:34 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

//check if c is alphabatical or numerical 
// #include <stdio.h>

// int main()
// {
// 	int c; 
// 	c = 'Z'; 
// 	printf("Ma Fonction : %d \n", ft_isalnum(c));
// 	printf("Fonction originelle :%d \n", isalnum(c));
// 	return(0);	
// }