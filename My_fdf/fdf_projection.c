/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:10 by anferre           #+#    #+#             */
/*   Updated: 2024/02/20 14:49:57 by anferre          ###   ########.fr       */
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

static void	*ft_convert_to_isometric(int **array3d, t_size *size, t_coor *coor)
{
	int		i;
	int		j;
	double	a;
	double	t;
	double	r;

	i = 0;
	a =  ISO_ANGLE * M_PI / 180;
	while (i < (*size).rows)
	{
		j = 0;
		while (j < (*size).cols)
		{
			t = j * cos(a) + i * cos(a + 2) + array3d[i][j] * cos(a - 2);
			r = j * sin(a) + i * sin(a + 2) + array3d[i][j] * sin(a - 2);
			ft_fill_x(coor, t, (j + i * (*size).cols));
			ft_fill_y(coor, r, (j + i * (*size).cols));
			j++;
		}
		i++;
	}
	return (coor);
}

static void	ft_rescale(t_coor *coor, t_size *size, t_coor mincoor, t_coor maxcoor)
{
	t_dcoor	scale;
	double	dscale;
	int		i;
	t_coor	delta;
	t_coor	middlecoor;

	middlecoor.x = maxcoor.x - mincoor.x;
	middlecoor.y = maxcoor.y - mincoor.y;
	scale.x = (WINDOW_WIDTH - 2 * WINDOW_MARGIN) / middlecoor.x;
	scale.y = (WINDOW_HEIGTH - 2 * WINDOW_MARGIN) / middlecoor.y;
	dscale = ft_min(scale);
	delta.x = (WINDOW_WIDTH - 2 * WINDOW_MARGIN) / 2 - (mincoor.x + maxcoor.x) / 2;
	delta.y = (WINDOW_HEIGTH - 2 * WINDOW_MARGIN) / 2 - (mincoor.y + maxcoor.y) / 2;
	while (i < ((*size).rows * (*size).cols))
	{
		coor[i].x = ((int)(coor[i].x - mincoor.x) * dscale + delta.x + WINDOW_MARGIN);
		coor[i].y = ((int)(coor[i].y - mincoor.y) * dscale + delta.y + WINDOW_MARGIN);
		i++;
	}
}

static void *ft_resize(t_coor *coor, t_size *size)
{
	int	i;
	t_coor mincoor;
	t_coor maxcoor;
	t_coor *middlecoor;

	i = -1;
	mincoor.x = 0;
	mincoor.y = 0;
	maxcoor.x = 0;
	maxcoor.y = 0;
	middlecoor = ft_new_coor(&(t_size){0, 1});
	while (++i < ((*size).rows * (*size).cols))
	{
		if (mincoor.x > coor[i].x) 
			mincoor.x = coor[i].x;
		if (mincoor.y > coor[i].y)
			mincoor.y = coor[i].y;
		if (maxcoor.x < coor[i].x)
			maxcoor.x = coor[i].x;
		if (maxcoor.y < coor[i].y)
			maxcoor.y = coor[i].y;
	}
	ft_rescale(coor, size, mincoor, maxcoor);
	return (free(middlecoor), coor);
}

static void ft_draw_line(t_coor start, t_coor end, t_data *data_img, int color) 
{
	t_coor	diff;
	t_coor	in;
	int		i;
	int		step;

	diff.x = abs(end.x - start.x);
	diff.y = abs(end.y - start.y);
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
			ft_mlx_pixel_put(mlx->data_img, coor[(j + i * (*size).cols)].x, coor[(j + i * (*size).cols)].y, RED_COLOR);
			if (j < (*size).cols - 1)
				ft_draw_line(coor[i], coor[i + 1], mlx->data_img->img, GREEN_COLOR);
			// if (i < (*size).rows - 1)
			// 	ft_draw_line(coor[i], coor[i + 1], mlx->data_img->img, GREEN_COLOR);
			j++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->data_img->img, 0, 0);
		i++;
	}
}

void	*ft_project(int **array, t_size *size, char *title)
{
	t_coor	*coor;
	t_mlx	*mlx;
	t_coor	*middle;

	coor = ft_new_coor(size);
	ft_convert_to_isometric(array, size, coor);
	ft_free_array(array, size->rows);
	middle = ft_resize(coor, size);
	ft_print_coor(coor, size);
	if (middle)
	mlx = ft_initialize_window(title);
	if (!mlx)
		return (NULL);
	mlx->data_img = ft_initialize_image(mlx);
	if (!mlx->data_img->img)
		return (NULL);
	ft_init_background(mlx->data_img, WHITE_COLOR);
	ft_print_map(coor, size, mlx);
	// ft_free_coor(coor, size);
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