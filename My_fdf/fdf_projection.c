/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:10 by anferre           #+#    #+#             */
/*   Updated: 2024/02/27 17:06:19 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_get_middle_coor(t_coor *coor, t_size *size)
{
	t_coor	mincoor;
	t_coor	maxcoor;

	mincoor = ft_get_mincoor(coor, size);
	maxcoor = ft_get_maxcoor(coor, size);
	size->middle_x = (maxcoor.x + mincoor.x) / 2;
	size->middle_y = (maxcoor.y + mincoor.y) / 2;
}

void ft_recenter(t_coor *coor, t_size *size, int width, int height)
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

void	ft_replace(t_coor *coor, t_size *size, int prevmid_x, int prevmid_y)
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

void *ft_resize(t_size *size, t_coor *coor)
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
	scale.dx = (WINDOW_WIDTH - 2 * WINDOW_MARGIN) / deltacoor.dx + size->scale_x;
	scale.dy = (WINDOW_HEIGTH - 2 * WINDOW_MARGIN) / deltacoor.dy + size->scale_y;
	ft_minimum(&scale);
	while (i < ((*size).rows * (*size).cols))
	{
		coor[i].x = round(coor[i].dy * scale.dx);
		coor[i].y = round(coor[i].dx * scale.dy);
		i++;
	}
	return (coor);
}

void	*ft_convert_to_isometric(t_size *size, t_coor *coor)
{
	int		y;
	int		x;
	int		i;
	
	double	arcsin;
	double	beta;

	y = 0;
	arcsin = asin(tan(M_PI / 6));
	beta = M_PI / 4;
	while (y < (*size).rows)
	{
		x = 0;
		while (x < (*size).cols)
		{
			i = x + y * size->cols;
			coor[i].dx = cos(beta) * coor[i].dx + sin(beta) * sin(arcsin) * coor[i].dy + sin(beta) * cos(arcsin) * (coor[i].dz * size->scale_z);
			coor[i].dy = cos(arcsin) * coor[i].dy - sin(arcsin) * (coor[i].dz * size->scale_z);
			x++;
		}
		y++;
	}
	ft_resize(size, coor);
	return (coor);
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
			ft_mlx_pixel_put(data->data_img, data->coor[j + i * data->size->cols].x, data->coor[(j + i * data->size->cols)].y, RED_COLOR);
			if (j < data->size->cols - 1)
				ft_draw_line(data->coor[j + i * data->size->cols], data->coor[(j + i * data->size->cols) + 1], data->data_img, RED_COLOR);
			if (i < data->size->rows - 1)
				ft_draw_line(data->coor[j + i * data->size->cols], data->coor[(j + (i + 1) * data->size->cols)], data->data_img, RED_COLOR);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->data_img->img, 0, 0);
}


void	*ft_project(t_data *data)
{

	ft_convert_to_isometric(data->size, data->coor);
	ft_resize(data->size, data->coor);
	ft_recenter(data->coor, data->size, WINDOW_WIDTH, WINDOW_HEIGTH);
	ft_render(data);
	mlx_loop_hook(data->mlx->mlx, ft_render, data);
	mlx_key_hook(data->mlx->mlx_win, ft_handle_input, data);
	mlx_hook(data->mlx->mlx_win, 17, (1L<<17), ft_handle_notify, data);
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

/*
1st nope
x=cos(β)⋅x+sin(β)⋅sin(α)⋅y−sin(β)⋅cos(α)⋅z
y=cos(α)⋅y+sin(α)⋅z

2nd nope
x=cos(β)⋅x+sin(β)⋅sin(α)⋅y+sin(β)⋅cos(α)⋅z 
y=−cos(α)⋅y−sin(α)⋅z

3rd maybe
x=−cos(β)⋅x−sin(β)⋅sin(α)⋅y+sin(β)⋅cos(α)⋅z
y=−cos(α)⋅y−sin(α)⋅z

4th nope
x=−cos(β)⋅x−sin(β)⋅sin(α)⋅y−sin(β)⋅cos(α)⋅z
y=cos(α)⋅y+sin(α)⋅z

5th nope
x=cos(β)⋅x−sin(β)⋅sin(α)⋅y+sin(β)⋅cos(α)⋅z
y=−cos(α)⋅y−sin(α)⋅z

6th nope
x=−cos(β)⋅x+sin(β)⋅sin(α)⋅y−sin(β)⋅cos(α)⋅z
y=cos(α)⋅y+sin(α)⋅z

7th nope
x=−cos(β)⋅x+sin(β)⋅sin(α)⋅y+sin(β)⋅cos(α)⋅z
y=cos(α)⋅y+sin(α)⋅z

8th nope
x=cos(β)⋅x−sin(β)⋅sin(α)⋅y−sin(β)⋅cos(α)⋅z
y=−cos(α)⋅y−sin(α)⋅z
*/