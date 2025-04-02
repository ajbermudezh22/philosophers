/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:06:13 by albbermu          #+#    #+#             */
/*   Updated: 2025/04/02 13:36:08 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	check_death(t_table *table, t_philo *philo)
{
	size_t	time_since_meal;
	size_t	last_meal;
	size_t	now;

	pthread_mutex_lock(&philo->meal_lock);
	if (philo->done_eating)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (false);
	}
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_lock);
	now = get_time();
	time_since_meal = now - last_meal;
	if (time_since_meal > table->time_to_die)
	{
		set_dead_and_print(table, philo);
		return (true);
	}
	return (false);
}

static bool	handle_all_eat(t_table *table)
{
	if (table->must_eat_count > 0 && is_all_eat(table))
	{
		pthread_mutex_lock(&table->death_lock);
		if (!table->dead)
		{
			table->dead = 1;
			pthread_mutex_unlock(&table->death_lock);
			return (true);
		}
		pthread_mutex_unlock(&table->death_lock);
	}
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		i = -1;
		while (++i < table->num_philos)
		{
			if (check_death(table, &table->philos[i]))
				return (NULL);
		}
		if (handle_all_eat(table))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

void	grim_reaper(t_table *table)
{
	if (table->must_eat_count == -1)
		return ;
	while (1)
	{
		pthread_mutex_lock(&table->death_lock);
		if (table->dead)
		{
			pthread_mutex_unlock(&table->death_lock);
			return ;
		}
		pthread_mutex_unlock(&table->death_lock);
		if (is_all_eat(table))
		{
			pthread_mutex_lock(&table->death_lock);
			table->dead = 1;
			pthread_mutex_unlock(&table->death_lock);
			return ;
		}
		usleep(1000);
	}
}
