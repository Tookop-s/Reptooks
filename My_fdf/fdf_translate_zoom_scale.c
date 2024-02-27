/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translate_zoom_scale.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:30 by anferre           #+#    #+#             */
/*   Updated: 2024/02/27 17:03:45 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	ft_translate(t_data *data, int keysym)
{
	int i;
	int y;
	int x;

	i = 0;
	if (keysym == XK_KP_Down)
		x = 5;
	if (keysym == XK_KP_Up)
		y = -5;
	if (keysym == XK_KP_Right)
		y = 5;
	if (keysym == XK_KP_Left)
		x = -5;
	while (i < (data->size->rows * data->size->cols))
	{
		data->coor[i].x += x;
		i++;
	}
	i = 0;
	while (i < (data->size->rows * data->size->cols))
	{
		data->coor[i].y += y;
		i++;
	}
	return(1);
}

int	ft_zoom(t_data *data, int keysym)
{	
	if (keysym == XK_KP_Add )
	{
		data->size->scale_x += 1;
		data->size->scale_y += 1;
		ft_get_middle_coor(data->coor, data->size);
		ft_convert_to_isometric( data->size, data->coor);
		ft_replace(data->coor, data->size, data->size->middle_x, data->size->middle_y);
		return (1);
	}
	if (keysym == XK_KP_Subtract)
	{
		data->size->scale_x -= 1;
		data->size->scale_y -= 1;
		ft_get_middle_coor(data->coor, data->size);
		ft_convert_to_isometric(data->size, data->coor);
		ft_replace(data->coor, data->size, data->size->middle_x, data->size->middle_y);
		return (1);
	}
	return (0);
}

int	ft_scale(t_data *data, int keysym)
{
	if (keysym == XK_Page_Up)
	{
		data->size->scale_z += 0.1;
		ft_get_middle_coor(data->coor, data->size);
		ft_convert_to_isometric(data->size, data->coor);
		ft_replace(data->coor, data->size, data->size->middle_x, data->size->middle_y);
		return (1);
	}
	if (keysym == XK_Page_Down)
	{
		data->size->scale_z -= 0.1;
		ft_get_middle_coor(data->coor, data->size);
		ft_convert_to_isometric(data->size, data->coor);
		ft_replace(data->coor, data->size, data->size->middle_x, data->size->middle_y);
		return (1);
	}
	return (0);
}