/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_interactions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:56:03 by anferre           #+#    #+#             */
/*   Updated: 2024/02/29 16:56:52 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	ft_handle_notify(t_data	*data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	data->mlx->mlx_win = NULL;
	ft_free_struct(data);
	exit(0);
}

int	ft_check_keysym(int keysym)
{
	if (keysym == XK_Right || keysym == XK_Left || keysym == XK_Up \
		|| keysym == XK_Down || keysym == XK_o || keysym == XK_p \
		|| keysym == XK_KP_Add || keysym == XK_KP_Subtract \
		|| keysym == XK_Page_Up || keysym == XK_Page_Down)
		return (1);
	return (0);
}

int	ft_handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
		data->mlx->mlx_win = NULL;
		ft_free_struct(data);
		exit(0);
	}
	if (ft_check_keysym(keysym))
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
	if (keysym == XK_KP_Down || keysym == XK_KP_Up || keysym == XK_KP_Right \
	|| keysym == XK_KP_Left)
		ft_translate(data, keysym);
	return (0);
}
