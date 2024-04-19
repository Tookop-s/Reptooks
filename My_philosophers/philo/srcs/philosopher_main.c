/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:20:25 by anferre           #+#    #+#             */
/*   Updated: 2024/04/19 13:48:30 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	ft_check_last_meal(t_philo *philo, long long ms_time)
{
	long long	last_meal;

	pthread_mutex_lock(philo->last_meal_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(philo->last_meal_mutex);
	if (last_meal == 0)
		last_meal = philo->start_time;
	ft_get_time(&ms_time);
	if ((ms_time - last_meal > philo->time_to_die))
	{
		pthread_mutex_lock(philo->stop_mutex);
		*philo->stop = true;
		pthread_mutex_unlock(philo->stop_mutex);
		pthread_mutex_lock(philo->print_mutex);
		printf("%lld %d died\n", ms_time - philo->start_time, philo->id + 1);
		pthread_mutex_unlock(philo->print_mutex);
		return (-1);
	}
	return (0);
}

t_bool	ft_get_stop_val(t_philo *philo)
{
	t_bool	stop;

	pthread_mutex_lock(philo->stop_mutex);
	stop = *philo->stop;
	pthread_mutex_unlock(philo->stop_mutex);
	return (stop);
}

/*threads that compares the time of the last meal with the current time 
if above the limit stop = true and stops all the threads */
int	ft_death_check(t_philo *philo)
{
	long long	ms_time;
	int			i;
	t_bool		stop;

	ms_time = 0;
	stop = ft_get_stop_val(philo);
	while (!stop)
	{
		i = 0;
		while (i < philo->nb_philo)
		{
			if (ft_check_last_meal(&philo[i], ms_time) == -1)
				return (0);
			pthread_mutex_lock(philo[i].nb_eat_mutex);
			if (philo->nb_meal && philo[i].nb_eat >= philo->nb_meal)
			{
				pthread_mutex_unlock(philo[i].nb_eat_mutex);
				return (0);
			}
			pthread_mutex_unlock(philo[i].nb_eat_mutex);
			i++;
			stop = ft_get_stop_val(philo);
		}
	}
	return (0);
}

void	ft_join(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_join(*philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	int			i;
	int			nb_philo;
	int			ret;

	if (argc < 5 || argc > 6 || !ft_check_args(argv))
		return (write(1, "Error: wrong arguments\n", 24), 1);
	nb_philo = ft_atoi(argv[1]);
	i = -1;
	philo = ft_init(argv, argc);
	if (!philo)
		return (write(1, "Error initializing the struct \n", 32), 2);
	while (++i < nb_philo)
		ft_get_time(&philo[i].start_time);
	i = 0;
	pthread_mutex_lock(philo->stop_mutex);
	while (i < nb_philo)
	{
		pthread_create(philo[i].thread, NULL, &ft_philosopher, &philo[i]);
		i++;
	}
	pthread_mutex_unlock(philo->stop_mutex);
	ret = ft_death_check(philo);
	ft_join(philo);
	return (ft_clean(philo, NULL), ret);
}
/* -fsanitize=thread -g 
 valgrind --tool=helgrind ./programme.
 valgrind --tool=drd ./programme.
 valgrind et -fsanitize=thread out et ne doivent pas s’utiliser ensemble !
 -fsanitize=address 
 
 check if there is a mutex to prevent a philosopher from diying and starting
  eating at the same time yes = the stop mutex*/