/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data_processing_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:51:36 by anferre           #+#    #+#             */
/*   Updated: 2024/03/01 15:14:37 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_coor	ft_get_mincoor(t_coor *coor, t_size *size)
{
	int		i;
	t_coor	mincoor;

	i = 0;
	mincoor.dx = coor[0].dx;
	mincoor.dy = coor[0].dy;
	mincoor.iz = coor[0].iz;
	mincoor.x = coor[0].x;
	mincoor.y = coor[0].y;
	while (i < ((*size).rows * (*size).cols))
	{
		if (mincoor.dx > coor[i].dx)
			mincoor.dx = coor[i].dx;
		if (mincoor.dy > coor[i].dy)
			mincoor.dy = coor[i].dy;
		if (mincoor.iz > coor[i].iz)
			mincoor.iz = coor[i].iz;
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
	maxcoor.iz = coor[0].iz;
	maxcoor.x = coor[0].x;
	maxcoor.y = coor[0].y;
	while (i < ((*size).rows * (*size).cols))
	{
		if (maxcoor.dx < coor[i].dx)
			maxcoor.dx = coor[i].dx;
		if (maxcoor.dy < coor[i].dy)
			maxcoor.dy = coor[i].dy;
		if (maxcoor.iz < coor[i].iz)
			maxcoor.iz = coor[i].iz;
		if (maxcoor.x < coor[i].x)
			maxcoor.x = coor[i].x;
		if (maxcoor.y < coor[i].y)
			maxcoor.y = coor[i].y;
		i++;
	}
	return (maxcoor);
}

void	ft_get_middle_coor(t_coor *coor, t_size *size)
{
	t_coor	mincoor;
	t_coor	maxcoor;

	mincoor = ft_get_mincoor(coor, size);
	maxcoor = ft_get_maxcoor(coor, size);
	size->middle_x = (maxcoor.x + mincoor.x) / 2;
	size->middle_y = (maxcoor.y + mincoor.y) / 2;
}

void	ft_minimum(t_coor *comp)
{
	if (comp->dx > comp->dy)
		comp->dx = comp->dy;
	else
		comp->dy = comp->dx;
	if (comp->ix > comp->iy && comp->iz > comp->iy)
	{
		comp->ix = comp->iy;
		comp->iz = comp->iy;
	}
	else if (comp->iy > comp->ix && comp->iz > comp->ix)
	{
		comp->iy = comp->ix;
		comp->iz = comp->ix;
	}
	else
	{
		comp->iy = comp->iz;
		comp->ix = comp->iz;
	}
}

void	ft_init_coor(t_coor *coor)
{
	coor->x = 0;
	coor->y = 0;
	coor->dz = 0;
	coor->dx = 0;
	coor->dy = 0;
	coor->iz = 0;
	coor->ix = 0;
	coor->iy = 0;
	coor->clr = 0;
}