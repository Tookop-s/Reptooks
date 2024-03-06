/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:49:07 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:43:54 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		d;
	unsigned char		*src;
	long unsigned int	i;

	d = c;
	i = 0;
	src = (void *)s;
	while (i < n)
	{
		if (src[i] == d)
			return (&src[i]);
		i++;
	}
	return (NULL);
}

//look in the n bytes of *s for c
// #include<stdio.h>

// int main()
// {
// 	const void *s = "Hello World !";
// 	int a = '!';
// 	int len = 14;
// 	printf("Resultat ma fonction :%p \n", ft_memchr(s, a, len));
// 	printf("Resultat fonction originelle : %p\n", memchr(s, a, len));
// 	return (0);
// }