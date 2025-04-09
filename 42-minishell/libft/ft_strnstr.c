/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:21:41 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:47:21 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	tf_len;

	if ((!str && len == 0) || (!to_find && len == 0))
		return (0);
	if (*to_find == '\0' || str == to_find)
		return ((char *)str);
	tf_len = ft_strlen(to_find);
	while (*str && tf_len <= len)
	{
		if (ft_strncmp((char *)str, (char *)to_find, tf_len) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}

//	La fonction ft_strnstr recherche la première occurrence
//	de la sous-chaîne to_find dans la chaîne str, avec une
//	limite de recherche spécifiée par len. 
//	La fonction renvoie un pointeur vers le début de la
//	première occurrence de la sous-chaîne, ou NULL si la
//	sous-chaîne n'est pas trouvée.

// int main() 
// {
//     const char *str = "Hello, World";
//     const char *to_find = "World";

//     char *result = ft_strnstr(str, to_find, strlen(str));

//     if (result != NULL)
//         printf("Le résultat de ft_strnstr : %s\n", result);
//     else
//         printf("La sous-chaîne n'a pas été trouvée.\n");
//     return 0;
// }