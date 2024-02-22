/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:10 by anferre           #+#    #+#             */
/*   Updated: 2024/02/22 11:59:08 by anferre          ###   ########.fr       */
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

static void	ft_rescale(t_dcoor *dcoor, t_size *size, double *dscale,  t_dcoor *delta)
{
	t_dcoor mincoor;
	t_dcoor maxcoor;
	t_dcoor	middlecoor;
	t_dcoor scale;

	mincoor = ft_get_mincoor(dcoor, size);
	maxcoor = ft_get_maxcoor(dcoor, size);
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


static void *ft_resize(t_dcoor *dcoor, t_size *size, t_coor	*coor)
{
	int	i;
	double dscale;
	t_dcoor delta;

	i = 0;
	dscale = 0;
	ft_rescale(dcoor, size, &dscale, &delta);
	while (i < ((*size).rows * (*size).cols))
	{
		ft_round_double_in_y(coor, dcoor[i].y * dscale + delta.y, i);
		ft_round_double_in_x(coor, dcoor[i].x * dscale + delta.x, i);
		i++;
	}
	return (coor);
}

static void	*ft_convert_to_isometric(int **array3d, t_size *size, t_dcoor *dcoor, t_coor *coor)
{
	int		i;
	int		j;
	double	a;
	double	b;
	double	t;
	double	u;

	i = 0;
	a =  asin(tan(M_PI / 6));
	b =  M_PI / 4;
	while (i < (*size).rows)
	{
		j = 0;
		while (j < (*size).cols)
		{
			t = cos(b) * j + sin(b) * sin(a) * i - sin(b) * cos(a) * array3d[i][j];
			u = cos(a) * i + sin(a) * array3d[i][j];
			dcoor[j + i * (*size).cols].x = t;
			dcoor[j + i * (*size).cols].y = u;
			j++;
		}
		i++;
	}
	coor = ft_resize(dcoor, size, coor);
	return (ft_free_dcoor(dcoor), coor);
}
//t = cos(b) * j + sin(b) * sin(a) * i - sin(b) * cos(a) * array3d[i][j]; one view

// static void ft_draw_line(t_coor start, t_coor end, t_data *data_img, int color) 
// {
// 	t_coor	diff;
// 	t_coor	in;
// 	int		i;
// 	int		step;

// 	if (start.x == end.x && start.y == end.y)
// 		return ;
// 	diff.x = end.x - start.x;
// 	diff.y = end.y - start.y;
// 	if (diff.x >= diff.y)
// 		step = diff.x;
// 	else
// 		step = diff.y;
// 	in.x = diff.x / step;
// 	in.y = diff.y / step;
// 	i = 0;
// 	while (i < step)
// 	{
// 		ft_mlx_pixel_put(data_img, start.x, start.y, color);
// 		start.x += in.x;
// 		start.y += in.y;
// 		i++;
// 	}
// }

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

static void	ft_print_map(t_coor *coor, t_size *size, t_mlx *mlx) //not working 
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
			// if (j < (*size).cols - 1)
			// 	ft_draw_line(coor[(j + i * (*size).cols)], coor[(j + i * (*size).cols) + 1], mlx->data_img, WHITE_COLOR);
			// if (i < (*size).rows - 1)
			// 	ft_draw_line(coor[(j + i * (*size).cols)], coor[(j + (i + 1) * (*size).cols)], mlx->data_img, WHITE_COLOR);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->data_img->img, 0, 0);
}

void	*ft_project(int **array, t_size *size, char *title)
{
	t_dcoor	*dcoor;
	t_coor	*coor;
	t_mlx	*mlx;

	dcoor = ft_new_dcoor(size);
	coor = ft_new_coor(size);
	coor = ft_convert_to_isometric(array, size, dcoor, coor);
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

// rotate clock wise 
// tempx = *x
// *x = cos(angle) * tempX - sin(angle) * *z;
// *z = sin(angle) * tempX + cos(angle) * *z;
//rotate counter clock wise 
// *x = cos(angle) * tempX + sin(angle) * *z;
// *z = -sin(angle) * tempX + cos(angle) * *z;
