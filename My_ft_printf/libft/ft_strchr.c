/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:30:09 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:56:32 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return (s);
	return (0);
}
// returns a pointer to the first occurrence of the character c in the string s.
// #include<stdio.h>

// int main()
// {
// 	const char *s = "teste";
// 	// char c = 'e';
// 	printf("%s", ft_strchr(s, 't' + 256));
// 	return (0);
// }
