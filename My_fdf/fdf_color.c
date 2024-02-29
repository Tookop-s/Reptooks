/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:31:59 by anferre           #+#    #+#             */
/*   Updated: 2024/02/29 17:33:17 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_max_min_z(t_data *data, int *max, int *min)
{
	int		i;

	i = 0;
	*max = data->coor[i].iz;
	while (i < data->size->cols * data->size->rows)
	{
		if (*max < data->coor[i].iz)
			*max = round(data->coor[i].iz);
		if (*min > data->coor[i].iz)
			*min = round(data->coor[i].iz);
		i++;
	}
}

int	ft_color(t_data *data, int i)
{
	int	color;
	int	max;
	int	min;

	ft_max_min_z(data, &max, &min);
	if (data->coor[i].iz == 0)
		color = BLUE_COLOR;
	else if (data->coor[i].iz == max)
		color = WHITE_COLOR;
	else
		color = GREEN_COLOR;
	return (color);
}

int	ft_lcolor(t_data *data, int i, int ni)
{
	int	max;
	int	min;
	int	color;

	ft_max_min_z(data, &max, &min);
	if (round(data->coor[i].iz) == round(data->coor[ni].iz) \
	&& round(data->coor[i].iz) == max)
		color = WHITE_COLOR;
	else
		color = BLUE_COLOR;
	return (color);
}
