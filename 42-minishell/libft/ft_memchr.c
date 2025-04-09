/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:35:04 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:19:42 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}

//	La fonction ft_memchr recherche la
//	première occurrence de l'octet c dans les
//	n premiers octets de la mémoire pointée par s.
//	Elle renvoie un pointeur vers l'octet correspondant
//	ou NULL si l'octet n'est pas trouvé dans la plage spécifiée.

// #include <stdio.h>

// int main() 
// {
//     const char *str = "/|\x12\xff\x09\x42\042\42|\\";
//     char search_char = '\x42';
//     unsigned int n = 10;

//     void *result = ft_memchr(str, (int)search_char, n);
// 	void *result2 = memchr(str, (int)search_char, n);

//     if (result != NULL) 
// 	{
//         printf("Le caractère '%c' a été trouvé à l'adresse 
// mémoire : %p\n", search_char, result);
//     } else 
// 	{
//         printf("Le caractère '%c' n'a pas été trouvé dans 
// la chaîne.\n", search_char);
//     }

// 	if (result2 != NULL) 
// 	{
//         printf("Le caractère '%c' a été trouvé à l'adresse 
// mémoire : %p\n", search_char, result2);
//     } else {
//         printf("Le caractère '%c' n'a pas été trouvé dans 
// la chaîne.\n", search_char);
//     }
//     return 0;
// }
