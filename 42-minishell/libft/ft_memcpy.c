/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:06:08 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:32:00 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Utilisez memcpy lorsque vous êtes sûr que les zones source 
// et de destination ne se chevauchent pas. Cela peut être 
// plus efficace en termes de performances.
// #include <stdio.h>
// #include <string.h>

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned int	i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

//	La fonction ft_memcpy copie les n premiers octets du
//	bloc mémoire pointé par src dans le bloc mémoire pointé
//	par dst. Les blocs mémoire peuvent se chevaucher.

// int main()
// {
// 	char dst[10];
// 	char src[10];
// 	strcpy(dst, "coucou");
// 	strcpy(src, "ok");
// 	ft_memcpy(dst, src, 6);
// 	printf("%s \n %s \n", src, dst);
// 	return 0;
// }