/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:58:36 by anferre           #+#    #+#             */
/*   Updated: 2024/04/12 19:20:33 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philosopher.h>

void	ft_destroy_mutex(pthread_mutex_t *mutex, pthread_mutex_t *mutex2, \
int nb_philosophers)
{
	int i;

	i = 0;
	if (mutex)
	{
		while (i < nb_philosophers)
		{
			pthread_mutex_destroy(&mutex[i]);
			i++;
		}
		free(mutex);
	}
	i = 0;
	if (mutex2)
	{
		while (i < nb_philosophers)
		{
			pthread_mutex_destroy(&mutex[i]);
			i++;
		}
		free(mutex);
	}
}

void	ft_delete_mutex(t_philo *philo)
{
	if (philo->right_fork && philo->nb_philo)
	{
		ft_destroy_mutex(philo->right_fork, NULL, philo->nb_philo);
		philo->right_fork = NULL;
	}
	if (philo->last_meal_mutex && philo->nb_philo)
	{
		ft_destroy_mutex(philo->last_meal_mutex, NULL, philo->nb_philo);
		philo->last_meal_mutex = NULL;
	}
	if (philo->nb_eat_mutex && philo->nb_philo)
	{
		ft_destroy_mutex(philo->nb_eat_mutex, NULL, philo->nb_philo);
		philo->nb_eat_mutex = NULL;
	}
	if (philo->print_mutex && philo->nb_philo)
	{
		pthread_mutex_destroy(philo->print_mutex);
		free(philo->print_mutex);
		philo->print_mutex = NULL;
	}
}

void	ft_clean(t_philo *philo, char *str)
{
	int i;

	if (str)
		write(1, str, ft_strlen(str));
	ft_delete_mutex(philo);
	free(philo->print_mutex);
	free(philo->stop_mutex);
	i = 0;
	if (philo)
	{
		free((void *)philo->stop);
		philo->stop = NULL;
		ft_free_to_i(philo, philo->nb_philo - 1);
		free(philo);
	}
	philo = NULL;
}

void	ft_free_to_i(t_philo *philo, int i)
{
	while (i >= 0)
	{
		if (philo[i].thread)
			free(philo[i].thread);
		philo[i].thread = NULL;
		if (philo[i].death_check)
			free(philo[i].death_check);
		philo[i].death_check = NULL;
		i--;
	}
}