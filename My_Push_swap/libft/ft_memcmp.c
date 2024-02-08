/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:56:48 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:43:57 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	i;

	i = 0;
	str1 = (void *)s1;
	str2 = (void *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

//compares the n bytes of each memory area
// #include <stdio.h>

// int main ()
// {
// 	char *s1 = '\0';
// 	char *s2 = '\0';
// 	int nb = 0;
// 	printf("Resultat ma fonction :%d \n", ft_memcmp(s1, s2, nb));
// 	printf("Resultat fonction originelle : %d\n", memcmp(s1, s2, nb));
// 	return (0);
// }