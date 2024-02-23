/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:10 by anferre           #+#    #+#             */
/*   Updated: 2024/02/23 16:58:20 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"


static void ft_recenter(t_coor *coor, t_size *size, t_coor mincoor, t_coor maxcoor)
{
	t_coor	middlecoor;
	t_coor	delta;
	int		i;

	i = 0;
	mincoor = ft_get_mincoor(coor, size);
	maxcoor = ft_get_maxcoor(coor, size);
	middlecoor.x = (maxcoor.x + mincoor.x) / 2;
	middlecoor.y = (maxcoor.y + mincoor.y) / 2;
	delta.x = WINDOW_WIDTH  / 2 - middlecoor.x;
	delta.y = WINDOW_HEIGTH / 2 - middlecoor.y;
	while (i < ((*size).rows * (*size).cols))
	{
		coor[i].x += delta.x;
		coor[i].y += delta.y;
		i++;
	}

}

static void *ft_resize(t_size *size, t_coor	*coor)
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
	scale.dx = (WINDOW_WIDTH - 2 * WINDOW_MARGIN) / deltacoor.dx;
	scale.dy = (WINDOW_HEIGTH - 2 * WINDOW_MARGIN) / deltacoor.dy;
	ft_minimum(&scale);
	while (i < ((*size).rows * (*size).cols))
	{
		coor[i].x = round(coor[i].dy * scale.dx);
		coor[i].y = round(coor[i].dx * scale.dy);
		i++;
	}
	ft_recenter(coor, size, mincoor, maxcoor);
	return (coor);
}

void	*ft_convert_to_isometric(int **array3d, t_size *size, t_coor *coor)
{
	int		i;
	int		j;

	i = 0;
	size->a = asin(tan(M_PI / 6));
	size->b =  M_PI / 4;
	while (i < (*size).rows)
	{
		j = 0;
		while (j < (*size).cols)
		{
			coor[j + i * (*size).cols].dx = cos(size->b) * j + sin(size->b) * sin(size->a) \
			* i + sin(size->b) * cos(size->a) * array3d[i][j];
			coor[j + i * (*size).cols].dy = cos(size->a) * i - sin(size->a) * array3d[i][j];
			j++;
		}
		i++;
	}
	coor = ft_resize(size, coor);
	return ( coor);
}

static void ft_draw_line(t_coor start, t_coor end, t_data_img *data_img, int color) 
{
	t_coor	diff;
	t_coor	in;
	int		err;
	int		err2;

	if (start.x == end.x && start.y == end.y)
		return ;
	diff.x = abs(end.x - start.x);
	diff.y = abs(end.y - start.y);
	err = diff.x - diff.y;
	if (start.x < end.x)
		in.x = 1;
	else
		in.x = -1;
	if (start.y < end.y)
		in.y = 1;
	else
		in.y = -1;
	while (start.x != end.x || start.y != end.y)
	{
		ft_mlx_pixel_put(data_img, start.x, start.y, color);
		err2 = 2 * err;
		if (err2 > -diff.y)
		{
			err -= diff.y;
			start.x += in.x;
		}
		if (err2 < diff.x)
		{
			err += diff.x;
			start.y += in.y;
		}
	}
}

void	ft_print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size->rows)
	{
		j = 0;
		while (j < data->size->cols)
		{
			ft_mlx_pixel_put(data->data_img, data->coor[(j + i * data->size->cols)].x, data->coor[(j + i * data->size->cols)].y, WHITE_COLOR);
			if (j < data->size->cols - 1)
				ft_draw_line(data->coor[(j + i * data->size->cols)], data->coor[(j + i * data->size->cols) + 1], data->data_img, WHITE_COLOR);
			if (i < data->size->rows - 1)
				ft_draw_line(data->coor[(j + i * data->size->cols)], data->coor[(j + (i + 1) * data->size->cols)], data->data_img, WHITE_COLOR);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->data_img->img, 0, 0);
}


void	*ft_project(t_data *data)
{

	ft_convert_to_isometric(data->array3d, data->size, data->coor);
	mlx_loop_hook(data->mlx->mlx_win, ft_render, data);
	mlx_key_hook(data->mlx->mlx_win, ft_handle_input, data);
	// mlx_hook(mlx->mlx_win, 2, (1L<<0), , );
	mlx_hook(data->mlx->mlx_win, 17, (1L<<17), ft_handle_notify, data->mlx);
	mlx_loop(data->mlx->mlx);
	return (0);
}

// rotate clock wise 
// tempx = *x
// *x = cos(angle) * tempX - sin(angle) * *z;
// *z = sin(angle) * tempX + cos(angle) * *z;
//rotate counter clock wise 
// *x = cos(angle) * tempX + sin(angle) * *z;
// *z = -sin(angle) * tempX + cos(angle) * *z;
