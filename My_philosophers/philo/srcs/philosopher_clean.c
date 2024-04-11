/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:58:36 by anferre           #+#    #+#             */
/*   Updated: 2024/04/11 15:58:57 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philosopher.h>

void	ft_destroy_mutex(pthread_mutex_t *mutex, int nb_philosophers)
{
	int i;

	i = 0;
	while (i < nb_philosophers)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
	free(mutex);
}

void	ft_clean(t_philo *philo, char *str)
{
	int i;

	if (str)
		write(1, str, ft_strlen(str));
	if (philo->right_fork && philo->nb_philo)
	{
		ft_destroy_mutex(philo->right_fork, philo->nb_philo);
		free(philo->right_fork);
		philo->right_fork = NULL;
	}
	if (philo->last_meal_mutex && philo->nb_philo)
	{
		ft_destroy_mutex(philo->last_meal_mutex, philo->nb_philo);
		free(philo->last_meal_mutex);
		philo->last_meal_mutex = NULL;
	}
	if (philo->last_meal_mutex && philo->nb_philo)
	{
		pthread_mutex_destroy(philo->print_mutex);
		free(philo->print_mutex);
		philo->print_mutex = NULL;
	}
	i = 0;
	if (philo)
	{
		free((void *)philo->stop);
		philo->stop = NULL;
		while (i < philo->nb_philo)
		{
			free(philo[i].thread);
			philo[i].thread = NULL;
			free(philo[i].death_check);
			philo[i].death_check = NULL;
			i++;
		}
		free(philo);
	}
	philo = NULL;
}