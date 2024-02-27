/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:07 by anferre           #+#    #+#             */
/*   Updated: 2024/02/27 15:37:43 by anferre          ###   ########.fr       */
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
		coor[i].dz = 0;
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


void	ft_minimum(t_coor *comp)
{
	if (comp->dx > comp->dy)
		comp->x = (int)comp->dy;
	else
		comp->y = (int)comp->dx;
}
t_coor	ft_get_mincoor(t_coor *coor, t_size *size)
{
	int		i;
	t_coor	mincoor;

	i = 0;
	mincoor.dx = coor[0].dx;
	mincoor.dy = coor[0].dy;
	mincoor.x = coor[0].x;
	mincoor.y = coor[0].y;
	while (i < ((*size).rows * (*size).cols))
	{
		if (mincoor.dx > coor[i].dx) 
			mincoor.dx = coor[i].dx;
		if (mincoor.dy > coor[i].dy)
			mincoor.dy = coor[i].dy;
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
	maxcoor.dx = coor[0].dx;
	maxcoor.dy = coor[0].dy;
	maxcoor.x = coor[0].x;
	maxcoor.y = coor[0].y;
	while (i < ((*size).rows * (*size).cols))
	{
		if (maxcoor.dx < coor[i].dx)
			maxcoor.dx = coor[i].dx;
		if (maxcoor.dy < coor[i].dy)
			maxcoor.dy = coor[i].dy;
		if (maxcoor.x < coor[i].x) 
			maxcoor.x = coor[i].x;
		if (maxcoor.y < coor[i].y)
			maxcoor.y = coor[i].y;
		i++;
	}
	return (maxcoor);
}
