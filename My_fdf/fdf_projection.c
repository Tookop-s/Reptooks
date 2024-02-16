/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:10 by anferre           #+#    #+#             */
/*   Updated: 2024/02/16 17:19:37 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	*ft_convert_to_isometric(int **array3d, t_size *size, t_coor *coor)
{
	int		i;
	int		j;
	double t;
	double r;

	i = 0;
	j = 0;
	while (i < (*size).rows * (*size).cols)
	{
		t = array3d[i][j];
		t = (j - array3d[i][j]) / sqrt(2);
		r = (j + 2 * i + array3d[i][j]) / sqrt(6);
		coor[j + i * (*size).cols].x = t;
		coor[j + i * (*size).cols].y = r;
		i++;
	}
	return (coor);
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
	t_data	*img;

	coor = ft_new_coor(size);
	coor = ft_convert_to_isometric(array, size, coor);
	ft_print_coor(coor, size);
	ft_free_array(array, size->rows);
	mlx = ft_initialize_window(title);
	if (!mlx)
		return (ft_free_coor(coor), NULL);
	img = ft_initialize_image(mlx);
	if (!img)
		return (ft_free_coor(coor), NULL);
	ft_init_background(img, WHITE_COLOR);
	// ft_print_map(coor, size, mlx, img);
	// ft_free_coor(coor, size);
	// mlx_keyhook(vars.win, 2, (1L<<0), ft_close, &vars);
	// mlx_hook(vars.win, 17, (1L<<2), ft_close, &vars);
	// mlx_loop(mlx->mlx);
	return (0);
}


