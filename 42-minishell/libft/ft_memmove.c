/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:05:52 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:53:59 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Utilisez memmove lorsque vous ne pouvez pas garantir que les 
// zones ne se chevauchent pas ou lorsque la sécurité est une 
// préoccupation. Cela garantit que la copie se fait correctement, 
// même en cas de chevauchement.

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned int	i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

//	La fonction ft_memmove copie len octets du bloc mémoire
//	pointé par src dans le bloc mémoire pointé par dst.
//	La particularité de ft_memmove par rapport à ft_memcpy
//	est qu'elle gère correctement les cas où les blocs
//	mémoire source et destination se chevauchent.

// /*chevauchement*/
// int main() 
// {
//     char source[] = "Hello, World!";
//     char destination[14];
//     ft_memmove(destination, source + 6, strlen(source) - 6);
//     printf("Destination: %s\nSource: %s\n", destination, source);
//     return 0;
// }
// /*pas de chevauchement*/
// int main() 
// {
//     char source[] = "Hello, World!";
//     char destination[14];
//     ft_memmove(destination, source, strlen(source));
//     printf("Destination: %s\nSource: %s\n", destination, source);
//     return 0;
// }