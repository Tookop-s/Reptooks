/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:20:25 by anferre           #+#    #+#             */
/*   Updated: 2024/04/09 16:37:06 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philosopher.h>

void	*ft_init_philosophers(int argc, char **argv, pthread_mutex_t *fork_mutex, pthread_mutex_t *meal_mutex)
{
	t_philo	*philosophers;
	int		i;
	int		nb_philosophers;

	nb_philosophers = ft_atoi(argv[1]);
	philosophers = malloc(sizeof(t_philo) * nb_philosophers);
	if (!philosophers)
		return (NULL);
	i = -1;
	while (++i < nb_philosophers)
	{
		philosophers[i].id = i;
		philosophers[i].stop = 0;
		philosophers[i].nb_eat = 0;
		philosophers[i].nb_meal = 0;
		philosophers[i].time_to_die = ft_atoi(argv[2]);
		philosophers[i].time_to_eat = ft_atoi(argv[3]);
		philosophers[i].time_to_sleep = ft_atoi(argv[4]);
		philosophers[i].left_fork = &fork_mutex[i];
		philosophers[i].right_fork = &fork_mutex[(i + 1) % nb_philosophers];
		philosophers[i].last_meal_mutex = &meal_mutex[i];
		ft_get_time(&philosophers[i].start_time);
		if (argc == 6)
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

void	ft_clean(t_philo *philo, int nb_phil, char *str)
{
	int i;

	i = -1;
	if (str)
		write(1, str, ft_strlen(str));
	if (philo->left_fork && nb_phil)
	{
		ft_destroy_mutex(philo->left_fork, nb_phil);
	}
	i = -1;
	if (philo->last_meal_mutex && nb_phil)
	{
		ft_destroy_mutex(philo->last_meal_mutex, nb_phil);
	}
	if (philo)
		free(philo);
	philo = NULL;
}


//wait for the forks and eat
void	ft_philosopher_eat(t_philo *philo, long long ms_time)
{
	if (philo->left_fork < philo->right_fork)
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
	ft_print(ms_time, philo, "is eating");
	pthread_mutex_unlock(philo->last_meal_mutex);
	usleep(philo->time_to_eat * 1000);
	philo->nb_eat++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

//sleep and think
void	ft_philosopher_sleep_think(t_philo *philo, long long ms_time)
{
	ft_print(ms_time, philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
	ft_print(ms_time, philo, "is thinking");
}

//threads that simulate the philosopher's actions
void	*ft_philosopher(void *arg)
{
	t_philo *philo;
	long long ms_time;

	philo = (t_philo *)arg;
	ms_time = 0;
	while (!philo->stop)
	{
		if (philo->nb_meal && philo->nb_eat >= philo->nb_meal)
			return (0);
		ft_philosopher_eat(philo, ms_time);
		ft_philosopher_sleep_think(philo, ms_time);
	}
	return (void *)(-1);
}

//threads that check if the philosopher is dead
void	*ft_death_check(void *arg)
{
	t_philo *philo;
	long long ms_time;
	long long last_meal;

	philo = (t_philo *)arg;
	while (!philo->stop)
	{
		pthread_mutex_lock(philo->last_meal_mutex);
		last_meal = philo->last_meal;
		pthread_mutex_unlock(philo->last_meal_mutex);
		ft_get_time(&ms_time);
		if (ms_time - philo->last_meal > philo->time_to_die)
		{
			printf("%lld %d died\n", ms_time, philo->id);
			return (void *)(-1);
		}
		usleep(9999);
	}
	return (void *)(-1);
}

static void	*ft_init(char **argv, int argc)
{
	t_philo			*philo;
	pthread_mutex_t *fork_mutex;
	pthread_mutex_t *meal_mutex;
	int 			nb_philo;

	nb_philo = ft_atoi(argv[1]);
	if (argc != 5 && argc != 6)
		return (ft_clean(NULL, nb_philo, "Wrong number of arguments"), NULL);
	if (nb_philo < 1)
		return (ft_clean(NULL, nb_philo, "Philo must be at least 1"), NULL);
	fork_mutex = ft_init_mutex(nb_philo);
	if (!fork_mutex)
		return (ft_clean(NULL, nb_philo, "mutex init"), NULL);
	meal_mutex = ft_init_mutex(nb_philo);
	if (!meal_mutex)
		return (ft_destroy_mutex(fork_mutex, nb_philo) ,ft_clean(NULL,\
		nb_philo, "mutex init"), NULL);
	philo = ft_init_philosophers(argc, argv, fork_mutex, meal_mutex);
	if (!philo)
	{
		ft_destroy_mutex(fork_mutex, nb_philo);
		ft_destroy_mutex(meal_mutex, nb_philo);
		return (ft_clean(NULL, nb_philo, "philo init"), NULL);
	}
	return (philo);
}

int main(int argc, char **argv)
{
	t_philo			*philo;
	int 			i;
	int 			j;
	void 			*status;
	int 			nb_philo;

	nb_philo = ft_atoi(argv[1]);
	i = 0;
	philo = ft_init(argv, argc);
	while (i < nb_philo)
	{
		pthread_create(philo[i].thread, NULL, &ft_philosopher, &philo[i]);
		pthread_create(philo[i].death_check, NULL, &ft_death_check, &philo[i]);
		i++;
	}
	i = 0;
	j = 0;
	while (i < nb_philo)
	{
		pthread_join(*philo[i].thread, NULL);
		pthread_join(*philo[i].death_check, &status);
		if ((long long)status == -1)
		{
			while (j < nb_philo)
			{
				philo[j].stop = 1;
				if (j != i)
				{
					pthread_detach(*philo[j].thread);
					pthread_detach(*philo[j].death_check);
				}
				j++;
			}
			return (ft_clean(philo, nb_philo, NULL), 6);
		}
		i++;
	}
}

/* -fsanitize=thread -g 
 valgrind --tool=helgrind ./programme.
 valgrind --tool=drd ./programme.
 valgrind et -fsanitize=thread ne s’entendent pas du tout et ne doivent pas s’utiliser ensemble !
 -fsanitize=address et valgrind*/