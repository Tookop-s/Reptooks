/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:49:30 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:44:56 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

//	La fonction ft_strlcpy copie une chaîne source src dans
//	une chaîne de destination dst tout en limitant la copie
//	à une taille maximale spécifiée par l'argument size.
//	La fonction renvoie la longueur de la chaîne source,
//	c'est-à-dire le nombre de caractères qu'elle aurait
//	copiés sans la limitation de taille, mais elle ne
//	renvoie jamais une valeur supérieure à size - 1.
//	Le dernier caractère de la chaîne de destination est
//	toujours défini sur zéro pour s'assurer que la chaîne
//	résultante est correctement terminée.

// #include "libft.h"
// #include <stdio.h>

// int main()
// {
//     // Déclarer un tableau de destination avec une taille suffisante
//     char destination[20];

//     // Chaîne source à copier dans la destination
//     const char *source = "Hello, World!";

//     // Taille de la destination (la taille du tableau)
//     size_t size_of_destination = sizeof(destination);

//     // Appeler la fonction ft_strlcpy
//     size_t result = ft_strlcpy(destination, source, size_of_destination);

//     // Afficher les résultats
//     printf("Résultat de ft_strlcpy: %zu\n", result);
//     printf("Chaîne destination: %s\n", destination);

//     return 0;
// }