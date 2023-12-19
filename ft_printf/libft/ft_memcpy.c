/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:43:17 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:44:05 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	s = (void *)src;
	d = dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
//copies n bytes from src to dest that may not overlap
// #include<stdio.h>
// int main()
// {
// 	char src[] = "0123456789";
// 	char *buff1 = &src[0];
// 	char *buff2 = &src[2];
// 	char src2[] = "0123456789";
// 	char *buff12 = &src2[0];
// 	char *buff22 = &src2[2];
// 	char *me = ft_memcpy(buff2, buff1, 8);
// 	char *me2 = memcpy(buff22, buff12, 8);
// 	printf("%s\n", me);
// 	printf("%s\n", me2);
// }