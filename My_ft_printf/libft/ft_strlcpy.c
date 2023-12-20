/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:59:57 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 13:33:42 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

//copies up to size - 1 characters from the NUL-terminated string src to dst
// #include <stdio.h>
// int main()
// {
// 	char *s = "Hello world !";
// 	char d[14];
// 	ft_strlcat(d, s, 14);
// 	printf("My function : $%s$ \n", d);
// }