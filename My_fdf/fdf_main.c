/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:54:37 by anferre           #+#    #+#             */
/*   Updated: 2024/02/14 16:55:44 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		return (1);
	ft_project(array3d, size, argv[1]);
	return (0);
		
}

// isometric projection
// u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°)
// v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°)
// void	ft_print_array(int **array)
// {
// 	int i = 0;
// 	int j = 0;

// 	while (i < 10)
// 	{
// 		j = 0;
// 		while (j < 10)
// 		{
// 			ft_printf("%d", array[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
	
// }