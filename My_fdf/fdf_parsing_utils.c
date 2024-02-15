/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:14:20 by anferre           #+#    #+#             */
/*   Updated: 2024/02/14 17:04:53 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_new_array(int rows, int cols)
{
	int	**array;
	int	i;

	i = 0;
	array = malloc(rows * sizeof(int*));
	if (!array)
		return (NULL);
	while (i < rows)
	{
		array[i] = malloc(cols * sizeof(int));
		if (!array)
			return(NULL);
		i++;
	}
	return (array);
}

void	ft_free_array(int **array, int rows)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_split(char **str, int cols)
{
	int	j;

	j = 0;
	while (j < cols)
	{
		free(str[j]);
		j++;
	}
	free (str);
}

void	*ft_init_size()
{
	t_size	*size;

	size = malloc(sizeof(t_size));
	if (!size)
		return (NULL);
	return (size);
}
