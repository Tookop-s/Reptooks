/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:49:58 by anferre           #+#    #+#             */
/*   Updated: 2024/02/29 16:50:55 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_recenter(t_coor *coor, t_size *size, int width, int height)
{
	t_coor	delta;
	int		i;

	i = 0;
	ft_get_middle_coor(coor, size);
	delta.x = width  / 2 - size->middle_x;
	delta.y = height / 2 - size->middle_y;
	while (i < ((*size).rows * (*size).cols))
	{
		coor[i].x += delta.x;
		coor[i].y += delta.y;
		i++;
	}
}

void	ft_reposition(t_coor *coor, t_size *size, int prevmid_x, int prevmid_y)
{
	t_coor	delta;
	int		i;

	i = 0;
	ft_get_middle_coor(coor, size);
	delta.x = prevmid_x  - size->middle_x;
	delta.y = prevmid_y - size->middle_y;
	while (i < ((*size).rows * (*size).cols))
	{
		coor[i].x += delta.x;
		coor[i].y += delta.y;
		i++;
	}	
}

void	*ft_resize_3d(t_size *size, t_coor *coor)
{
	t_coor	maxcoor;
	t_coor	mincoor;
	t_coor deltacoor;
	t_coor scale;
	int		i;

	i = 0;
	maxcoor = ft_get_maxcoor(coor, size);
	mincoor = ft_get_mincoor(coor, size);
	deltacoor.ix = size->cols;
	deltacoor.iy = size->rows;
	deltacoor.iz = maxcoor.iz - mincoor.iz;
	scale.ix = (WIN_WIDTH - 2 * WIN_MARGIN) / deltacoor.ix;
	scale.iy = (WIN_HEIGTH - 2 * WIN_MARGIN) / deltacoor.iy;
	scale.iz = (WIN_HEIGTH - 2 * WIN_MARGIN) / deltacoor.iz;
	ft_minimum(&scale);
	while ((i < ((*size).rows * (*size).cols) && scale.dx != 0))
	{
		coor[i].ix *= scale.ix;
		coor[i].iy *= scale.iy;
		coor[i].iz *= scale.iz;
		i++;
	}
	return (coor);
}

void	*ft_resize_2d(t_size *size, t_coor *coor)
{
	t_coor mincoor;
	t_coor maxcoor;
	t_coor deltacoor;
	t_coor scale;
	int		i;

	i = 0;
	mincoor = ft_get_mincoor(coor, size);
	maxcoor = ft_get_maxcoor(coor, size);
	deltacoor.dx = maxcoor.dx - mincoor.dx;
	deltacoor.dy = maxcoor.dy - mincoor.dy;
	scale.dx = (WIN_WIDTH - 2 * WIN_MARGIN) / deltacoor.dx + size->scale_f;
	scale.dy = (WIN_HEIGTH - 2 * WIN_MARGIN) / deltacoor.dy + size->scale_f;
	ft_minimum(&scale);
	while ((i < ((*size).rows * (*size).cols) && scale.dx != 0))
	{
		coor[i].x = round(coor[i].dx * scale.dx);
		coor[i].y = round(coor[i].dy * scale.dy);
		i++;
	}
	return (coor);
}

void	*ft_convert_to_isometric(t_size *size, t_coor *coor)
{
	int i;
	double arcsin;
	double beta;

	arcsin = asin(tan(M_PI / 6));
	beta = M_PI / 4;
	i = 0;
	while (i < ((*size).rows * (*size).cols))
	{
	
		coor[i].dx = cos(beta) * coor[i].dx + sin(beta) * sin(arcsin) * coor[i].dy + sin(beta) * cos(arcsin) * (coor[i].dz * size->scale_z);
		coor[i].dy = cos(arcsin) * coor[i].dy - sin(arcsin) * (coor[i].dz * size->scale_z);
		i++;
	}
	ft_resize_2d(size, coor);
	return (coor);
}
