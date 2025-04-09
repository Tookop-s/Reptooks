/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:00:10 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/21 12:29:12 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t len)
{
	void	*ptr;

	if (!count || !len)
		return (malloc(0));
	if (((count * len) / count) != len)
		return (NULL);
	ptr = (void *)malloc(count * len);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, count * len);
	return (ptr);
}

//	La fonction calloc est utilisée pour allouer
//	de la mémoire pour un tableau de count
//	éléments, chacun ayant une taille de len octets, et
//	elle initialise tous les octets de la mémoire allouée
//	à zéro.

// int main()
// {
//     unsigned int count = 5;
//     unsigned int len = 4;
//     unsigned int total_size = count * len;

//     void *ptr = ft_calloc(count, len);
//     if (ptr) {
//         printf("Mémoire allouée avec succès.\n");
//         unsigned char *byte_ptr = (unsigned char *)ptr;
//         for (unsigned int i = 0; i < total_size; i++) 
//     {
//             if (byte_ptr[i] != 0) 
//     {
//                 printf("Erreur : La mémoire n'est 
//				pas initialisée à zéro.\n");
//                 break;
//             }
//         }
//      } 
//		else 
//      {
//         printf("Échec de l'allocation de mémoire.\n");
//		}
//     free(ptr);

//     return 0;
// }

// verf fuite = valgrind --leak-check=full ./votre_programme
// verf fuite = gcc -fsanitize=address -g -o votre_programme votre_code.c