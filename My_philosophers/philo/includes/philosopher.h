/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:20:52 by anferre           #+#    #+#             */
/*   Updated: 2024/04/15 15:44:42 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef enum e_bool
{
	true = 1,
	false = 0
}			t_bool;

/*volatile removes some compiler optimizations that could cause the variable 
to be stored in a register*/
typedef struct philo
{
	int				id;
	int				nb_eat;
	int				nb_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_philo;
	volatile t_bool	*stop;
	pthread_t		*thread;
	pthread_t		*death_check;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*last_meal_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*stop_mutex;
	pthread_mutex_t	*nb_eat_mutex;
	long long		last_meal;
	long long		start_time;
}				t_philo;

		/*utils*/
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_get_time(long long *ms_time);
void	ft_print(long long ms_time, t_philo *philo, char *str);

		/*init*/
void	*ft_init(char **argv, int argc);

		/*threads*/
void	*ft_philosopher(void *arg);

		/*clean*/
void	ft_clean(t_philo *philo, char *str);
void	ft_destroy_mutex(pthread_mutex_t *mutex, pthread_mutex_t *mutex2, \
int nb_philosophers);
void	ft_free_to_i(t_philo *philo, int i);
void	ft_delete_mutex(t_philo *philo);

#endif