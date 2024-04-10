/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:20:25 by anferre           #+#    #+#             */
/*   Updated: 2024/04/10 18:12:42 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philosopher.h>

void	*ft_init_philosophers(char **argv, pthread_mutex_t *fork_mutex, pthread_mutex_t *meal_mutex, pthread_mutex_t *print_mutex)
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
		philosophers[i].nb_philo = nb_philosophers;
		philosophers[i].last_meal = 0;
		if (nb_philosophers == 1)
			philosophers[i].left_fork = NULL;
		else 
			philosophers[i].left_fork = &fork_mutex[(i + 1) % nb_philosophers]; //need to check when there is only 1 philosopher
		philosophers[i].right_fork = &fork_mutex[i];
		philosophers[i].last_meal_mutex = &meal_mutex[i];
		philosophers[i].print_mutex = print_mutex;
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

	if (str)
		write(1, str, ft_strlen(str));
	if (philo->left_fork && nb_phil)
		ft_destroy_mutex(philo->left_fork, nb_phil);
	if (philo->last_meal_mutex && nb_phil)
		ft_destroy_mutex(philo->last_meal_mutex, nb_phil);
	i = 0;
	if (philo)
	{
		while (i < nb_phil)
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

//sleep and think
void	ft_philosopher_sleep_think(t_philo *philo, long long ms_time)
{
	if (philo->stop == 0)
		ft_print(ms_time, philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
	if  (philo->stop == 0)
		ft_print(ms_time, philo, "is thinking");
}

//wait for the forks and eat
void	ft_philosopher_eat(t_philo *philo, long long ms_time)
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
	ft_print(ms_time, philo, "is eating");
	ft_get_time(&ms_time);
	philo->last_meal = ms_time;
	pthread_mutex_unlock(philo->last_meal_mutex);
	philo->nb_eat++;
	printf("philo %d nb_eat = %d nb_meal = %d\n", philo->id, philo->nb_eat, philo->nb_meal);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);

}

//threads that simulate the philosopher's actions
void	*ft_philosopher(void *arg)
{
	t_philo *philo;
	long long ms_time;
	int start;

	philo = (t_philo *)arg;
	ms_time = 0;
	start = 1;
	while (!philo->stop)
	{
		if (philo->nb_philo == 1)
		{
			pthread_mutex_lock(philo->right_fork);
			ft_print(ms_time, philo, "has taken a fork");
			pthread_mutex_unlock(philo->right_fork);
			usleep(philo->time_to_die * 1000);
		}
		else if (philo->stop == 0)
		{
			ft_philosopher_eat(philo, ms_time);
			if (philo->stop || (philo->nb_meal && philo->nb_eat >= philo->nb_meal))
				return (0);
			ft_philosopher_sleep_think(philo, ms_time);
		}
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
		if (last_meal == 0)
			last_meal = philo->start_time;
		pthread_mutex_unlock(philo->last_meal_mutex);
		ft_get_time(&ms_time);
		if (ms_time - last_meal > philo->time_to_die)
		{
			pthread_mutex_lock(philo->print_mutex);
			printf("%lld %d died last_meal = %lld start_time = %lld\n", ms_time, philo->id, last_meal, philo->start_time);
			pthread_mutex_unlock(philo->print_mutex);
			return (void *)(-1);
		}
		usleep(9000);
		if (philo->nb_eat >= philo->nb_meal)
			return (0);
	}
	return (void *)(-1);
}

static void	*ft_init(char **argv, int argc)
{
	t_philo			*philo;
	pthread_mutex_t *fork_mutex;
	pthread_mutex_t *meal_mutex;
	pthread_mutex_t *print_mutex;
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
	print_mutex = ft_init_mutex(nb_philo);
	philo = ft_init_philosophers(argv, fork_mutex, meal_mutex, print_mutex);
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
	i = -1;
	philo = ft_init(argv, argc);
	while (++i < nb_philo)
		ft_get_time(&philo[i].start_time);
	i = 0;
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
				else
					pthread_detach(*philo[j].thread);
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