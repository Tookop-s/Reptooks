/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:12:17 by gchamore          #+#    #+#             */
/*   Updated: 2024/06/11 17:52:47 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if ((!str1[i] || !str2[i]) && i < len)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}
// #include <stdio.h>

// int main() 
// {
//     const char *str1 = "\200";
//     const char *str2 = "\0";
//     unsigned int n = 1;

//     int result = ft_strncmp(str1, str2, n);

//     int expected_result = strncmp(str1, str2, n);

//     if (result == expected_result) 
// 	{
//         printf("Test réussi : les résultats sont identiques.\n");
//     } else {
//         printf("Test échoué : les résultats diffèrent %d str && 
// %d ft.\n", expected_result, result);
//     }

//     return 0;
// }