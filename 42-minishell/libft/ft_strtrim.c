/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:10:49 by gchamore          #+#    #+#             */
/*   Updated: 2024/05/17 15:07:33 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tri1(char const*s1, char const *set, int i)
{
	int		y;
	int		count;

	y = 0;
	count = 0;
	while (s1[i] && count == 0)
	{
		while (s1[i] != set[y])
		{
			y++;
			if (set[y] == '\0')
			{
				count = 1;
				break ;
			}
		}
		y = 0;
		if (count == 0)
			i++;
	}
	return (i);
}

static int	ft_tri2(char const*s1, char const *set, int j)
{
	int		y;
	int		count;

	y = 0;
	count = 0;
	while (s1[j])
		j++;
	j = j - 1;
	while (s1[j] && count == 0)
	{
		while (s1[j] != set[y])
		{
			y++;
			if (set[y] == '\0')
			{
				count = 1;
				break ;
			}
		}
		y = 0;
		if (count == 0)
			j--;
	}
	j = j + 2;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	size_t	substr_len;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return ((char *)s1);
	if (set[0] == '\0')
		return (ft_strdup((char *)s1));
	i = ft_tri1(s1, set, 0);
	j = ft_tri2(s1, set, 0);
	if (i >= j)
		return (ft_strdup(""));
	substr_len = j - i - 1;
	return (ft_substr((char *)s1, i, substr_len));
}

//	La fonction ft_strtrim prend une chaîne de caractères
//	s1 et supprime les caractères spécifiés dans l'ensemble
//	set du début et de la fin de la chaîne.
//	La fonction renvoie une nouvelle chaîne de caractères
//	résultante, avec les caractères indésirables supprimés.

// #include <stdio.h>
// #include <string.h>

// int main() 
// {
//     const char *s1 = "abcd";
//     const char *set = "";
//     char *str;

// 	str = ft_strtrim(s1, set);
//     printf("Chaîne originale: '%s'\n", s1);
//     printf("Chaîne après trim: '%s'\n", str);

//     free(str);

//     return 0;
// }