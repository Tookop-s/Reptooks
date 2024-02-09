/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:06:00 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:12:38 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
//check if c is part of the alphabet

// #include <stdio.h>

// int main()
// {
// 	int c; 
// 	c = '1'; 
// 	printf("ma fonction : %d \n", ft_isaplha(c));
// printf("fonction originelle %d \n", isaplha(c));
// 	return(0);	
// }