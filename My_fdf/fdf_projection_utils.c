/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:07 by anferre           #+#    #+#             */
/*   Updated: 2024/02/22 10:46:18 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	*ft_new_coor(t_size *size)
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
		i++;
	}
	return (coor);
}

void	*ft_new_dcoor(t_size *size)
{
	t_dcoor	*dcoor;
	int	i;

	i = 0;
	dcoor = malloc(((*size).rows * (*size).cols) * sizeof(t_dcoor));
	if (!dcoor)
		return (NULL);
	while (i < (*size).rows * (*size).cols )
	{
		dcoor[i].x = 0;
		dcoor[i].y = 0;
		i++;
	}
	return (dcoor);
}

void	ft_free_coor(t_coor *coor)
{
	if (!coor)
		return ;
	free(coor);
}

void	ft_free_dcoor(t_dcoor *dcoor)
{
	if (!dcoor)
		return ;
	free(dcoor);
}

void	ft_free_all(int **array, t_coor *coor, t_size *size, t_dcoor *dcoor)
{
	ft_free_coor(coor);
	ft_free_dcoor(dcoor);
	ft_free_array(array, size->rows);
	if (size)
		free(size);
}

void	ft_minimum(t_dcoor comp, double *dscale)
{
	if (comp.x > comp.y)
		*dscale = comp.y;
	else
		*dscale = comp.x;
}
t_dcoor	ft_get_mincoor(t_dcoor *dcoor, t_size *size)
{
	int		i;
	t_dcoor	mincoor;

	i = 0;
	mincoor.x = dcoor[0].x;
	mincoor.y = dcoor[0].y;
	while (i < ((*size).rows * (*size).cols))
	{
		if (mincoor.x > dcoor[i].x) 
			mincoor.x = dcoor[i].x;
		if (mincoor.y > dcoor[i].y)
			mincoor.y = dcoor[i].y;
		i++;
	}
	return (mincoor);
}

t_dcoor	ft_get_maxcoor(t_dcoor *dcoor, t_size *size)
{
	int		i;
	t_dcoor	maxcoor;

	i = 0;
	maxcoor.x = dcoor[0].x;
	maxcoor.y = dcoor[0].y;
	while (i < ((*size).rows * (*size).cols))
	{
		if (maxcoor.x < dcoor[i].x)
			maxcoor.x = dcoor[i].x;
		if (maxcoor.y < dcoor[i].y)
			maxcoor.y = dcoor[i].y;
		i++;
	}
	return (maxcoor);
}
