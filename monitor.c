/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:06:13 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/21 17:01:46 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	check_death(t_table *table, t_philo *philo)
{
	bool	is_dead;
	size_t	time_since_meal;

	is_dead = false;
	pthread_mutex_lock(&table->death_lock);
	if (table->dead)
		is_dead = true;
	pthread_mutex_unlock(&table->death_lock);
	if (is_dead)
		return (true);
	pthread_mutex_lock(&philo->meal_lock);
	time_since_meal = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->meal_lock);
	if (time_since_meal > table->time_to_die)
	{
		set_dead_and_print(table, philo);
		return (true);
	}
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
			if (table->must_eat_count > 0)
				lock_unlock_meal_if_full(table,
					&table->philos[i], &full_philos);
		}
		if (check_all_full(table, full_philos))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
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
