/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:06:13 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/19 13:41:12 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	check_death(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->death_lock);
	if (table->dead)
	{
		pthread_mutex_unlock(&table->death_lock);
		return (true);
	}
	if ((get_time() - philo->last_meal) > table->time_to_die)
	{
		table->dead = 1;
		pthread_mutex_unlock(&table->death_lock);
		print_status(philo, "died");
		return (true);
	}
	pthread_mutex_unlock(&table->death_lock);
	return (false);
}

bool	check_all_full(t_table *table, int full_philos)
{
	if (table->must_eat_count > 0 && full_philos == table->num_philos)
	{
		pthread_mutex_lock(&table->death_lock);
		table->dead = 1;
		pthread_mutex_unlock(&table->death_lock);
		return (true);
	}
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;
	int		full_philos;

	table = (t_table *)arg;
	while (1)
	{
		i = -1;
		full_philos = 0;
		while (++i < table->num_philos)
		{
			if (check_death(table, &table->philos[i]))
				return (NULL);
			if (table->must_eat_count > 0 && table->philos[i].meals_eaten
				>= table->must_eat_count)
				full_philos++;
		}
		if (check_all_full(table, full_philos))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

bool	is_all_eat(t_philo *philos)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	if (philos[0].table->must_eat_count == -1)
		return (false);
	while (i < philos[0].table->num_philos)
	{
		pthread_mutex_lock(&philos[i].table->death_lock);
		if (philos[i].meals_eaten >= philos[i].table->must_eat_count)
			finished++;
		pthread_mutex_unlock(&philos[i].table->death_lock);
		i++;
	}
	return (finished == philos[0].table->num_philos);
}

void	grim_reaper(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->death_lock);
		if (table->dead)
		{
			pthread_mutex_unlock(&table->death_lock);
			return ;
		}
		pthread_mutex_unlock(&table->death_lock);
		if (is_all_eat(table->philos))
		{
			pthread_mutex_lock(&table->death_lock);
			table->dead = 1;
			pthread_mutex_unlock(&table->death_lock);
			return ;
		}
		usleep(1000);
	}
}
