/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:57:32 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/09 11:55:37 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str1)
{
	char			*str;
	unsigned int	i;

	if (!str1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(str1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (str1[i])
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