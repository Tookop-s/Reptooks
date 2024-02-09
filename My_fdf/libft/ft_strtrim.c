/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:36:16 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 13:40:44 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_checkstarttrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	found;

	i = 0;
	j = 0;
	found = 1;
	while (s1[i] && found == 1)
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				found = 1;
				i++;
				break ;
			}
			j++;
		}
	}
	return (i);
}

unsigned int	ft_checkendtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	found;

	i = ft_strlen(s1) - 1;
	j = 0;
	found = 1;
	while (s1[i] && found == 1)
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				found = 1;
				i--;
				break ;
			}
			j++;
		}
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	starttrim;
	unsigned int	endtrim;
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set || set[i] == '\0')
		return (ft_strdup((char *)s1));
	starttrim = ft_checkstarttrim(s1, set);
	if (!(starttrim < ft_strlen(s1)))
		return (ft_strdup(""));
	endtrim = ft_checkendtrim(s1, set);
	str = (char *)malloc((endtrim - starttrim + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (starttrim < endtrim)
	{
		str[i] = s1[starttrim];
		i++;
		starttrim++;
	}
	str[i] = '\0';
	return (str);
}
//  returns an allocated copy of’s1’ with the characters specified
//  in ’set’ removed from the beginning and the end of the string
//if (!(starttrim < ft_strlen(s1))) means we only found set char in *s1
// #include<stdio.h>

// int main()
// {   
// 	char *s = "  \t \t \n   \n\n\n\t";
// 	char *set = " \n\t";
// 	char *me = ft_strtrim(s, set);
// 	printf("%s \n", me);
// 	free(me);
// 	return (0);
// }