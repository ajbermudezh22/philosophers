/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:01:00 by albermud          #+#    #+#             */
/*   Updated: 2025/03/21 17:01:27 by albermud         ###   ########.fr       */
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
	if (philo->meals_eaten >= table->must_eat_count)
		(*count)++;
	pthread_mutex_unlock(&philo->meal_lock);
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
		pthread_mutex_lock(&philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].table->must_eat_count)
			finished++;
		pthread_mutex_unlock(&philos[i].meal_lock);
		i++;
	}
	return (finished == philos[0].table->num_philos);
}
