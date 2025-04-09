/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:06 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/20 14:35:03 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i])
		i++;
	while (i != 0 && str[i] != (char)c)
		i--;
	if (str[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

//	La fonction ft_strrchr recherche la dernière occurrence
//	du caractère c dans la chaîne de caractères s.
//	Elle renvoie un pointeur vers le dernier emplacement du
//	caractère recherché dans la chaîne ou NULL si le
//	caractère n'est pas trouvé.

// int main() 
// {
//     const char *str = "there is so \0ma\0ny \0 \\0 in t\0his 
// stri\0ng !\0\0\0\0";
//     int search_char = '\0';
//     char *result = ft_strrchr(str, search_char);
//     char *expected_result = strrchr(str, search_char);
//     if (result == expected_result) 
//     {
//         printf("Test réussi : les résultats sont identiques.\n");
//     } 
//     else 
//     {
//         printf("Test échoué : les résultats diffèrent.\n");
//     }
//     return 0;
// }