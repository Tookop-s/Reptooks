/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:10 by anferre           #+#    #+#             */
/*   Updated: 2024/02/21 14:47:00 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void ft_fill_x(t_coor *coor, double t, int index)
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
static void ft_fill_y(t_coor *coor, double r, int index)
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

static void	ft_rescale(t_coor *coor, t_size *size, t_coor mincoor, t_coor maxcoor)
{
	double	dscale;
	int		i;
	t_dcoor	scale;
	t_dcoor	delta;
	t_coor	middlecoor;

	middlecoor.x = maxcoor.x - mincoor.x;
	middlecoor.y = maxcoor.y - mincoor.y;
	scale.x = (WINDOW_WIDTH - 2 * WINDOW_MARGIN) / middlecoor.x;
	scale.y = (WINDOW_HEIGTH - 2 * WINDOW_MARGIN) / middlecoor.y;
	dscale = ft_min(scale) * 0.5;
	middlecoor.x = (maxcoor.x + mincoor.x) / 2;
	middlecoor.y = (maxcoor.y + mincoor.y) / 2;
	delta.x = (WINDOW_WIDTH - 2 * WINDOW_MARGIN) / 2 - middlecoor.x * dscale;
	delta.y = (WINDOW_HEIGTH - 2 * WINDOW_MARGIN) / 2 - middlecoor.y * dscale;
	i = 0;
	while (i < ((*size).rows * (*size).cols) && dscale)
	{
		coor[i].x = (int)(coor[i].x * dscale + delta.x);
		coor[i].y = (int)(coor[i].y * dscale + delta.y);
		i++;
	}
}


static void *ft_resize(t_coor *coor, t_size *size)
{
	int	i;
	t_coor mincoor;
	t_coor maxcoor;

	mincoor = ft_get_mincoor(coor, size);
	maxcoor = ft_get_maxcoor(coor, size);
	ft_rescale(coor, size, mincoor, maxcoor);
	return (coor);
}

static void	*ft_convert_to_isometric(int **array3d, t_size *size, t_coor *coor)
{
	int		i;
	int		j;
	double	a;
	double	b;
	double	t;
	double	r;

	i = 0;
	a =  35.264 * M_PI / 180;
	b = 45 * M_PI / 180;
	while (i < (*size).rows)
	{
		j = 0;
		while (j < (*size).cols)
		{
			t = cos(b) * j + sin(b) * sin(a) * i - sin(b) * cos(a) * array3d[i][j];
			r = cos(a) * i + sin(a) * array3d[i][j];
			ft_fill_x(coor, t, (j + i * (*size).cols));
			ft_fill_y(coor, r, (j + i * (*size).cols));
			j++;
		}
		i++;
	}
	ft_resize(coor, size);
	return (coor);
}


static void ft_draw_line(t_coor start, t_coor end, t_data *data_img, int color) 
{
	t_coor	diff;
	t_coor	in;
	int		i;
	int		step;

	if (start.x == end.x && start.y == end.y)
		return ;
	diff.x = end.x - start.x;
	diff.y = end.y - start.y;
	if (diff.x >= diff.y)
		step = diff.x;
	else
		step = diff.y;
	in.x = diff.x / step;
	in.y = diff.y / step;
	i = 0;
	while (i < step)
	{
		ft_mlx_pixel_put(data_img, start.x, start.y, color);
		start.x = start.x + in.x;
		start.y = start.y + in.y;
		i++;
	}
}


static void	ft_print_map(t_coor *coor, t_size *size, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*size).rows)
	{
		j = 0;
		while (j < (*size).cols)
		{
			ft_mlx_pixel_put(mlx->data_img, coor[(j + i * (*size).cols)].x, coor[(j + i * (*size).cols)].y, WHITE_COLOR);
			if (j < (*size).cols - 1)
				ft_draw_line(coor[(j + i * (*size).cols)], coor[(j + i * (*size).cols) + 1], mlx->data_img, WHITE_COLOR);
			if (i < (*size).rows - 1)
				ft_draw_line(coor[(j + i * (*size).cols)], coor[(j + i * (*size).cols) + 1], mlx->data_img, WHITE_COLOR);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->data_img->img, 0, 0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->data_img->img, 0, 0);
}

void	*ft_project(int **array, t_size *size, char *title)
{
	t_coor	*coor;
	t_mlx	*mlx;

	coor = ft_new_coor(size);
	ft_convert_to_isometric(array, size, coor);
	mlx = ft_initialize_window(title);
	if (!mlx)
		return (NULL);
	mlx->data_img = ft_initialize_image(mlx);
	if (!mlx->data_img->img)
		return (NULL);
	ft_init_background(mlx->data_img, BLACK_COLOR);
	ft_print_map(coor, size, mlx);
	// mlx_keyhook(vars.win, 2, (1L<<0), ft_close, &vars);
	// mlx_hook(vars.win, 17, (1L<<2), ft_close, &vars);
	// mlx_loop(mlx->mlx);
	return (0);
}


// static void ft_draw_line(t_coor start, t_coor end, t_data *img, int color) 
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