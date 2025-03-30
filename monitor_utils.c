/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:01:00 by albermud          #+#    #+#             */
/*   Updated: 2025/03/28 15:47:11 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_dead_and_print(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->death_lock);
	if (!table->dead)
	{
		table->dead = 1;
		pthread_mutex_unlock(&table->death_lock);
		print_status(philo, "died");
	}
	else
		pthread_mutex_unlock(&table->death_lock);
}

void	lock_unlock_meal_if_full(t_table *table, t_philo *philo, int *count)
{
	pthread_mutex_lock(&philo->meal_lock);
	if (!philo->done_eating && philo->meals_eaten >= table->must_eat_count)
	{
		philo->done_eating = true;
		(*count)++;
	}
	pthread_mutex_unlock(&philo->meal_lock);
}

bool	is_all_eat(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i].meal_lock);
		if (!table->philos[i].done_eating)
		{
			pthread_mutex_unlock(&table->philos[i].meal_lock);
			return (false);
		}
		pthread_mutex_unlock(&table->philos[i].meal_lock);
		i++;
	}
	return (true);
}
