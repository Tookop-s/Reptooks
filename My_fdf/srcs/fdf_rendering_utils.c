/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:31:59 by anferre           #+#    #+#             */
/*   Updated: 2024/03/05 16:32:12 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_max_min_z(t_data *data, int *max, int *min)
{
	int		i;

	i = 0;
	*max = data->coor[i].iz;
	*min = data->coor[i].iz;
	while (i < data->size->cols * data->size->rows)
	{
		if (*max < data->coor[i].iz)
			*max = round(data->coor[i].iz);
		if (*min > data->coor[i].iz)
			*min = round(data->coor[i].iz);
		i++;
	}
}

void	ft_print_points(t_data *data, int min, int max)
{
	int	i;

	i = 0;
	while (i < data->size->cols * data->size->rows)
	{
		if (data->coor[i].iz == min)
			ft_mpp(data->data_img, data->coor[i].x, \
			data->coor[i].y, BLUE_COLOR);
		else if (data->coor[i].iz == max)
			ft_mpp(data->data_img, data->coor[i].x, \
			data->coor[i].y, WHITE_COLOR);
		else
			ft_mpp(data->data_img, data->coor[i].x, \
			data->coor[i].y, GREEN_COLOR);
		i++;
	}
}

void	ft_draw_v(t_coor *in, t_coor start, t_coor end)
{
	if (start.x < end.x)
		in->x = 1;
	else
		in->x = -1;
	if (start.y < end.y)
		in->y = 1;
	else
		in->y = -1;
}
