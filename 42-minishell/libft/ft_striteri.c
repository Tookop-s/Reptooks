/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:16:00 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:41:00 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void ft_isalpha(unsigned int i, char *c) 
// {
//         if ((int) i > -1)
//         if (*c >= 'a' && *c <= 'z') 
//             *c -= 32;
// 		// printf("isalpha : %c\n", *c);
// }
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f (i, &s[i]);
			i++;
		}
	}
}

//	La fonction ft_striteri applique une fonction f à chaque
//	caractère de la chaîne de caractères s. La fonction f
//	prend en paramètre l'indice du caractère et une
//	référence vers ce caractère.

// int main() 
// {
//     char input_string[] = "abcdef";
//     ft_striteri(input_string, ft_isalpha);
//     return 0;
// }