/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:44:56 by anferre           #+#    #+#             */
/*   Updated: 2024/03/05 16:31:52 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_size(int fd, t_size *size)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (0);
	size->cols = ft_countcols(str);
	while (str)
	{
		if (ft_countcols(str) != size->cols)
			return (free (str), get_next_line(-1), 0);
		free (str);
		size->rows++;
		str = get_next_line(fd);
	}
	return (1);
}

int	ft_countcols(char *str)
{
	int	i;
	int	check;
	int	sum;

	i = 0;
	check = 1;
	sum = 0;
	while (str[i])
	{
		if ((str[i] == ' ') | (str[i] == '\t') | (str[i] == '\n'))
			check = 1;
		else if (check == 1)
		{
			sum++;
			check = 0;
		}
		i++;
	}
	return (sum);
}

void	*ft_init_data(char **argv)
{
	int		fd;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->size = ft_init_size();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || data->size == NULL)
		return (free(data->size), free(data), NULL);
	if (!ft_get_size(fd, data->size))
		return (free(data->size), free(data), NULL);
	close(fd);
	data->coor = ft_init_coor_tab(data->size);
	if (!data->coor)
		return (free(data->size), free(data), NULL);
	data->mlx = ft_initialize_window(argv[0]);
	if (!data->mlx)
		return (free(data->size), free(data->coor), free(data), NULL);
	data->data_img = ft_initialize_image(data->data_img, data->mlx);
	if (!data->mlx)
		return (mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win), \
		mlx_destroy_display(data->mlx->mlx), free(data->size), free(data->coor) \
		, free(data), NULL);
	return (data);
}

void	*ft_init_size(void)
{
	t_size	*size;

	size = malloc(sizeof(t_size));
	if (!size)
		return (NULL);
	size->cols = 0;
	size->rows = 0;
	size->x = 0;
	size->y = 0;
	size->z = 0;
	size->middle_x = 0;
	size->middle_y = 0;
	size->scale_f = 0;
	size->scale_z = 1;
	return (size);
}

void	*ft_init_coor_tab(t_size *size)
{
	t_coor	*coor;
	int		i;

	i = 0;
	coor = malloc(((*size).rows * (*size).cols) * sizeof(t_coor));
	if (!coor)
		return (NULL);
	while (i < (*size).rows * (*size).cols)
	{
		coor[i].x = 0;
		coor[i].y = 0;
		coor[i].dz = 0;
		coor[i].dx = 0;
		coor[i].dy = 0;
		coor[i].iz = 0;
		coor[i].ix = 0;
		coor[i].iy = 0;
		coor[i].clr = 0;
		i++;
	}
	return (coor);
}
