/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:40:09 by anferre           #+#    #+#             */
/*   Updated: 2024/02/19 17:51:46 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define RED_COLOR 0xFF0000
# define GREEN_COLOR 0x00FF00
# define BLUE_COLOR 0x0000FF
# define WHITE_COLOR 0xFFFFFF

# define WINDOW_HEIGTH 600
# define WINDOW_WIDTH 300

# define ISO_ANGLE 30

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_data;
//bpp = bit per pixel & ll = line lenght

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_data	*data_img;
}				t_mlx;

typedef struct s_coor
{
	int	x;
	int	y;
}				t_coor;

typedef struct s_size
{
	int	rows;
	int	cols;
}				t_size;

		/*Parsing*/
void	*ft_parsing(char **argv, t_size *size);
		/*Utils*/
void	*ft_new_array(int rows, int cols);
void	ft_free_array(int **array, int rows);
void	*ft_init_size();
void	ft_free_split(char **str);

		/*Projection*/
void	*ft_project(int **array, t_size *size, char *title);
		/*Utils*/
void	ft_free_all(int **array, t_coor *coor, t_size *size);
void	*ft_new_coor(t_size *size);
void	ft_free_coor(t_coor *coor);

		/*mlx*/
void	*ft_initialize_window(char *title);
void	*ft_initialize_image(t_mlx *mlx);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_init_background(t_data *data, int color);

void	ft_print_coor(t_coor *coor, t_size *size);

#endif