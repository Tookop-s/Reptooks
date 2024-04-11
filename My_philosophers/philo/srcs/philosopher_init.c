/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:46:50 by anferre           #+#    #+#             */
/*   Updated: 2024/04/11 16:04:47 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philosopher.h>

void	*ft_init_philosophers(char **argv, pthread_mutex_t *fork_mutex, pthread_mutex_t *meal_mutex)
{
	t_philo	*philosophers;
	int		i;
	int		nb_philosophers;
	volatile t_bool		*stop;
	pthread_mutex_t *print_mutex;
	pthread_mutex_t *stop_mutex;

	stop = malloc(sizeof(t_bool));
	if (!stop)
		return (NULL);
	*stop = false;
	stop_mutex = ft_init_mutex(1);
	print_mutex = ft_init_mutex(1);
	nb_philosophers = ft_atoi(argv[1]);
	philosophers = malloc(sizeof(t_philo) * nb_philosophers);
	if (!philosophers)
		return (NULL);
	i = -1;
	while (++i < nb_philosophers)
	{
		philosophers[i].id = i;
		philosophers[i].stop = stop;
		philosophers[i].nb_eat = 0;
		philosophers[i].nb_meal = 0;
		philosophers[i].time_to_die = ft_atoi(argv[2]);
		philosophers[i].time_to_eat = ft_atoi(argv[3]);
		philosophers[i].time_to_sleep = ft_atoi(argv[4]);
		philosophers[i].nb_philo = nb_philosophers;
		philosophers[i].last_meal = 0;
		if (nb_philosophers == 1)
			philosophers[i].left_fork = NULL;
		else 
			philosophers[i].left_fork = &fork_mutex[(i + 1) % nb_philosophers];
		philosophers[i].right_fork = &fork_mutex[i];
		philosophers[i].last_meal_mutex = &meal_mutex[i];
		philosophers[i].print_mutex = print_mutex;
		philosophers[i].stop_mutex = stop_mutex;
		philosophers[i].thread = malloc(sizeof(pthread_t));
		if (!philosophers[i].thread)
			return (free(philosophers), NULL);
		philosophers[i].death_check = malloc(sizeof(pthread_t));
		if (!philosophers[i].death_check)
			return (free(philosophers), free(philosophers[i].thread), NULL);		
		if (argv[5])
			philosophers[i].nb_meal = ft_atoi(argv[5]);
	}
	return (philosophers);
}

void	*ft_init_mutex(int nb_philosophers)
{
	int i;
	pthread_mutex_t *mutex;

	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * nb_philosophers);
	if (!mutex)
		return (write(1, "Error mutexes malloc", 27), NULL);
	while (i < nb_philosophers)
	{
		if (pthread_mutex_init(&mutex[i], NULL))
			return (write(1, "Error mutexes init", 27), NULL);
		i++;
	}
	return (mutex);
}

void	*ft_init(char **argv, int argc)
{
	t_philo			*philo;
	pthread_mutex_t *fork_mutex;
	pthread_mutex_t *meal_mutex;
	int 			nb_philo;

	nb_philo = ft_atoi(argv[1]);
	if (argc != 5 && argc != 6)
		return (NULL);
	if (nb_philo < 1)
		return (NULL);
	fork_mutex = ft_init_mutex(nb_philo);
	if (!fork_mutex)
		return (NULL);
	meal_mutex = ft_init_mutex(nb_philo);
	if (!meal_mutex)
		return (NULL);
	philo = ft_init_philosophers(argv, fork_mutex, meal_mutex);
	if (!philo)
		return (NULL);
	return (philo);
}
