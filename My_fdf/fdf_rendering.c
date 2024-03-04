/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:39:14 by anferre           #+#    #+#             */
/*   Updated: 2024/03/04 17:58:46 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

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

/*t_coor mm x = min y = max*/
void	ft_print_map(t_data *data, int cols)
{
	int		x;
	int		y;
	int		i;
	t_coor	mm;

	x = -1;
	ft_max_min_z(data, &mm.y, &mm.x);
	ft_print_points(data, mm.x, mm.y);
	while (++x < data->size->rows)
	{
		y = -1;
		while (++y < data->size->cols)
		{
			i = y + x * cols;
			if (x < data->size->rows - 1)
				ft_print_color(data, data->coor[i], data->coor[(y + (x + 1) \
				* data->size->cols)], mm);
			if (y < data->size->cols - 1)
				ft_print_color(data, data->coor[i], data->coor[(y + x \
				* data->size->cols + 1)], mm);
		}
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, \
	data->data_img->img, 0, 0);
}

void	ft_draw(t_coor start, t_coor end, t_data_img *data_img, int color)
{
	t_coor	diff;
	t_coor	temp;
	t_coor	in;
	int		err;

	if (start.x == end.x && start.y == end.y)
		return ;
	ft_draw_v(&diff, &in, start, end);
	err = diff.x - diff.y;
	temp.x = start.x;
	temp.y = start.y;
	while (start.x != end.x || start.y != end.y)
	{
		ft_mpp(data_img, start.x, start.y, ft_grad(color, temp, end, start));
		if ((2 * err) > -diff.y)
		{
			err -= diff.y;
			start.x += in.x;
		}
		if ((2 * err) < diff.x)
		{
			err += diff.x;
			start.y += in.y;
		}
	}
}

/*The algorithm essentially uses the decision parameter p to determine
 which pixel to choose at each step. If p is negative, the next pixel 
 is to the right; if p is non-negative, the next pixel is diagonally to 
 the right and up. This decision is based on the comparison of p with */