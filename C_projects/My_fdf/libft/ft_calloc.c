/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:48:21 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 13:55:33 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if (((nmemb * size) / nmemb) != size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
//allocate memory for nmemb elements of size bytes and set all to 0
//test for the overflow (nmemb * size) / nmemb --> if nmemb * size overflow 
//it will change the value of (nmemb * size) 
//and the result will be diff from size

// #include<stdio.h>

// int main ()
// {
// 	int nmelements = 8539;
// 	unsigned char *ptrme = ft_calloc(nmelements, sizeof(int));
// 	unsigned char *ptrfunc = calloc(nmelements, sizeof(int));
// 	printf("Resultat ma fonction :$%s$ \n", ptrme);
// 	printf("Resultat fonction originelle : $%s$\n", ptrfunc);
// 	printf("comparaison mem %d", memcmp((void *)ptrme, (void *)
//ptrfunc, nmelements * sizeof(int)));
// 	free (ptrme);
// 	free (ptrfunc);
// 	return (0);
// }