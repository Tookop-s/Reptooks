/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:14:20 by anferre           #+#    #+#             */
/*   Updated: 2024/03/04 17:58:08 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	*ft_fill_array(t_coor *coor, int fd, int rows, int cols)
{
	char	*line;
	char	**tabsplit;
	int		y;
	int		x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		line = get_next_line(fd);
		tabsplit = ft_split(line, ' ');
		while (x < cols)
		{
			coor[x + y * cols].ix = x;
			coor[x + y * cols].iy = y;
			coor[x + y * cols].iz = ft_atoi(tabsplit[x]);
			x++;
		}
		y++;
		free(line);
		ft_free_split(tabsplit);
	}
	return (coor);
}

void	*ft_parsing(char **argv, t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	data->coor = ft_fill_array(data->coor, fd, data->size->rows, \
	data->size->cols);
	close(fd);
	ft_resize_3d(data->size, data->coor);
	while (i < data->size->rows * data->size->cols)
	{
		data->coor[i].dx = data->coor[i].ix;
		data->coor[i].dy = data->coor[i].iy;
		data->coor[i].dz = data->coor[i].iz;
		i++;
	}
	return (data);
}
