/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:13:55 by anferre           #+#    #+#             */
/*   Updated: 2023/11/20 17:44:33 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}

//Applies the function ’f’ on each character of
//the string passed as argument, passing its index
//as first argument.
// void ft_mappi(unsigned int i, char *c)
// {
// 	if (i >= 1 && *c >= 32)
// 	 if (*c >= 'a' && *c <= 'z')
// 	 	*c -= 32;
// }
// #include<stdio.h>

// int main()
// {
// 	char s[] = " Hello world !";
// 	void (*ptr)(unsigned int, char*) = ft_mappi;
// 	ft_striteri(s, (*ptr));
// 	printf("%s", s);
// 	return (0);
// }
