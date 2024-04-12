/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:46:50 by anferre           #+#    #+#             */
/*   Updated: 2024/04/12 19:33:39 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

static t_philo *ft_init_multiple(t_philo *philo, pthread_mutex_t *fork_mutex, \
pthread_mutex_t *meal_mutex, pthread_mutex_t *nb_eat_mutex)
{
	int	i;

	i = -1;
	while (++i < philo->nb_philo)
	{
		philo->id = i;
		if (philo->nb_philo == 1)
			philo[i].left_fork = NULL;
		else
			philo[i].left_fork = &fork_mutex[(i + 1) % philo->nb_philo];
		philo[i].right_fork = &fork_mutex[i];
		philo[i].last_meal_mutex = &meal_mutex[i];
		philo[i].nb_eat_mutex = &nb_eat_mutex[i];
		philo[i].thread = malloc(sizeof(pthread_t));
		if (!philo[i].thread)
			return (ft_free_to_i(philo, i - 1), NULL);
		philo[i].death_check = malloc(sizeof(pthread_t));
		if (!philo[i].death_check)
			return (philo[i].death_check = NULL, ft_free_to_i(philo, i), NULL);
	}
	return (philo);
}
//init single does not work need to fix it 
static t_philo *ft_init_single(t_philo *philo, char **argv, pthread_mutex_t *print_mutex, pthread_mutex_t *stop_mutex)
{
	philo->nb_eat = 0;						  
	philo->nb_meal = 0;					  
	philo->time_to_die = ft_atoi(argv[2]);	  
	philo->time_to_eat = ft_atoi(argv[3]);	  
	philo->time_to_sleep = ft_atoi(argv[4]); 	  
	philo->last_meal = 0;
	philo->print_mutex = print_mutex;		  
	philo->stop_mutex = stop_mutex; 
	if (argv[5])
		philo->nb_meal = ft_atoi(argv[5]);
	return (philo);
}

static void	*ft_init_mutex(int nb_philosophers)
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

static void	*ft_init_philosophers(char **argv, pthread_mutex_t *fork_mutex, \
pthread_mutex_t *meal_mutex, pthread_mutex_t *nb_eat_mutex)
{
	t_philo			*philo;
	int				nb_philosophers;
	volatile t_bool	*stop;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*stop_mutex;

	stop = malloc(sizeof(t_bool));
	if (!stop)
		return (NULL);
	*stop = false;
	stop_mutex = ft_init_mutex(1);
	print_mutex = ft_init_mutex(1);
	nb_philosophers = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_philo) * nb_philosophers);
	if (!philo)
		return (free((void *)stop), ft_destroy_mutex(stop_mutex, print_mutex, 1), NULL);
	philo->nb_philo = nb_philosophers;	
	philo->stop = stop;
	philo = ft_init_single(philo, argv, print_mutex, stop_mutex);
	if (!philo)
		return (free((void *)stop), ft_destroy_mutex(stop_mutex, print_mutex, 1), NULL);
	philo = ft_init_multiple(philo, fork_mutex, meal_mutex, nb_eat_mutex);
	if (!philo)
		return (ft_clean(philo, NULL), NULL);
	return (philo);
}

void	*ft_init(char **argv, int argc)
{
	t_philo			*philo;
	pthread_mutex_t *fork_mutex;
	pthread_mutex_t *last_meal_mutex;
	pthread_mutex_t *nb_eat_mutex;
	int 			nb_philo;

	nb_philo = ft_atoi(argv[1]);
	if (argc != 5 && argc != 6)
		return (NULL);
	if (nb_philo < 1)
		return (NULL);
	fork_mutex = ft_init_mutex(nb_philo);
	if (!fork_mutex)
		return (NULL);
	last_meal_mutex = ft_init_mutex(nb_philo);
	if (!last_meal_mutex)
		return (ft_destroy_mutex(fork_mutex, NULL, nb_philo), NULL);
	nb_eat_mutex = ft_init_mutex(nb_philo);
	if (!nb_eat_mutex)
		return (ft_destroy_mutex(fork_mutex, NULL, nb_philo), \
		ft_destroy_mutex(nb_eat_mutex, NULL, nb_philo),NULL);
	philo = ft_init_philosophers(argv, fork_mutex, last_meal_mutex, nb_eat_mutex);
	if (!philo)
		return (NULL);
	return (philo);
}
