/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:27:13 by anferre           #+#    #+#             */
/*   Updated: 2024/03/05 17:07:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*get the position among the line between start x & y and end x & y,
then transform it to a ratio, and apply it to max and min z */
t_coor	ft_grad_data(t_coor start, t_coor end, t_coor curr, t_data *data)
{
	t_coor	t;

	if ((end.x - start.x) != 0)
		t.dx = ((double)curr.x - start.x) / (end.x - start.x);
	else
		t.dx = 0;
	if ((end.y - start.y) != 0)
		t.dy = ((double)curr.y - start.y) / (end.y - start.y);
	else
		t.dy = 0;
	if ((data->size->max_z - data->size->min_z) != 0)
		t.dz = (start.iz - data->size->min_z) / (data->size->max_z - \
		data->size->min_z);
	else
		t.dz = 0;
	return (t);
}

/*define the color depending on the ratio / position */
int	ft_grad(t_coor curr, t_coor start, t_coor end, t_data *data)
{
	t_coor	t;
	double	p;

	t = ft_grad_data(start, end, curr, data);
	p = ((t.dx + t.dy) / 2.0) * ((end.iz - start.iz) / (data->size->max_z \
	- data->size->min_z)) + t.dz;
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
	return (GREEN_COLOR);
}

/*first sort of color*/
void	ft_print_color(t_data *data, t_coor start, t_coor end)
{
	if (start.iz == end.iz && start.iz == data->size->min_z)
	{
		start.clr = BLUE_COLOR;
		ft_draw(start, end, data);
	}
	else if (start.iz == end.iz && start.iz == data->size->max_z)
	{
		start.clr = WHITE_COLOR;
		ft_draw(start, end, data);
	}
	else
	{
		start.clr = GREEN_COLOR;
		ft_draw(start, end, data);
	}
}	

int	ft_check_color(int color)
{
	if (color == GREEN_COLOR || color == GREEN1_COLOR)
		return (1);
	else if (color == GREEN2_COLOR || color == GREEN3_COLOR)
		return (1);
	else if (color == GREEN4_COLOR || color == GREEN5_COLOR)
		return (1);
	else
		return (0);
}
