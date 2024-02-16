/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:54:37 by anferre           #+#    #+#             */
/*   Updated: 2024/02/16 17:18:18 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_print_coor(t_coor *coor, t_size *size)
{
	int i = 0;

	while (i < (*size).rows * (*size).cols )
	{

		ft_printf(" x = %d ", coor[i].x);
		ft_printf(" y = %d ", coor[i].y);
		ft_printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	int	**array3d;
	t_size	*size;

	if (argc != 2)
		return (1);
	size = ft_init_size();
	if (!size)
		return (1);
	array3d = ft_parsing(argv, size);
	if (!array3d)
		return (ft_free_all(array3d, NULL, size), 1);
	ft_project(array3d, size, argv[1]);
	return (0);
		
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
