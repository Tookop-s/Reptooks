/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:04:16 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:44:48 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string
// char	ft_mappi(unsigned int i, char c)
// {
// 	if (i >= 1)
// 	 if (c >= 'a' && c <= 'z')
// 	 	c -= 32;
// 	return (c);
// }

// #include<stdio.h>

// int main()
// {
// 	char *s = "override this !";
// 	char (*ptr)(unsigned int, char) = ft_mappi;
// 	char *me = ft_strmapi(s, (*ptr));
// 	printf("%s", me);
// 	free (me);
// 	return (0);
// }