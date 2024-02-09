/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:04:49 by anferre           #+#    #+#             */
/*   Updated: 2023/11/21 12:17:50 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countnbsize(int n)
{
	long int		temp;
	unsigned int	nsize;

	temp = n;
	nsize = 1;
	if (temp < 0)
	{
		temp *= -1;
		nsize++;
	}
	while (temp > 9)
	{
		temp /= 10;
		nsize++;
	}
	return (nsize);
}

char	*ft_fillstr(char *s, long int nb, int i)
{
	while (nb > 9)
	{
		s[i] = (nb % 10 + '0');
		nb /= 10;
		i--;
	}
	s[i] = (nb % 10 + '0');
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	i;
	unsigned int	nbsize;
	long int		nb;

	i = 0;
	nb = n;
	nbsize = ft_countnbsize(nb);
	s = (char *)malloc((nbsize + 1));
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		s[i] = '-';
		nb *= -1;
	}
	i = nbsize;
	s[i] = '\0';
	i--;
	ft_fillstr(s, nb, i);
	return (s);
}

//transform an int to an allocated char *s
// #include<stdio.h>

// int main()
// {
// 	int n = -1;
// 	char *s = ft_itoa(n);
// 	char *s1= itoa(n);
// 	printf("Ma fonction : %s\n", s);
// 	printf("Fonction originelle :%s\n", s1);
// 	free (s);
// 	free (s1);
// 	return (0);
// }