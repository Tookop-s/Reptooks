/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:21:53 by anferre           #+#    #+#             */
/*   Updated: 2024/02/29 17:06:53 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	*ft_project(t_data *data)
{
	ft_convert_to_isometric(data->size, data->coor);
	ft_recenter(data->coor, data->size, WIN_WIDTH, WIN_HEIGTH);
	mlx_loop_hook(data->mlx->mlx, ft_render, data);
	mlx_key_hook(data->mlx->mlx_win, ft_handle_input, data);
	mlx_hook(data->mlx->mlx_win, 17, (1L<<17), ft_handle_notify, data);
	mlx_loop(data->mlx->mlx);
	return (0);
}

t_mlx	*ft_initialize_window(char *title)
{
	t_mlx *mlx;
	
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	(*mlx).mlx = mlx_init();
	(*mlx).mlx_win = mlx_new_window((*mlx).mlx, WIN_WIDTH, WIN_HEIGTH, title);
	return (mlx);
}

void	*ft_initialize_image(t_data_img *data_img, t_mlx *mlx)
{
	data_img = malloc(sizeof(t_data_img));
	if (!data_img)
		return (NULL);
	data_img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGTH);
	data_img->addr = mlx_get_data_addr(data_img->img, &data_img->bpp, &data_img->ll, &data_img->endian);
	return (data_img);
}

void	ft_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*pixel;

	if (x > WIN_WIDTH || y > WIN_HEIGTH || x < 0 || y < 0)
		return ;
	pixel = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(int *)pixel = color;
}

