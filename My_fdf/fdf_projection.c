/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:10 by anferre           #+#    #+#             */
/*   Updated: 2024/02/22 17:36:16 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void ft_round_double_in_x(t_coor *coor, double t, int index)
{
	if (t > 0)
	{
		if (10 - (t * 10) <= 5)
			coor[index].x = (int)ceil(t);
		else
			coor[index].x = (int)(t);
	}
	else
	{
		if (10 - (t * 10) >= 15)
			coor[index].x = (int)floor(t);
		else
			coor[index].x = (int)(t);
	}
}

static void ft_round_double_in_y(t_coor *coor, double r, int index)
{
	if (r > 0)
	{
		if (10 - (r * 10) <= 5)
			coor[index].y = (int)ceil(r);
		else
			coor[index].y = (int)(r);
	}
	else
	{
		if (10 - (r * 10) >= 15)
			coor[index].y = (int)floor(r);
		else
			coor[index].y = (int)(r);
	}
}

static void	ft_rescale(t_coor *coor, t_size *size, double *dscale,  t_coor *delta)
{
	t_coor mincoor;
	t_coor maxcoor;
	t_coor	middlecoor;
	t_coor scale;

	mincoor = ft_get_mincoor(coor, size);
	maxcoor = ft_get_maxcoor(coor, size);
	middlecoor.x = maxcoor.x - mincoor.x;
	middlecoor.y = maxcoor.y - mincoor.y;
	scale.x = (WINDOW_WIDTH - 2 * (WINDOW_MARGIN + 50)) / middlecoor.x;
	scale.y = (WINDOW_HEIGTH - 2 * (WINDOW_MARGIN + 50)) / middlecoor.y;
	ft_minimum(scale, dscale);
	middlecoor.x = (maxcoor.x + mincoor.x) / 2;
	middlecoor.y = (maxcoor.y + mincoor.y) / 2;
	delta->x = (WINDOW_WIDTH - 2 * WINDOW_MARGIN) / 2 - middlecoor.x * (*dscale);
	delta->y = (WINDOW_HEIGTH - 2 * WINDOW_MARGIN) / 2 - middlecoor.y * (*dscale);

}


static void *ft_resize(t_size *size, t_coor	*coor)
{
	int	i;
	double dscale;
	t_coor delta;

	i = 0;
	dscale = 0;
	ft_rescale(coor, size, &dscale, &delta);
	while (i < ((*size).rows * (*size).cols))
	{
		ft_round_double_in_y(coor, coor[i].y * dscale + delta.y, i);
		ft_round_double_in_x(coor, coor[i].x * dscale + delta.x, i);
		i++;
	}
	return (coor);
}

static void	*ft_convert_to_isometric(int **array3d, t_size *size, t_coor *coor)
{
	int		i;
	int		j;
	double	t;
	double	u;

	i = 0;
	size->a = asin(tan(M_PI / 6));
	size->b =  M_PI / 4;
	while (i < (*size).rows)
	{
		j = 0;
		while (j < (*size).cols)
		{
			t = cos(size->b) * j + sin(size->b) * sin(size->a) * i - sin(size->b) * cos(size->a) * array3d[i][j];
			u = cos(size->a) * i + sin(size->a) * array3d[i][j];
			coor[j + i * (*size).cols].x = t;
			coor[j + i * (*size).cols].y = u;
			j++;
		}
		i++;
	}
	coor = ft_resize(size, coor);
	return ( coor);
}

//view asin(tan(M_PI / 6))
// t = cos(b) * j - sin(b) * sin(a) * i + sin(b) * cos(a) * array3d[i][j];
// u = cos(a) * i - sin(a) * array3d[i][j];

// almost
// t = cos(b) * j + sin(b) * sin(a) * i + sin(b) * cos(a) * array3d[i][j];
// u = cos(a) * i - sin(a) * array3d[i][j];

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


// static void ft_draw_line(t_coor start, t_coor end, t_data_img *img, int color) 
// {
// 	int x;
//     double slope;

// 	x = start.x;
// 	slope = (end.y - start.y) / (end.x - start.x);
//     while (x <= end.x)
// 	{
// 		int y = start.y + slope * (x - start.x);
// 		ft_mlx_pixel_put(img, x, y, color);
// 		x++;
// 	}
// }

static void	ft_print_map(t_data *data)
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



int	ft_handle_input(int keysym, t_data *data)
{
	double rx;
	// double translation;
	
	rx = 0.1;
	// translation = 0.1;
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	if (keysym == XK_Right)
		{
			// data->size->a += rx;
			mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
		}
	// if (keysym == XK_Left)
	// 	{
	// 		data->size->a -= rx;
	// 	}
	return (0);
}

int	ft_handle_notify(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	return(0);
}

void	ft_data_mutation(t_data *data)
{
	ft_convert_to_isometric(data->array3d, data->size, data->coor);
}

void	ft_render(t_data *data)
{
	
	ft_render_background(data->data_img, BLACK_COLOR);
	ft_print_map(data);
}

void	*ft_project(t_data *data, char *title)
{

	ft_data_mutation(data);
	mlx_loop_hook(data->mlx->mlx_win, &ft_render, data);
	mlx_key_hook(data->mlx->mlx_win, ft_handle_input, data);
	// mlx_hook(mlx->mlx_win, 2, (1L<<0), , );
	mlx_hook(data->mlx->mlx_win, 17, (1L<<17), &ft_handle_notify, data->mlx);
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
