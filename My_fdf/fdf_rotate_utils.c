/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:30 by anferre           #+#    #+#             */
/*   Updated: 2024/03/04 18:00:57 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	ft_check_rotate(t_coor *temp, t_data *data, int i, char c)
{
	if (data->size->x)
	{
		temp->dx = data->coor[i].dx;
		temp->dy = data->coor[i].dy;
		temp->dz = data->coor[i].dz;
	}
	if (data->size->y && c == 'z')
	{
		temp->dx = data->coor[i].dx;
		temp->dy = data->coor[i].dy;
		temp->dz = data->coor[i].dz;
	}
	else if (!data->size->x)
	{
		temp->dx = data->coor[i].ix;
		temp->dy = data->coor[i].iy;
		temp->dz = data->coor[i].iz;
	}
}

static	void	ft_rotate_x(t_data *data)
{
	t_coor	temp;
	int		y;
	int		x;
	int		i;

	y = 0;
	while (y < data->size->rows)
	{
		x = 0;
		while (x < data->size->cols)
		{
			i = x + y * data->size->cols;
			temp.dx = data->coor[i].ix;
			temp.dy = data->coor[i].iy;
			temp.dz = data->coor[i].iz;
			data->coor[i].dx = temp.dx;
			data->coor[i].dy = cos(data->size->x) * \
			temp.dy - sin(data->size->x) * temp.dz;
			data->coor[i].dz = sin(data->size->x) * \
			temp.dy + cos(data->size->x) * temp.dz;
			x++;
		}
		y++;
	}
}

static void	ft_rotate_y(t_data *data)
{
	t_coor	temp;
	int		y;
	int		x;
	int		i;

	y = 0;
	while (y < data->size->rows)
	{
		x = 0;
		while (x < data->size->cols)
		{
			i = x + y * data->size->cols;
			ft_check_rotate(&temp, data, i, 'y');
			data->coor[i].dx = cos(data->size->y) * \
			temp.dx + sin(data->size->y) * temp.dz;
			data->coor[i].dy = temp.dy;
			data->coor[i].dz = sin(data->size->y) * \
			temp.dx + cos(data->size->y) * temp.dz;
			x++;
		}
		y++;
	}
}

static void	ft_rotate_z(t_data *data)
{
	t_coor	temp;
	int		y;
	int		x;
	int		i;

	y = 0;
	while (y < data->size->rows)
	{
		x = 0;
		while (x < data->size->cols)
		{
			i = x + y * data->size->cols;
			ft_check_rotate(&temp, data, i, 'z');
			data->coor[i].dx = cos(data->size->z) * \
			temp.dx - sin(data->size->z) * temp.dy;
			data->coor[i].dy = sin(data->size->z) * \
			temp.dx + cos(data->size->z) * temp.dy;
			data->coor[i].dz = temp.dz;
			x++;
		}
		y++;
	}
}

void	ft_rotate_render(t_data *data)
{
	int	i;

	i = 0;
	if (data->size->x != 0)
		ft_rotate_x(data);
	if (data->size->y != 0)
		ft_rotate_y(data);
	if (data->size->z != 0)
		ft_rotate_z(data);
	if (data->size->x == 0 && data->size->y == 0 && data->size->z == 0)
	{
		while (i < data->size->cols * data->size->rows)
		{
			data->coor[i].dx = data->coor[i].ix;
			data->coor[i].dy = data->coor[i].iy;
			data->coor[i].dz = data->coor[i].iz;
			i++;
		}
	}
}
