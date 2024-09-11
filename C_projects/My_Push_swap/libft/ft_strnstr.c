/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:48:40 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 13:38:06 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*b;

	i = 0;
	b = (char *)big;
	if (little[i] == '\0')
		return (b);
	if (len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while ((i + j) < len && big[i + j] == little[j])
			{
				j++;
				if (little[j] == '\0')
					return (((char *)&big[i]));
			}
		}
		i++;
	}
	return (NULL);
}

//locates the first occurrence of the null-terminated 
//string little in the string big
//
// #include<stdio.h>
// #include<unistd.h>

// int main ()
// {
// 	char *b = "Hello World!";
// 	char *l = "";
// 	int nb = 13;
// 	printf("Resultat ma fonction :%s \n", ft_strnstr(b, l, nb));
// 	return (0);
// }