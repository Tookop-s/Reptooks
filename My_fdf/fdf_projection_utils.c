/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:07 by anferre           #+#    #+#             */
/*   Updated: 2024/02/22 16:11:29 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	*ft_init_coor(t_size *size)
{
	t_coor	*coor;
	int	i;

	i = 0;
	coor = malloc(((*size).rows * (*size).cols) * sizeof(t_coor));
	if (!coor)
		return (NULL);
	while (i < (*size).rows * (*size).cols )
	{
		coor[i].x = 0;
		coor[i].y = 0;
		coor[i].dx = 0;
		coor[i].dy = 0;
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

void	ft_free_all(int **array, t_coor *coor, t_size *size, t_coor *coor)
{
	ft_free_coor(coor);
	ft_free_coor(coor);
	ft_free_array(array, size->rows);
	if (size)
		free(size);
}

void	ft_minimum(t_coor comp, double *dscale)
{
	if (comp.x > comp.y)
		*dscale = comp.y;
	else
		*dscale = comp.x;
}
t_coor	ft_get_mincoor(t_coor *coor, t_size *size)
{
	int		i;
	t_coor	mincoor;

	i = 0;
	mincoor.x = coor[0].x;
	mincoor.y = coor[0].y;
	while (i < ((*size).rows * (*size).cols))
	{
		if (mincoor.x > coor[i].x) 
			mincoor.x = coor[i].x;
		if (mincoor.y > coor[i].y)
			mincoor.y = coor[i].y;
		i++;
	}
	return (mincoor);
}

t_coor	ft_get_maxcoor(t_coor *coor, t_size *size)
{
	int		i;
	t_coor	maxcoor;

	i = 0;
	maxcoor.x = coor[0].x;
	maxcoor.y = coor[0].y;
	while (i < ((*size).rows * (*size).cols))
	{
		if (maxcoor.x < coor[i].x)
			maxcoor.x = coor[i].x;
		if (maxcoor.y < coor[i].y)
			maxcoor.y = coor[i].y;
		i++;
	}
	return (maxcoor);
}
