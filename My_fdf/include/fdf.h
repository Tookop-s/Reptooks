/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:40:09 by anferre           #+#    #+#             */
/*   Updated: 2024/02/22 17:28:12 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
#include <X11/keysym.h>

# define RED_COLOR 0xFF0000
# define GREEN_COLOR 0x00FF00
# define BLUE_COLOR 0x0000FF
# define WHITE_COLOR 0xFFFFFF
# define BLACK_COLOR 0x000000


# define WINDOW_HEIGTH 500
# define WINDOW_WIDTH 1000
# define WINDOW_MARGIN 100


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
	int	x;
	int	y;
	double	dx;
	double	dy;
}				t_coor;

typedef struct s_size
{
	int	rows;
	int	cols;
	double	a;
	double	b;
}				t_size;

typedef struct s_data
{
	int			**array3d;
	t_data_img	*data_img;
	t_mlx		*mlx;
	t_coor		*coor;
	t_size		*size;
}				t_data;

		/*Parsing*/
void	*ft_parsing(char **argv, t_size *size, int **array3d);
		/*Utils*/
void	*ft_new_array(t_size *size);
void	ft_free_array(int **array, int rows);
void	*ft_init_size();
void	ft_free_split(char **str);
int		ft_get_size(int	fd, t_size *size);

		/*Projection*/
void	*ft_project(t_data *data, char *title);
		/*Utils*/
void	ft_free_struct(t_data *data);
void	*ft_init_coor(t_size *size);
void	ft_free_coor(t_coor *coor);
void	ft_free_coor(t_coor *coor);
t_coor	ft_get_maxcoor(t_coor *coor, t_size *size);
t_coor	ft_get_mincoor(t_coor *coor, t_size *size);
void	ft_minimum(t_coor comp, double *dscale);

		/*mlx*/
t_mlx	*ft_initialize_window(char *title);
void	*ft_initialize_image(t_data_img *data_img, t_mlx *mlx);
void	ft_mlx_pixel_put(t_data_img *data, int x, int y, int color);
void	ft_render_background(t_data_img *data, int color);

void	ft_print_coor(t_coor *coor, t_size *size);

#endif