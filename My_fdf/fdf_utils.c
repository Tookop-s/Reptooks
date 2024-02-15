/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:21:53 by anferre           #+#    #+#             */
/*   Updated: 2024/02/15 17:10:50 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_initialize_window(char *title)
{
	t_mlx *mlx;
	
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	(*mlx).mlx = mlx_init();
	(*mlx).mlx_win = mlx_new_window((*mlx).mlx, 1920, 1080, title);
	return (mlx);
}

void	*ft_initialize_image(t_mlx *mlx)
{
	t_data	*img;

	img = malloc(sizeof(t_data));
	if (!img)
		return (NULL);
	
	(*img).img = mlx_new_image(mlx->mlx, 1920, 1080);
	(*img).addr = mlx_get_data_addr((*img).img, &(*img).bpp, &(*img).ll, &(*img).endian);
	return (img);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
