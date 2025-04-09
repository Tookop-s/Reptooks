/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:46:31 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:54:24 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	ft_isalpha(unsigned int i, char c) 
// {
// 	if((int)i > -1)
// 	if (c >= 'a' && c <= 'z')
// 		c -= 32;
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = (char *)s;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

//	La fonction ft_strmapi applique une fonction f 
//	à chaque caractère de la chaîne de caractères s.
//	La fonction f prend en paramètre l'indice du caractère
//	dans la chaîne et le caractère lui-même. 
//	Le résultat de la fonction f est utilisé pour construire
//	une nouvelle chaîne de caractères, et le pointeur vers
//	cette nouvelle chaîne est renvoyé.

// int main() 
// {
//     const char *input_string = "abcdef";

//     char *result = ft_strmapi(input_string, &ft_isalpha);

//     if (result == NULL) 
// 		return (1);

//     printf("Chaîne d'entrée: '%s'\n", input_string);
//     printf("Résultat de ft_strmapi: '%s'\n", result);

//     free(result);

//     return 0;
// }