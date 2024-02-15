/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:14:20 by anferre           #+#    #+#             */
/*   Updated: 2024/02/14 16:35:16 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_size(int	fd, int *rows, int *cols)
{
	char	*str;

	str = get_next_line(fd);
	*rows = 1;
	*cols = ft_countword(str) - 1;
	while (get_next_line(fd))
		(*rows)++;
}

static void	*ft_fill_array(int **array3d, int fd, int rows, int cols)
{
	char	*line;
	char	**tabsplit;
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		line = get_next_line(fd);
		tabsplit = ft_split(line, ' ');
		while (j < cols)
		{
			array3d[i][j] = ft_atoi(tabsplit[j]);
			j++;
		}
		i++;
		free(line);
		ft_free_split(tabsplit, cols);
	}
	return (array3d);
}

void	*ft_parsing(char **argv, t_size *size)
{
	int		fd;
	int		**array3d;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	ft_get_size(fd, &(*size).rows, &(*size).cols);
	close(fd);
	array3d = ft_new_array((*size).rows, (*size).cols);
	fd = open(argv[1], O_RDONLY);
	array3d = ft_fill_array(array3d, fd, (*size).rows, (*size).cols);
	close(fd);
	return (array3d);
}