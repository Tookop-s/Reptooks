/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:21:53 by anferre           #+#    #+#             */
/*   Updated: 2024/02/22 12:07:00 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	*ft_initialize_window(char *title)
{
	t_mlx *mlx;
	
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	(*mlx).mlx = mlx_init();
	(*mlx).mlx_win = mlx_new_window((*mlx).mlx, WINDOW_WIDTH, WINDOW_HEIGTH, title);
	return (mlx);
}

void	*ft_initialize_image(t_mlx *mlx)
{
	mlx->data_img = malloc(sizeof(t_data));
	if (!mlx->data_img)
		return (NULL);
	(*mlx->data_img).img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGTH);
	(*mlx->data_img).addr = mlx_get_data_addr((*mlx->data_img).img, &(*mlx->data_img).bpp, \
	&(*mlx->data_img).ll, &(*mlx->data_img).endian);
	return (mlx->data_img);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x > WINDOW_WIDTH || y > WINDOW_HEIGTH)
		return ;
	pixel = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(int *)pixel = color;
}

void	ft_init_background(t_data *data, int color)
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
