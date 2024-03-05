/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_interactions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:56:03 by anferre           #+#    #+#             */
/*   Updated: 2024/03/05 17:02:25 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_handle_notify(t_data	*data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	data->mlx->mlx_win = NULL;
	ft_free_struct(data);
	exit(0);
}

static int	ft_check_keysym(int keysym)
{
	if (keysym == XK_Right || keysym == XK_Left || keysym == XK_Up \
		|| keysym == XK_Down || keysym == XK_o || keysym == XK_p \
		|| keysym == XK_KP_Add || keysym == XK_KP_Subtract \
		|| keysym == XK_Page_Up || keysym == XK_Page_Down)
		return (1);
	return (0);
}

/*reposition just like the beginning*/
void	ft_first_pos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size->rows * data->size->cols)
	{
		data->coor[i].dx = data->coor[i].ix;
		data->coor[i].dy = data->coor[i].iy;
		data->coor[i].dz = data->coor[i].iz;
		i++;
	}
	data->size->x = 0;
	data->size->y = 0;
	data->size->z = 0;
	data->size->scale_f = 0;
	data->size->scale_z = 1;
	ft_convert_to_isometric(data->size, data->coor);
	ft_recenter(data->coor, data->size, WIN_WIDTH, WIN_HEIGTH);
}

int	ft_handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_kill(data);
	else if (keysym == XK_Home)
		ft_first_pos(data);
	else if (ft_check_keysym(keysym))
	{
		if (keysym == XK_Right || keysym == XK_Left || keysym == XK_Up \
		|| keysym == XK_Down || keysym == XK_o || keysym == XK_p)
			ft_rotate(data, keysym);
		if (keysym == XK_KP_Add || keysym == XK_KP_Subtract)
			ft_zoom(data, keysym);
		if (keysym == XK_Page_Up || keysym == XK_Page_Down)
			ft_scale(data, keysym);
		ft_get_middle_coor(data->coor, data->size);
		ft_convert_to_isometric(data->size, data->coor);
		ft_reposition(data->coor, data->size, data->size->middle_x, \
		data->size->middle_y);
	}
	else if (keysym == XK_KP_Down || keysym == XK_KP_Up || \
	keysym == XK_KP_Right || keysym == XK_KP_Left)
		ft_translate(data, keysym);
	return (0);
}

void	*ft_project(t_data *data)
{
	ft_convert_to_isometric(data->size, data->coor);
	ft_recenter(data->coor, data->size, WIN_WIDTH, WIN_HEIGTH);
	mlx_loop_hook(data->mlx->mlx, ft_render, data);
	mlx_key_hook(data->mlx->mlx_win, ft_handle_input, data);
	mlx_hook(data->mlx->mlx_win, 17, (1L << 17), ft_handle_notify, data);
	mlx_loop(data->mlx->mlx);
	return (0);
}
