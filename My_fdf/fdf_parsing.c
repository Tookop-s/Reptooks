/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:14:20 by anferre           #+#    #+#             */
/*   Updated: 2024/02/22 17:35:32 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_size(int	fd, t_size *size)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (0);
	size->cols = ft_countword(str) - 1;
	while (str)
	{
		free (str);
		size->rows++;
		if ((int)ft_strlen(str) != size->cols)
			return (0);
		str = get_next_line(fd);
	}
	return (1);
}

void	*ft_fill_array(int **array3d, int fd, int rows, int cols)
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
		ft_free_split(tabsplit);
	}
	return (array3d);
}

void	*ft_parsing(char **argv, t_size *size, int **array3d)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	array3d = ft_fill_array(array3d, fd, (*size).rows, (*size).cols);
	close(fd);
	return (array3d);
}