/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:07 by anferre           #+#    #+#             */
/*   Updated: 2024/02/20 14:49:35 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	*ft_new_coor(t_size *size)
{
	t_coor	*coor;
	int	i;

	i = 0;
	coor = malloc(((*size).rows * (*size).cols) * sizeof(t_coor*));
	if (!coor)
		return (NULL);
	while (i < (*size).rows * (*size).cols )
	{
		coor[i].x = 0;
		coor[i].y = 0;
		i++;
	}
	return (coor);
}

void	ft_free_coor(t_coor *coor)
{
	if (!coor)
		return ;
	free(coor);
}

void	ft_free_all(int **array, t_coor *coor, t_size *size)
{
	ft_free_coor(coor);
	ft_free_array(array, size->rows);
	if (size)
		free(size);
}

double	ft_min(t_dcoor comp)
{
	if (comp.x > comp.y)
		return (comp.y);
	else
		return (comp.x);
}
