/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_threads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:32 by anferre           #+#    #+#             */
/*   Updated: 2024/04/15 15:26:26 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

//sleep and think
static void	*ft_philosopher_sleep_think(t_philo *philo, long long ms_time)
{
	ft_print(ms_time, philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
	pthread_mutex_lock(philo->stop_mutex);
	if (*philo->stop)
	{
		pthread_mutex_unlock(philo->stop_mutex);
		return ((void *)(-1));
	}
	pthread_mutex_unlock(philo->stop_mutex);
	ft_print(ms_time, philo, "is thinking");
	usleep((philo->time_to_die - philo->time_to_sleep - philo->time_to_eat) \
	* 200);
	return (0);
}

//wait for the forks and eat
static void	ft_philosopher_eat(t_philo *philo, long long ms_time)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(ms_time, philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print(ms_time, philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print(ms_time, philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		ft_print(ms_time, philo, "has taken a fork");
	}
	pthread_mutex_lock(philo->last_meal_mutex);
	ft_get_time(&philo->last_meal);
	pthread_mutex_unlock(philo->last_meal_mutex);
	ft_print(ms_time, philo, "is eating");
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(philo->nb_eat_mutex);
	philo->nb_eat++;
	pthread_mutex_unlock(philo->nb_eat_mutex);
}

static void	*ft_routine(t_philo *philo, long long ms_time)
{
	pthread_mutex_unlock(philo->stop_mutex);
	ft_philosopher_eat(philo, ms_time);
	pthread_mutex_lock(philo->stop_mutex);
	if (*philo->stop || (philo->nb_meal && philo->nb_eat >= philo->nb_meal))
	{
		pthread_mutex_unlock(philo->stop_mutex);
		return ((void *)(-1));
	}
	pthread_mutex_unlock(philo->stop_mutex);
	if (ft_philosopher_sleep_think(philo, ms_time) == (void *)(-1))
		return ((void *)(-1));
	return ((void *)(0));
}

static void	ft_one_philo(t_philo *philo, long long ms_time)
{
	pthread_mutex_unlock(philo->stop_mutex);
	pthread_mutex_lock(philo->right_fork);
	ft_print(ms_time, philo, "has taken a fork");
	usleep((philo->time_to_die + 11) * 1000);
	pthread_mutex_unlock(philo->right_fork);
}

//threads that simulate the philosopher's actions
void	*ft_philosopher(void *arg)
{
	t_philo		*philo;
	long long	ms_time;

	philo = (t_philo *)arg;
	ms_time = 0;
	pthread_mutex_lock(philo->stop_mutex);
	while (!*philo->stop)
	{
		if (philo->nb_philo == 1)
			ft_one_philo(philo, ms_time);
		else if (*philo->stop == false)
		{
			if (ft_routine(philo, ms_time) == (void *)(-1))
				return (0);
		}
		else
			pthread_mutex_unlock(philo->stop_mutex);
		pthread_mutex_lock(philo->stop_mutex);
	}
	pthread_mutex_unlock(philo->stop_mutex);
	return ((void *)(-1));
}
