/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:48:57 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/22 13:07:49 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;

	if (!dst && size == 0)
		return (0);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = ft_strlen(dst);
	y = 0;
	while (src[y] != '\0' && i + 1 < size)
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[y]));
}

//	La fonction ft_strlcat concatène une chaîne source src à
//	la fin d'une chaîne de destination dst. 
//	La différence principale entre ft_strlcat et ft_strcat
//	est que ft_strlcat prend un argument supplémentaire,
//	size, qui spécifie la taille totale de la mémoire
//	disponible pour la chaîne de destination, y compris
//	l'espace déjà occupé par les caractères existants dans dst.

//	La fonction ft_strlcat renvoie la longueur totale de la
//	chaîne résultante (c'est-à-dire la longueur de la chaîne
//	initiale dst plus la longueur de la chaîne ajoutée src).
//	Si la taille totale de la chaîne résultante est
//	supérieure à size, la fonction renvoie
//	la valeur size + ft_strlen(src).

// #include <stdio.h>
// #include <string.h>

// int main() 
// {
//     char destination[10] = "a";
//     printf("Concatenated string mine :
//		%ld\n", ft_strlcat(destination, "lorem ipsum dolor sit amet", 0));
//     return 0;
// }
