/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:55:28 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:33:05 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	t;
	unsigned int	i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	t = 0;
	i = 0;
	while (i < len && s1[i] == s2[i])
	{
		if (s1[i] == s2[i])
			t++;
		i++;
	}
	if (t == len)
		return (0);
	return (s1[i] - s2[i]);
}

//	La fonction ft_memcmp compare les len premiers octets des
//	blocs mémoire pointés par str1 et str2. 
//	Elle renvoie un entier inférieur, égal, ou supérieur
//	à zéro, selon que le bloc mémoire str1 est considéré
//	comme inférieur, égal ou supérieur au bloc mémoire str2.

// int main() 
// {
//     const char *str1 = "";
//     const char *str2 = "";
//     unsigned int n = 4;

//     int result = ft_memcmp(str1, str2, n);

//     int expected_result = memcmp(str1, str2, n);

//     if (result == expected_result) {
//         printf("Test réussi : les résultats sont identiques.\n");
//     } else {
//         printf("Test échoué : les résultats diffèrent.\n");
//     }

//     return 0;
// }