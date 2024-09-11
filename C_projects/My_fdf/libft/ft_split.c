/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:21 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 19:10:49 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(char **str, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return ;
}

char	*ft_strlcpymem(char *s, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	i;
	unsigned int	check;
	unsigned int	countw;

	i = 0;
	check = 1;
	countw = 0;
	while (s[i])
	{
		if (s[i] == c)
			check = 1;
		else if (check == 1)
		{
			countw++;
			check = 0;
		}
		i++;
	}
	return (countw);
}

size_t	ft_tabsize(char *s, char c)
{
	unsigned int	i;
	unsigned int	tabcount;

	i = 0;
	tabcount = 0;
	if (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		tabcount++;
		i++;
	}
	return (tabcount);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	counttab;
	char			**str;
	char			*strtemp;

	i = 0;
	if (!s)
		return (NULL);
	counttab = ft_countwords(s, c);
	strtemp = (char *)s;
	str = (char **)malloc((counttab + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < counttab && strtemp[0] != '\0')
	{
		while (*strtemp == c)
			strtemp++;
		str[i] = ft_strlcpymem(strtemp, ft_tabsize(strtemp, c));
		if (!str[i])
			return (ft_freetab(str, i), NULL);
		while (*strtemp != c && *strtemp)
			strtemp++;
		i++;
	}
	return (str[i] = NULL, str);
}
// allocates and return an array of strings  obtained by splitting ’s’ 
//using the character ’c’ as a delimiter.
// #include<stdio.h>

// int main()
// {
// 	char *str = "hello! Antonin";
// 	char c = ' ';
// 	char **me = ft_split(str, c);
// 	unsigned int i;
// 	i = 0;
// 	while (me[i])
// 	{
// 		printf("tableau %d : %s\n", i, me[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (me[i])
// 	{
// 		free(me[i]);
// 		i++;
// 	}
// 	free(me);
// 	return (0);
// }