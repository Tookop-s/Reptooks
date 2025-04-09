/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/05/16 18:19:55 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

//	La fonction ft_strjoin concatène deux chaînes de caractères
//	s1 et s2 pour former une nouvelle chaîne de caractères.
//	La nouvelle chaîne est allouée dynamiquement, et la
//	mémoire doit être libérée après utilisation.

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     const char *s1;
//     const char *s2;

// 	s1 = "Hello, ";
// 	s2 = "John!";
//     // Utilisation de strjoin pour concaténer les chaînes
//     char *str = ft_strjoin(s1, s2);

//     // Vérification de l'allocation de mémoire réussie
//     if (str != NULL) 
// 	{
//         printf("%s\n", str);

//         // N'oubliez pas de libérer la mémoire allouée
//         free(str);
//     } 
// 	else 
//         printf("Erreur d'allocation de mémoire.\n");
//     return 0;
// 	free (str);
// }