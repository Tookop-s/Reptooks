/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:18:50 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:45:07 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s)
		s++;
	while (s != str && *s != (char)c)
		s--;
	if (*s == (char)c)
		return (s);
	return (0);
}

//returns a pointer to the last occurrence of the character c in the string s.
// #include<stdio.h>

// int main()
// {
// 	const char *s = "Hello world";
// 	char c = 'l';
// 	printf("%s", ft_strrchr(s, c));
// 	return (0);
// }