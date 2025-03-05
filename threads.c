/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:09:53 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/01 09:22:40 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->table->dead)
	{
		eat(philo);
		sleep_think(philo);
	}
	return (NULL);
}

void start_thread(t_table *table)
{
    pthread_t monitor;
    int i;

    pthread_create(&monitor, NULL, monitor_routine, table);

    i = 0;
    while (i < table->num_philos)
    {
        pthread_create(&table->philos[i].thread, NULL, philo_routine, &table->philos[i]); // Calls philo_routine
        i++;
    }

    i = 0;
    while (i < table->num_philos)
    {
        pthread_join(table->philos[i].thread, NULL);
        i++;
    }
    pthread_join(monitor, NULL);
}





