/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:48:01 by anferre           #+#    #+#             */
/*   Updated: 2024/02/29 16:48:47 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_free_split(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free (str);
}

void	ft_free_struct(t_data *data)
{
	if (data)
	{
		if (data->mlx->mlx && data->data_img->img)
			mlx_destroy_image(data->mlx->mlx, data->data_img->img);
		data->mlx->mlx_win = NULL;
		if (data->coor)
			ft_free_coor(data->coor);
		data->coor = NULL;
		if (data->data_img)
			free(data->data_img);
		data->data_img = NULL;
		if (data->size)
			free(data->size);
		if (data->mlx->mlx)
			mlx_destroy_display(data->mlx->mlx);
		if (data->mlx->mlx)
			free(data->mlx->mlx);
		if (data->mlx)
			free(data->mlx);
		data->mlx = NULL;
		free(data);
	}
}

void	ft_free_coor(t_coor *coor)
{
	if (!coor)
		return ;
	free(coor);
}
