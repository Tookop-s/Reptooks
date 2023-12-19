/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:24:56 by anferre           #+#    #+#             */
/*   Updated: 2023/11/22 13:06:55 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.
//if (start >= ft_strlen(s)) means start is after the char *s
//if (len > ft_strlen(s + start)) means len is too big
// #include<stdio.h>

// int main()
// {
// 	// char const* s = "";
// 	char *me = ft_substr("tripoulle", 15, 15);
// 	printf("%s\n", me);
// 		free(me);
// }
