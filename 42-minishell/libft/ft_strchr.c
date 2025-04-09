/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:22:46 by gchamore          #+#    #+#             */
/*   Updated: 2023/12/06 13:22:25 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

//	La fonction ft_strchr recherche la première occurrence 
//	du caractère c dans la chaîne de caractères s.
//	Elle renvoie un pointeur vers le premier emplacement 
//	du caractère recherché dans la chaîne ou NULL si le
//	caractère n'est pas trouvé.

// int main() 
// {
//     const char *str = "Hello, World!";
//     int search_char = 'o';

//     char *result = ft_strchr(str, search_char);

//     char *expected_result = strchr(str, search_char);

//     if (result == expected_result) 
// 	{
//         printf("Test réussi : les résultats sont identiques.\n");
//     } 
// 	else 
// 	{
//         printf("Test échoué : les résultats diffèrent.\n");
//     }
//     return 0;
// }