/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:47:53 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/30 18:53:34 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	usage_error(char *s)
{
	printf("Error\n%s\n", s);
	exit(EXIT_FAILURE);
}

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(500);
	return (0);
}

void	print_status(t_philo *philo, char *msg)
{
	bool	is_dead;

	if (!philo || !philo->table || !msg)
		return ;
	pthread_mutex_lock(&philo->table->print_lock);
	pthread_mutex_lock(&philo->table->death_lock);
	is_dead = philo->table->dead;
	pthread_mutex_unlock(&philo->table->death_lock);
	if (!is_dead || (msg[0] == 'd' && msg[1] == 'i'))
	{
		printf("%zu %d %s\n",
			get_time() - philo->table->start_time, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->table->print_lock);
}

long	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num = num + (str[i] - '0');
		++i;
		if (num > INT_MAX)
			break ;
	}
	return (num * sign);
}
