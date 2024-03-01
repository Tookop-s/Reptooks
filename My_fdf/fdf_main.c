/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:54:37 by anferre           #+#    #+#             */
/*   Updated: 2024/03/01 15:53:18 by anferre          ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_data	*data;
	

	if (argc != 2)
		return (1);

	data = ft_init_data(argv);
	if (!data)
		return (1);
	data = ft_parsing(argv, data);
	if (!data)
		return (ft_free_struct(data), 1);
	ft_project(data);
	ft_free_struct(data);
	return (0);
}
