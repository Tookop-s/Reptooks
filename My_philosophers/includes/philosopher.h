/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:20:52 by anferre           #+#    #+#             */
/*   Updated: 2024/04/09 16:18:44 by anferre          ###   ########.fr       */
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

//volatile removes some compiler optimizations that could cause the variable to be stored in a register
typedef struct philo
{
	int				id;
	int				nb_eat;
	int				nb_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	volatile int	stop;
	pthread_t		*thread;
	pthread_t 		*death_check;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*last_meal_mutex;
	long long		last_meal;
	long long		start_time;
}				t_philo;


long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_get_time(long long *ms_time);
void	ft_print(long long ms_time, t_philo *philo, char *str);

#endif