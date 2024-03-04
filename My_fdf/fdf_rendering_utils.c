/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:31:59 by anferre           #+#    #+#             */
/*   Updated: 2024/03/04 17:56:50 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

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

/*t_coor mm x = min y = max*/
void	ft_print_color(t_data *data, t_coor start, t_coor end, t_coor mm)
{
	if (start.iz == end.iz && start.iz == mm.x)
		ft_draw(start, end, data->data_img, BLUE_COLOR);
	else if (start.iz == end.iz && start.iz == mm.y)
		ft_draw(start, end, data->data_img, WHITE_COLOR);
	else
		ft_draw(start, end, data->data_img, GREEN_COLOR);
}	


void	ft_draw_v(t_coor *diff, t_coor *in, t_coor start, t_coor end)
{
	diff->x = abs(end.x - start.x);
	diff->y = abs(end.y - start.y);
	if (start.x < end.x)
		in->x = 1;
	else
		in->x = -1;
	if (start.y < end.y)
		in->y = 1;
	else
		in->y = -1;
}

int	ft_grad(int color, t_coor start, t_coor end, t_coor curr)
{
	t_coor	t;
	double	p;

	if (color != GREEN_COLOR)
		return (color);
	if ((end.x - start.x) != 0)
		t.dx = ((double)curr.x - start.x) / (end.x - start.x);
	else
		t.dx = 0;
	if ((end.y - start.y) != 0)
		t.dy = ((double)curr.y - start.y) / (end.y - start.y);
	else
		t.dy = 0;
	p = (t.dx + t.dy) / 2.0;
	if (p >= 0 && p < 0.2)
		return (GREEN1_COLOR);
	if (p >= 0.2 && p < 0.4)
		return (GREEN2_COLOR);
	if (p >= 0.4 && p < 0.6)
		return (GREEN3_COLOR);
	if (p >= 0.6 && p < 0.8)
		return (GREEN4_COLOR);
	if (p >= 0.8 && p <= 0.1)
		return (GREEN5_COLOR);
}