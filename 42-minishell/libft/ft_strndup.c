/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:57:32 by gchamore          #+#    #+#             */
/*   Updated: 2024/06/11 18:26:06 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str1, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!str1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (str1[i] && i < len)
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//	La fonction ft_strdup duplique la chaîne de caractères
//	passée en argument. Elle alloue dynamiquement de la
//	mémoire pour la nouvelle chaîne et copie le contenu
//	de la chaîne d'origine dans la nouvelle mémoire allouée.
//	Elle renvoie un pointeur vers la nouvelle chaîne de
//	caractères.

// int	main() 
// {
//     char *src = "okok";
//     char *dest = ft_strdup(src);
//     printf("Src : %s\n", src);
//     printf("Dest : %s\n", dest);
// 	free(dest);
//     return (0);
// }