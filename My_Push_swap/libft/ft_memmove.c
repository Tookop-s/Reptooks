/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:44:53 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 18:07:42 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	s = (void *)src;
	d = dest;
	i = 0;
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

//copies n bytes from src to dest that may overlap
// #include<stdio.h>

// int main()
// {
// 	char *src = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
// 	char *dst[0xF0];
// 	char *me;
// 	me = memmove(dst, src, ft_strlen(src));
// 	printf("%s\n", me);
// }
