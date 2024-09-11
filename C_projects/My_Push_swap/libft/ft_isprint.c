/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:33 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:16:27 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
//check if we can print c
// #include <stdio.h>

// int main()
// {
// 	int c; 
// 	c = 127; 
// 	printf("ma fonction : %d \n", ft_isprint(c));
// 	printf("Fonction originelle : %d \n", isprint(c));
// 	return(0);	
// }