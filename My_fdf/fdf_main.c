/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:54:37 by anferre           #+#    #+#             */
/*   Updated: 2024/02/28 17:43:59 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_print_coor(t_coor *coor, t_size *size)
{
	int i = 0;

	while (i < (*size).rows * (*size).cols)
	{
		
		printf(" x = %d y = %d  | ", coor[i].x, coor[i].y);
		printf("dx = %f dy =  %f", coor[i].dx, coor[i].dy);
		printf("\n");
		i++;
	}
	printf("\n");
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
	if (fd < 0 || data->size == NULL)
		return (NULL);
	if (!ft_get_size(fd, data->size))
		return (NULL);
	close(fd);
	data->coor = ft_init_coor(data->size);
	data->mlx = ft_initialize_window(argv[0]);
	data->data_img = ft_initialize_image(data->data_img, data->mlx);
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
	data = ft_parsing(argv, data);
	if (!data)
		return (ft_free_struct(data), 1);
	ft_project(data);
	ft_free_struct(data);
	return (0);
}


