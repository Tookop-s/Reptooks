/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:40:09 by anferre           #+#    #+#             */
/*   Updated: 2024/02/29 17:38:00 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <errno.h>

# define RED_COLOR 0xFF0000
# define GREEN_COLOR 0x00FF00
# define BLUE_COLOR 0x0000FF
# define WHITE_COLOR 0xFFFFFF
# define BLACK_COLOR 0x000000


# define WIN_HEIGTH 1080
# define WIN_WIDTH 1920
# define WIN_MARGIN 100


typedef struct s_data_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_data_img;
//bpp = bit per pixel & ll = line lenght

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
}				t_mlx;

typedef struct s_coor
{
	int		x;
	int		y;
	double	dx;
	double	dy;
	double	dz;
	double	ix;
	double	iy;
	double	iz;
	int		clr;
}				t_coor;

typedef struct s_size
{
	int	rows;
	int	cols;
	double	x;
	double	y;
	double	z;
	int		middle_x;
	int		middle_y;
	double	scale_f;
	double	scale_z;
}				t_size;

typedef struct s_data
{
	t_data_img	*data_img;
	t_mlx		*mlx;
	t_coor		*coor;
	t_size		*size;
}				t_data;

		/*Parsing*/
void	*ft_fill_array(t_coor *coor, int fd, int rows, int cols);
void	*ft_parsing(char **argv, t_data *data);

		/*data_processing*/
void	ft_recenter(t_coor *coor, t_size *size, int width, int height);
void	ft_reposition(t_coor *coor, t_size *size, int prevmid_x, int prevmid_y);
void	*ft_resize_3d(t_size *size, t_coor *coor);
void	*ft_resize_2d(t_size *size, t_coor *coor);
void	*ft_convert_to_isometric(t_size *size, t_coor *coor);

		/*Utils_data_processing*/
t_coor	ft_get_mincoor(t_coor *coor, t_size *size);
t_coor	ft_get_maxcoor(t_coor *coor, t_size *size);
void	ft_get_middle_coor(t_coor *coor, t_size *size);
void	ft_minimum(t_coor *comp);

		/*Color*/
int		ft_color(t_data *data, int i);
int		ft_lcolor(t_data *data, int i, int ni);
void	ft_max_min_z(t_data *data, int *max , int *min);

		/*rendering*/
int		ft_render(t_data *data);
void	ft_render_background(t_data_img *data, int color);
void	ft_print_map(t_data *data);
void 	ft_draw(t_coor start, t_coor end, t_data_img *data_img, int color);

		/*mlx*/
void	*ft_project(t_data *data);
t_mlx	*ft_initialize_window(char *title);
void	*ft_initialize_image(t_data_img *data_img, t_mlx *mlx);
void	ft_mlx_pixel_put(t_data_img *data, int x, int y, int color);

		/*struct*/
int		ft_get_size(int	fd, t_size *size);
int		ft_countcols(char *str);
void	*ft_init_data(char **argv);
void	*ft_init_size(void);
void	*ft_init_coor(t_size *size);

void	ft_free_split(char **str);
void	ft_free_struct(t_data *data);
void	ft_free_coor(t_coor *coor);

		/*interactions*/
int		ft_handle_notify(t_data	*data);
int		ft_check_keysym(int keysym);
int		ft_handle_input(int keysym, t_data *data);

int		ft_rotate(t_data *data, int	keysym);
int		ft_translate(t_data *data, int keysym);
int		ft_zoom(t_data *data, int keysym);
int		ft_scale(t_data *data, int keysym);
void	ft_rotate_render(t_data *data);

#endif