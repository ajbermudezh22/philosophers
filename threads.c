/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:09:53 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/30 17:40:58 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_if_dead(t_table *table)
{
	pthread_mutex_lock(&table->death_lock);
	if (table->dead)
	{
		pthread_mutex_unlock(&table->death_lock);
		pthread_exit(NULL);
	}
	pthread_mutex_unlock(&table->death_lock);
}

static void	check_meal_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	if (philo->done_eating)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		pthread_exit(NULL);
	}
	pthread_mutex_unlock(&philo->meal_lock);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (table->must_eat_count > 0)
			check_meal_status(philo);
		philo_eat(philo);
		exit_if_dead(table);
		print_status(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep);
		print_status(philo, "is thinking");
		exit_if_dead(table);
	}
	return (NULL);
}

void	start_thread(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	pthread_create(&table->monitor_thread, NULL, monitor_routine, table);
	while (i < table->num_philos)
	{
		philo = &table->philos[i];
		pthread_create(&philo->thread, NULL, philo_routine, (void *)philo);
		i++;
	}
	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->monitor_thread, NULL);
}
