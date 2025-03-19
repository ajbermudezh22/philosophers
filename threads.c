/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:09:53 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/19 13:43:50 by albbermu         ###   ########.fr       */
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

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	while (1)
	{
		exit_if_dead(table);
		philo_eat(philo);
		exit_if_dead(table);
		print_status(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	start_thread(t_table *table)
{
	int			i;
	pthread_t	monitor;
	t_philo		*philo;

	pthread_create(&monitor, NULL, monitor_routine, table);
	i = 0;
	while (i < table->num_philos)
	{
		philo = &table->philos[i];
		pthread_create(&philo->thread, NULL, philo_routine, (void *)philo);
		i++;
	}
	pthread_join(monitor, NULL);
	pthread_mutex_lock(&table->death_lock);
	table->dead = 1;
	pthread_mutex_unlock(&table->death_lock);
	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}
