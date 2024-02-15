/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:10 by anferre           #+#    #+#             */
/*   Updated: 2024/02/15 16:54:47 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	*ft_convert_to_isometric(int **array3d, t_size *size, t_coor **coor)
{
	int		i;
	int		j;

	i = 0;
	while (i < (*size).rows)
	{
		j = 0;
		while (j < (*size).cols)
		{
			coor[i][j].x = (j - array3d[i][j]) / sqrt(2);
			coor[i][j].y = (j + 2 * i + array3d[i][j]) / sqrt(6);
			j++;
		}
		i++;
	}
	return (coor);
}

static void ft_draw_line(t_coor start, t_coor end, t_data *img, int color) 
{
	int x;
    float slope;

	x = start.x;
	slope = (float)(end.y - start.y) / (end.x - start.x);
    while (x <= end.x)
	{
		int y = start.y + slope * (x - start.x);
		ft_mlx_pixel_put(img, x, y, color);
		x++;
	}
}

static void	ft_print_map(t_coor **coor, t_size *size, t_mlx *mlx, t_data *img)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	color =  255;
	while (i < (*size).rows)
	{
		j = 0;
		while (j < (*size).cols)
		{
			ft_mlx_pixel_put(img, coor[i][j].x, coor[i][j].y, color);
			if (j < (*size).cols - 1)
				ft_draw_line(coor[i][j], coor[i][j + 1], img, color);
			if (i < (*size).rows - 1)
				ft_draw_line(coor[i][j], coor[i + 1][j], img, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, 0, 0);
}

void	*ft_project(int **array, t_size *size, char *title)
{
	t_coor	**coor;
	t_mlx	*mlx;
	t_data	*img;

	coor = ft_new_coor(size);
	coor = ft_convert_to_isometric(array, size, coor);
	ft_free_array(array, size->rows);
	mlx = ft_initialize_window(title);
	if (!mlx)
		return (ft_free_coor(coor, size), NULL);
	img = ft_initialize_image(mlx);
	if (!img)
		return (ft_free_coor(coor, size), NULL);
	ft_print_map(coor, size, mlx, img);
	ft_free_coor(coor, size);
	// mlx_hook(vars.win, 2, (1L<<0), ft_close, &vars);
	mlx_loop(mlx->mlx);
	return (0);
}


