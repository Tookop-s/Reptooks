/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:54:30 by anferre           #+#    #+#             */
/*   Updated: 2024/02/28 18:24:58 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	ft_rotate_x(t_data *data)
{
	t_coor temp;
	int	y;
	int	x;
	int	i;

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
			data->coor[i].dy = cos(data->size->x) * temp.dy - sin(data->size->x) * temp.dz;
			data->coor[i].dz = sin(data->size->x) * temp.dy + cos(data->size->x) * temp.dz;
			x++;
		}
		y++;
	}
}

static void	ft_rotate_y(t_data *data)
{
		t_coor temp;
	int	y;
	int	x;
	int	i;

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
			data->coor[i].dx = cos(data->size->y) * temp.dx + sin(data->size->y) * temp.dz;
			data->coor[i].dy = temp.dy;
			data->coor[i].dz = sin(data->size->y) * temp.dx + cos(data->size->y) * temp.dz;
			x++;
		}
		y++;
	}
}

static void	ft_rotate_z(t_data *data)
{
	t_coor temp;
	int	y;
	int	x;
	int	i;

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
			data->coor[i].dx = cos(data->size->z) * temp.dx - sin(data->size->z) * temp.dy;
			data->coor[i].dy = sin(data->size->z) * temp.dx + cos(data->size->z) * temp.dy;
			data->coor[i].dz = temp.dz;
			x++;
		}
		y++;
	}
}

// static void	ft_rotate_2d(t_data *data)
// {
// 	int		i;
// 	double	a;

// 	i = 0;
// 	a = data->size->x;
// 	while (i < (data->size->rows * data->size->cols))
// 	{
// 		data->coor[i].x -= data->size->middle_x;
// 		data->coor[i].y -= data->size->middle_y;
// 		i++;
// 	}
// 	i = 0;
// 		while (i < (data->size->rows * data->size->cols))
// 	{
// 		data->coor[i].x = round(cos(a) * data->coor[i].x - sin(a) * data->coor[i].y);
// 		data->coor[i].y = round(sin(a) * data->coor[i].x + cos(a) * data->coor[i].y);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < (data->size->rows * data->size->cols))
// 	{
// 		data->coor[i].x += data->size->middle_x;
// 		data->coor[i].y += data->size->middle_y;
// 		i++;
// 	}
// }
// ft_rotate_2d(data);

void	ft_rotate_render(t_data *data)
{
	ft_printf("before rotate \n");
	ft_print_coor(data->coor, data->size);
	if (data->size->x != 0)
		ft_rotate_x(data);
	if (data->size->y != 0)
		ft_rotate_y(data);
	if (data->size->y != 0)
		ft_rotate_z(data);

	ft_printf("after rotate \n");
	ft_print_coor(data->coor, data->size);
	ft_get_middle_coor(data->coor, data->size);
	ft_convert_to_isometric(data->size, data->coor);
	ft_reposition(data->coor, data->size, data->size->middle_x, data->size->middle_y);
}

int	ft_rotate(t_data *data, int	keysym)
{
	double rx;

	rx = 0.1;
	if (keysym == XK_Right)
		data->size->y += rx;
	else if (keysym == XK_Left)
		data->size->y -= rx;
	else if (keysym == XK_Up)
		data->size->x += rx;
	else if (keysym == XK_Down)
		data->size->x -= rx;
	else if (keysym == XK_O || keysym == XK_o)
		data->size->z += rx;
	else if (keysym == XK_P || keysym == XK_p)
		data->size->z -= rx;
	else
		return(0);
	ft_rotate_render(data);
	return (1);
}
