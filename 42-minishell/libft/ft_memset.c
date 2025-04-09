/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:31:49 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:34:49 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}

//	La fonction ft_memset remplit les len premiers octets de
//	la mémoire pointée par b avec la valeur c 
//	(interprétée comme un unsigned char).

// int main() {
//     char buffer[20];
//     ft_memset(buffer, 'A', 10);  
//     printf("Buffer after ft_memset: %s\n", buffer);
//     return 0;
// }