/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:14:20 by anferre           #+#    #+#             */
/*   Updated: 2024/02/23 14:08:35 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	*ft_new_array(t_size *size)
{
	int	**array;
	int	i;

	i = 0;
	array = malloc(size->rows * sizeof(int*));
	if (!array)
		return (NULL);
	while (i < size->rows)
	{
		array[i] = malloc(size->cols * sizeof(int));
		if (!array)
			return(NULL);
		i++;
	}
	return (array);
}

void	ft_free_array(int **array, int rows)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_split(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free (str);
}

void	*ft_init_size()
{
	t_size	*size;

	size = malloc(sizeof(t_size));
	if (!size)
		return (NULL);
	size->cols = 0;
	size->rows = 0;
	size->a = 0;
	size->b = 0;
	return (size);
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
		if ((str[i] == ' ') | (str[i] == '\t')| (str[i] == '\n'))
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

void	ft_free_struct(t_data *data)
{
	if (data)
	{
		ft_free_array(data->array3d, data->size->rows);
		mlx_destroy_image(data->mlx->mlx, data->data_img->img);
		free(data->data_img);
		mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
		mlx_destroy_display(data->mlx->mlx);
		free(data->mlx->mlx);
		ft_free_coor(data->coor);
		free(data->size);
	}
	free(data);
}