/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:48:46 by anferre           #+#    #+#             */
/*   Updated: 2024/03/29 13:43:01 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	unsigned int	i;
	int				neg;
	long			nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg = -neg;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}
//converts a string to an int 
// char *str to int 

// #include<stdlib.h>
// #include<stdio.h>

// int main()
// {
// 	char *s = "-2147483648";
// 	printf("Resultat ma fonction :%d\n", ft_atoi(s));
// 	printf("Resultat fonction originelle : %d\n", atoi(s));
// 	return (0);	
// }