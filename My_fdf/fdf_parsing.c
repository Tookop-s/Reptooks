/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:14:20 by anferre           #+#    #+#             */
/*   Updated: 2024/02/28 14:02:15 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	ft_get_size(int	fd, t_size *size)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (0);
	size->cols = ft_countcols(str);
	while (str)
	{
		if (ft_countcols(str) != size->cols && str != NULL)
			return (0);
		free (str);
		size->rows++;
		str = get_next_line(fd);
	}
	return (1);
}

static void	*ft_fill_array(t_coor *coor, int fd, int rows, int cols)
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
	int		fd;

	fd = open(argv[1], O_RDONLY);
	data->coor = ft_fill_array(data->coor ,fd , data->size->rows, data->size->cols);
	close(fd);
	return (data);
}