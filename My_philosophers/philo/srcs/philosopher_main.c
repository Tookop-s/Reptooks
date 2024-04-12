/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:20:25 by anferre           #+#    #+#             */
/*   Updated: 2024/04/12 18:09:32 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philosopher.h>

//sleep and think
void	ft_philosopher_sleep_think(t_philo *philo, long long ms_time)
{
	ft_print(ms_time, philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
	ft_print(ms_time, philo, "is thinking");
	usleep(1000);
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

//threads that simulate the philosopher's actions
void	*ft_philosopher(void *arg)
{
	t_philo *philo;
	long long ms_time;
	int start;

	philo = (t_philo *)arg;
	ms_time = 0;
	start = 1;
	pthread_mutex_lock(philo->stop_mutex);
	while (!*philo->stop)
	{
		if (philo->nb_philo == 1)
		{
			pthread_mutex_unlock(philo->stop_mutex);
			pthread_mutex_lock(philo->right_fork);
			ft_print(ms_time, philo, "has taken a fork");
			pthread_mutex_unlock(philo->right_fork);
			usleep(philo->time_to_die * 1000);
		}
		else if (*philo->stop == false)
		{
			pthread_mutex_unlock(philo->stop_mutex);
			ft_philosopher_eat(philo, ms_time);
			pthread_mutex_lock(philo->stop_mutex);
			if (*philo->stop || (philo->nb_meal && philo->nb_eat >= philo->nb_meal))
			{
				pthread_mutex_unlock(philo->stop_mutex);
				return (0);
			}
			pthread_mutex_unlock(philo->stop_mutex);
			ft_philosopher_sleep_think(philo, ms_time);
		}
		else
			pthread_mutex_unlock(philo->stop_mutex);
		pthread_mutex_lock(philo->stop_mutex);
	}
	pthread_mutex_unlock(philo->stop_mutex);
	return (void *)(-1);
}

void	*ft_check_last_meal(t_philo *philo, long long ms_time)
{
	long long	last_meal;

	pthread_mutex_lock(philo->last_meal_mutex);
	last_meal = philo->last_meal;
	if (last_meal == 0)
		last_meal = philo->start_time;
	pthread_mutex_unlock(philo->last_meal_mutex);
	ft_get_time(&ms_time);
	if ((ms_time - last_meal > philo->time_to_die) && !*philo->stop)
	{
		pthread_mutex_lock(philo->print_mutex);
		if (!*philo->stop)
			printf("%lld %d died \n", ms_time - philo->start_time, philo->id + 1);
		pthread_mutex_unlock(philo->print_mutex);
		*philo->stop = true;
		pthread_mutex_unlock(philo->stop_mutex);
		return (void *)(-1);
	}
	pthread_mutex_unlock(philo->stop_mutex);
	return (void *)(0);
}

/*threads that compares the time of the last meal with the current time 
if above the limit stop = true and stops all the threads */
void	*ft_death_check(void *arg)
{
	t_philo *philo;
	long long ms_time;
	int 	i;

	i = -1;
	ms_time = 0;
	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->stop_mutex);
	while (!*philo->stop)
	{
		if (ft_check_last_meal(philo, ms_time) == (void *)(-1))
			return (void *)(-1);
		pthread_mutex_lock(philo->nb_eat_mutex);
		if (philo->nb_meal && philo->nb_eat >= philo->nb_meal)
		{
			pthread_mutex_unlock(philo->nb_eat_mutex);
			return (0);
		}
		pthread_mutex_unlock(philo->nb_eat_mutex);
		pthread_mutex_lock(philo->stop_mutex);
	}
	pthread_mutex_unlock(philo->stop_mutex);
	return (void *)(-1);
}

int	ft_join(t_philo *philo)
{
	int		i;
	void	*status;
	int			ret;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_join(*philo[i].death_check, &status);
		if (status == (void *)(-1))
			ret = 1;
		i++;
	}
	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_join(*philo[i].thread, NULL);
		i++;
	}
	return (ret);
}

int main(int argc, char **argv)
{
	t_philo		*philo;
	int 		i;
	int 		nb_philo;
	int			ret;

	nb_philo = ft_atoi(argv[1]);
	i = -1;
	ret = 0;
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
	ret = ft_join(philo);
	ft_clean(philo, NULL);
	return (ret);
}
/* -fsanitize=thread -g 
 valgrind --tool=helgrind ./programme.
 valgrind --tool=drd ./programme.
 valgrind et -fsanitize=thread ne s’entendent pas du tout et ne doivent pas s’utiliser ensemble !
 -fsanitize=address et valgrind*/