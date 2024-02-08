/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:48:43 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 13:37:42 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

//it compares only the first (at most) n bytes of s1 and s2
//unsigned bc needs to be able to read negative ascii
// #include<string.h>
// #include<stdio.h>

// int main ()
// {
// 	char *src1 = "1";
// 	char *src2 = "3";
// 	int nb = 6;
// 	printf("Resultat ma fonction :%d \n", ft_strncmp(src1, src2, nb));
// 	printf("Resultat fonction originelle : %d\n", strncmp(src1, src2, nb));
// 	return (0);
// }