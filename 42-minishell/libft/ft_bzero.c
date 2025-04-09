/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:24:21 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/21 12:30:11 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
//	La fonction bzero est utilisée pour initialiser 
//	les n premiers octets de la mémoire pointée par s à zéro 
//	(la valeur 0). Elle prend deux arguments : 
//	- un pointeur vers la mémoire à initialiser (s) 
//	- et le nombre d'octets à initialiser (n).