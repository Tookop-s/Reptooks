/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:52:19 by anferre           #+#    #+#             */
/*   Updated: 2024/05/15 17:45:25 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char *str)
{
	int	i;
	int	check;
	int	sum;

	i = 0;
	check = 1;
	sum = 0;
	while (str[i])
	{
		if (str[i] == ' ' | str[i] == '\t')
			check = 1;
		else if (check == 1)
		{
			sum++;
			check = 0;
		}
		i++;
	}
	return (sum);
}
