/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:07 by anferre           #+#    #+#             */
/*   Updated: 2024/02/14 16:28:14 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_new_coor(t_size *size)
{
	t_coor	**coor;
	int	i;

	i = 0;
	coor = malloc((*size).rows * sizeof(t_coor*));
	if (!coor)
		return (NULL);
	while (i < (*size).rows)
	{
		coor[i] = malloc((*size).cols * sizeof(t_coor));
		if (!coor)
			return(NULL);
		i++;
	}
	return (coor);
}

void	ft_free_coor(t_coor **coor, t_size *size)
{
	int	i;

	i = 0;
	if (!coor)
		return ;
	while (i < (*size).rows)
	{
		free(coor[i]);
		i++;
	}
	free(coor);
}

void	ft_free_all(int **array, t_coor **coor, t_size *size)
{
	ft_free_coor(coor, size);
	ft_free_array(array, size->rows);
}