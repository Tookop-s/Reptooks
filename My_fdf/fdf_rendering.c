/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:39:14 by anferre           #+#    #+#             */
/*   Updated: 2024/02/29 16:54:03 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	ft_render(t_data *data)
{
	if (data->mlx->mlx_win)
	{
		ft_render_background(data->data_img, BLACK_COLOR);
		ft_print_map(data);
	}
	return (0);
}

void	ft_render_background(t_data_img *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGTH)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			ft_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}

void	ft_print_map(t_data *data)
{
	int	i;
	int	j;
	int cols;

	i = -1;
	cols = data->size->cols;
	while (++i < data->size->rows)
	{
		j = -1;
		while (++j < data->size->cols)
		{
			ft_mlx_pixel_put(data->data_img, data->coor[j + i * cols].x,\
			 data->coor[(j + i * cols)].y, ft_color(data, j + i * cols));
			if (i < data->size->rows - 1)
				ft_draw(data->coor[j + i * cols], data->coor[(j + (i + 1) *\
				cols)], data->data_img, ft_lcolor(data, j + i * cols, \
				(j + (i + 1) * cols)));
			if (j < cols - 1)
				ft_draw(data->coor[j + i * cols], data->coor[(j + i * cols) \
				+ 1], data->data_img, ft_lcolor(data, j + i * cols, \
				(j + i * cols+ 1)));
		}
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, \
	data->data_img->img, 0, 0);
}

void ft_draw(t_coor start, t_coor end, t_data_img *data_img, int color) 
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
