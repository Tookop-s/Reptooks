/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_zoom_scale_translate.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:30 by anferre           #+#    #+#             */
/*   Updated: 2024/03/04 18:02:04 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	ft_rotate(t_data *data, int keysym)
{
	double	rx;

	rx = 0.05;
	if (keysym == XK_Right)
		data->size->y += rx;
	else if (keysym == XK_Left)
		data->size->y -= rx;
	else if (keysym == XK_Up)
		data->size->x += rx;
	else if (keysym == XK_Down)
		data->size->x -= rx;
	else if (keysym == XK_o)
		data->size->z += rx;
	else if (keysym == XK_p)
		data->size->z -= rx;
	else
		return (0);
	data->size->x = fmod(data->size->x, 2 * M_PI);
	data->size->y = fmod(data->size->y, 2 * M_PI);
	data->size->z = fmod(data->size->z, 2 * M_PI);
	ft_rotate_render(data);
	return (1);
}

int	ft_translate(t_data *data, int keysym)
{
	int	i;
	int	y;
	int	x;

	i = -1;
	x = 0;
	y = 0;
	if (keysym == XK_KP_Down)
		y = 10;
	if (keysym == XK_KP_Up)
		y = -10;
	if (keysym == XK_KP_Right)
		x = 10;
	if (keysym == XK_KP_Left)
		x = -10;
	while (++i < (data->size->rows * data->size->cols))
		data->coor[i].x += x;
	i = -1;
	while (++i < (data->size->rows * data->size->cols))
		data->coor[i].y += y;
	return (1);
}

int	ft_zoom(t_data *data, int keysym)
{	
	if (keysym == XK_KP_Add)
	{
		data->size->scale_f += 1;
		ft_rotate_render(data);
		return (1);
	}
	if (keysym == XK_KP_Subtract)
	{
		data->size->scale_f -= 1;
		ft_rotate_render(data);
		return (1);
	}
	return (0);
}

int	ft_scale(t_data *data, int keysym)
{
	if (keysym == XK_Page_Up)
	{
		data->size->scale_z += 0.1;
		ft_rotate_render(data);
		return (1);
	}
	if (keysym == XK_Page_Down)
	{
		if (data->size->scale_z - 0.1 > 0.1)
			data->size->scale_z -= 0.1;
		ft_rotate_render(data);
		return (1);
	}
	return (0);
}
