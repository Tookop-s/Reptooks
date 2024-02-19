/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:10 by anferre           #+#    #+#             */
/*   Updated: 2024/02/19 18:06:17 by anferre          ###   ########.fr       */
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

static void ft_get_positive_coor(t_coor *coor, t_size *size, t_coor mincoor)
{
	int	i;

	i = 0;
	if (mincoor.x < 0)
		mincoor.x = abs(mincoor.x);
	else
		mincoor.x = 0;
	if (mincoor.y < 0)
		mincoor.y = abs(mincoor.y);
	else
		mincoor.y = 0;
	i = 0;
	while (i < ((*size).rows * (*size).cols))
	{
		coor[i].x += mincoor.x;
		coor[i].y += mincoor.y;
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
	middlecoor = ft_new_coor(&(t_size){1, 0});
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
	ft_get_positive_coor(coor, size, mincoor);
	(*middlecoor).x = maxcoor.x - mincoor.x;
	(*middlecoor).y = maxcoor.y - mincoor.y;
	return (middlecoor);
}

// static void ft_draw_line(t_coor start, t_coor end, t_data *img, int color) 
// {
// 	int x;
//     float slope;

// 	x = start.x;
// 	slope = (float)(end.y - start.y) / (end.x - start.x);
//     while (x <= end.x)
// 	{
// 		int y = start.y + slope * (x - start.x);
// 		ft_mlx_pixel_put(img, x, y, color);
// 		x++;
// 	}
// }

// static void	ft_print_map(t_coor *coor, t_size *size, t_mlx *mlx, t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < (*size).rows)
// 	{
// 		j = 0;
// 		while (j < (*size).cols)
// 		{
// 			ft_mlx_pixel_put(data, coor[i].x, coor[i].y, RED_COLOR);
// 			// if (j < (*size).cols - 1)
// 			// 	ft_draw_line(coor[i], coor[i], img, color);
// 			// if (i < (*size).rows - 1)
// 			// 	ft_draw_line(coor[i], coor[i + 1], img, color);
// 			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, data->img, 0, 0);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	*ft_project(int **array, t_size *size, char *title)
{
	t_coor	*coor;
	t_mlx	*mlx;
	t_coor	*middle;

	coor = ft_new_coor(size);
	ft_convert_to_isometric(array, size, coor);
	ft_free_array(array, size->rows);
	middle = ft_resize(coor, size);
	if (middle)
	mlx = ft_initialize_window(title);
	if (!mlx)
		return (NULL);
	mlx->data_img = ft_initialize_image(mlx);
	if (!mlx->data_img->img)
		return (NULL);
	ft_init_background(mlx->data_img->img, WHITE_COLOR);
	// ft_print_map(coor, size, mlx, img);
	// ft_free_coor(coor, size);
	// mlx_keyhook(vars.win, 2, (1L<<0), ft_close, &vars);
	// mlx_hook(vars.win, 17, (1L<<2), ft_close, &vars);
	// mlx_loop(mlx->mlx);
	return (0);
}


