/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:29:05 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:44:30 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
//returns a pointer to a new allocated string 
//which is a duplicate of the string s.
// #include<stdio.h>

// int main ()
// {
// 	const char *str = "hello";
// 	char *me = ft_strdup(str);
// 	char *func = strdup(str);
// 	printf("Resultat ma fonction :%s \n", me);
// 	printf("Resultat fonction originelle : %s\n", func);
// 	free (me);
// 	free (func);
// 	return (0);
// }