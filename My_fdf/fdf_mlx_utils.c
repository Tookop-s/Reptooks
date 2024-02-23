/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:21:53 by anferre           #+#    #+#             */
/*   Updated: 2024/02/23 14:48:20 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_mlx	*ft_initialize_window(char *title)
{
	t_mlx *mlx;
	
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	(*mlx).mlx = mlx_init();
	(*mlx).mlx_win = mlx_new_window((*mlx).mlx, WINDOW_WIDTH, WINDOW_HEIGTH, title);
	return (mlx);
}

void	*ft_initialize_image(t_data_img *data_img, t_mlx *mlx)
{
	data_img = malloc(sizeof(t_data_img));
	if (!data_img)
		return (NULL);
	data_img->img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGTH);
	data_img->addr = mlx_get_data_addr(data_img->img, &data_img->bpp, &data_img->ll, &data_img->endian);
	return (data_img);
}

void	ft_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*pixel;

	if (x > WINDOW_WIDTH || y > WINDOW_HEIGTH || x < 0 || y < 0)
		return ;
	pixel = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(int *)pixel = color;
}

void	ft_render_background(t_data_img *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGTH)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			ft_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}
