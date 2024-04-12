/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:58:18 by anferre           #+#    #+#             */
/*   Updated: 2024/04/12 18:27:20 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

long	ft_atoi(const char *str)
{
	unsigned int	i;
	int				neg;
	long			nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg = -neg;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_get_time(long long *ms_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	*ms_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

void	ft_print(long long ms_time, t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print_mutex);
	ft_get_time(&ms_time);
	if (*philo->stop)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	printf("%lld %d %s\n", ms_time - philo->start_time, philo->id + 1, str);
	pthread_mutex_unlock(philo->print_mutex);
}
