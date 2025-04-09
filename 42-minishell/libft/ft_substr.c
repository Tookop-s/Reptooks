/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:19:50 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/09 13:23:24 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((const char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//	La fonction ft_substr extrait une sous-chaîne de la
//	chaîne de caractères s, commençant à l'index spécifié
//	start et d'une longueur maximale len.
//	La sous-chaîne extraite est copiée dans une nouvelle
//	chaîne de caractères allouée dynamiquement,
//	et un pointeur vers cette nouvelle chaîne est renvoyé.

// int main()
// {
// 	char *str;
// 	str = ft_substr("01234", 10, 10);
// 	if (str)
//         printf("%s", str);
//     free(str);
//     return 0;
// }