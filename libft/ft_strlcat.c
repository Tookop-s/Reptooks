/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:21:55 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 13:30:51 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	ldest;
	unsigned int	lsrc;
	int				i;

	if (!dst && size == 0)
		return (0);
	ldest = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	if (size <= ldest)
		return (size + lsrc);
	while (src[i] && (ldest + i) < size -1)
	{
		dst[ldest + i] = src[i];
		i++;
	}
	dst[ldest + i] = '\0';
	return (ldest + lsrc);
}

//appends the NUL-terminated string src to the end of dst.
// #include <stdio.h>
// int main()
// {
// 	char *s = "world !";
// 	char d[14] = "Hello ";
// 	ft_strlcat(d, s, 14);
// 	printf("My function : $%s$ \n", d);
// }