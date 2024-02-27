/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:30 by anferre           #+#    #+#             */
/*   Updated: 2024/02/27 17:03:21 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	ft_rotate_x(t_data *data)
{
	t_coor temp;
	int	i;
	int	j;

	i = 0;
	while (i < data->size->rows)
	{
		j = 0;
		while (j < data->size->cols)
		{
			temp.dx = j;
			temp.dy = i;
			temp.dz = data->coor[j + i *data->size->cols].dz;
			data->coor[j + i *data->size->cols].dx = temp.dx;
			data->coor[j + i *data->size->cols].dy = cos(data->size->x) * temp.dy - sin(data->size->x) * temp.dz;
			data->coor[j + i *data->size->cols].dz = sin(data->size->x) * temp.dy + cos(data->size->x) * temp.dz;
			j++;
		}
		i++;
	}
}

static void	ft_rotate_y(t_data *data)
{
		t_coor temp;
	int	i;
	int	j;

	i = 0;
	while (i < data->size->rows)
	{
		j = 0;
		while (j < data->size->cols)
		{
			temp.dx = j;
			temp.dy = i;
			temp.dz = data->coor[j + i *data->size->cols].dz;
			data->coor[j + i *data->size->cols].dx = cos(data->size->y) * temp.dx + sin(data->size->y) * temp.dz;
			data->coor[j + i *data->size->cols].dy = temp.dy;
			data->coor[j + i *data->size->cols].dz = sin(data->size->y) * temp.dx + cos(data->size->y) * temp.dz;
			j++;
		}
		i++;
	}
}

static void	ft_rotate_z(t_data *data)
{
	t_coor temp;
	int	i;
	int	j;

	i = 0;
	while (i < data->size->rows)
	{
		j = 0;
		while (j < data->size->cols)
		{
			temp.dx = j;
			temp.dy = i;
			temp.dz = data->coor[j + i *data->size->cols].dz;
			data->coor[j + i *data->size->cols].dx = cos(data->size->z) * temp.dx - sin(data->size->z) * temp.dy;
			data->coor[j + i *data->size->cols].dy = temp.dy;
			data->coor[j + i *data->size->cols].dz = sin(data->size->z)* temp.dx + cos(data->size->z) * temp.dy;
			j++;
		}
		i++;
	}
}

void	ft_rotate_render(t_data *data)
{
	ft_rotate_x(data);
	ft_rotate_y(data);
	ft_rotate_z(data);
	ft_get_middle_coor(data->coor, data->size);
	ft_convert_to_isometric(data->size, data->coor);
	ft_replace(data->coor, data->size, data->size->middle_x, data->size->middle_y);
}

int	ft_rotate(t_data *data, int	keysym)
{
	double rx;

	rx = 1;
	if (keysym == XK_Right)
		data->size->x += rx;
	else if (keysym == XK_Left)
		data->size->x -= rx;
	else if (keysym == XK_Up)
		data->size->y += rx;
	else if (keysym == XK_Down)
		data->size->y -= rx;
	else if (keysym == XK_O || keysym == XK_o)
		data->size->z += rx;
	else if (keysym == XK_P || keysym == XK_p)
		data->size->z -= rx;
	else
		return(0);
	ft_rotate_render(data);
	return (1);
}
