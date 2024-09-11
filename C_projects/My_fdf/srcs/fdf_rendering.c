/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:39:14 by anferre           #+#    #+#             */
/*   Updated: 2024/03/05 17:06:52 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_render(t_data *data)
{
	if (data->mlx->mlx_win)
	{
		ft_render_background(data->data_img, BLACK_COLOR);
		ft_print_map(data, data->size->cols);
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
			ft_mpp(data, j, i, color);
			j++;
		}
		i++;
	}
}

void	ft_print_map(t_data *data, int cols)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	ft_max_min_z(data, &data->size->max_z, &data->size->min_z);
	ft_print_points(data, data->size->min_z, data->size->max_z);
	while (++x < data->size->rows)
	{
		y = -1;
		while (++y < data->size->cols)
		{
			i = y + x * cols;
			if (x < data->size->rows - 1)
				ft_print_color(data, data->coor[i], data->coor[(y + (x + 1) \
				* data->size->cols)]);
			if (y < data->size->cols - 1)
				ft_print_color(data, data->coor[i], data->coor[(y + x \
				* data->size->cols + 1)]);
		}
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, \
	data->data_img->img, 0, 0);
}

/*efficently draw pixel based on int 
If err2 is greater than -diff.y, it means the error is greater along the x-axis,
 so the error is reduced by diff.y, and the x-coordinate is incremented.
If err2 is less than diff.x, it means the error is greater along the y-axis, so
 the error is increased by diff.x, and the y-coordinate is incremented.
*/
static void	ft_bresenham(t_coor diff, t_coor start, t_coor end, t_data *data)
{
	int		err;
	int		err2;
	t_coor	temp;
	t_coor	in;

	err = diff.x - diff.y;
	temp = start;
	ft_draw_v(&in, start, end);
	while (start.x != end.x || start.y != end.y)
	{
		if (temp.clr == GREEN_COLOR)
			start.clr = ft_grad(start, temp, end, data);
		ft_mpp(data->data_img, start.x, start.y, start.clr);
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

void	ft_draw(t_coor start, t_coor end, t_data *data)
{
	t_coor	diff;

	if (start.x == end.x && start.y == end.y)
		return ;
	diff.x = abs(end.x - start.x);
	diff.y = abs(end.y - start.y);
	ft_bresenham(diff, start, end, data);
}
