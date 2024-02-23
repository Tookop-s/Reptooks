/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:54:37 by anferre           #+#    #+#             */
/*   Updated: 2024/02/23 14:16:05 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <stdio.h>

void	ft_print_coor(t_coor *coor, t_size *size)
{
	int i = 0;
	int j = 0;

	while (i < (*size).rows)
	{
		j = 0;
		while (j < (*size).cols)
		{
			printf(" x = %d y = %d ", coor[j + i * (*size).cols].x, coor[j + i * (*size).cols].y);
			j++;
		}
		printf("\n");
		i++;
	}
}
void	*ft_init_data(char **argv)
{
	int fd;
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->size = ft_init_size();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!ft_get_size(fd, data->size))
		return (NULL);
	close(fd);
	data->coor = ft_init_coor(data->size);
	data->mlx = ft_initialize_window(argv[0]);
	data->data_img = ft_initialize_image(data->data_img, data->mlx);
	data->array3d = ft_new_array(data->size);
	return (data);
}

int main(int argc, char **argv)
{
	t_data	*data;
	

	if (argc != 2)
		return (1);

	data = ft_init_data(argv);
	if (!data)
		return (ft_free_struct(data), 1);
	data->array3d = ft_parsing(argv, data->size, data->array3d);
	if (!data->array3d)
		return (ft_free_struct(data), 1);
	ft_project(data);
	return (ft_free_struct(data), 0);
		
}

// isometric projection
// u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°)
// v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°)
// α = 30 or 45

// coor[i][j].x = (j - array3d[i][j]) / sqrt(2);
// coor[i][j].y = (j + 2 * i + array3d[i][j]) / sqrt(6);

// t = j * cos(a) + i * cos(a + 2) + array3d[i][j] * cos(a - 2);
// 			r = j * sin(a) + i * sin(a + 2) + array3d[i][j] * sin(a - 2);
// 			coor[i][j].x = t;
// 			coor[i][j].y = r;
