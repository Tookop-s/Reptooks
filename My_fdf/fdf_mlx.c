/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:21:53 by anferre           #+#    #+#             */
/*   Updated: 2024/02/28 14:09:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	ft_render(t_data *data)
{
	if (data->mlx->mlx_win)
	{
		ft_render_background(data->data_img, BLACK_COLOR);
		ft_print_map(data);
	}
	return (0);
}

int	ft_handle_notify(t_data	*data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	data->mlx->mlx_win = NULL;
	ft_free_struct(data);
	exit(0);
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
	if (keysym == XK_Right || keysym == XK_Left || keysym == XK_Up \
	|| keysym == XK_Down || keysym == XK_o || keysym == XK_p)
		ft_rotate(data, keysym);
	if (keysym == XK_KP_Down || keysym == XK_KP_Up || keysym == XK_KP_Right \
	|| keysym == XK_KP_Left)
		ft_translate(data, keysym);
	if (keysym == XK_KP_Add || keysym == XK_KP_Subtract)
		ft_zoom(data, keysym);
	if (keysym == XK_Page_Up || keysym == XK_Page_Down)
		ft_scale(data, keysym);
	return (0);
}
