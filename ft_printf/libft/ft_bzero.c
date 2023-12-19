/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:32:30 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:11:06 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
}
//write 0 for n time starting at *s
// #include <stdio.h>
// int main()
// {
// 	char s[20];
// 	char s2[20];
// 	ft_bzero(s, 10);
// 	bzero(s2, 10);
// 	printf("ma fonction :%s \n", s);
// 	printf("fonction originelle :%s \n", s2);
// 	return (0);
// }