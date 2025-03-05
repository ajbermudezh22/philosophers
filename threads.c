/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:09:53 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/05 15:19:22 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (1)
    {
        pthread_mutex_lock(&philo->table->death_lock);
        if (philo->table->dead)
        {
            pthread_mutex_unlock(&philo->table->death_lock);
            break;
        }
        pthread_mutex_unlock(&philo->table->death_lock);

        eat(philo);

        pthread_mutex_lock(&philo->table->death_lock);
        if (philo->table->dead)
        {
            pthread_mutex_unlock(&philo->table->death_lock);
            break;
        }
        pthread_mutex_unlock(&philo->table->death_lock);

        sleep_think(philo);
    }

    return NULL;
}




void start_thread(t_table *table)
{
    pthread_t monitor;
    int i;

    pthread_create(&monitor, NULL, monitor_routine, table);

    i = 0;
    while (i < table->num_philos)
    {
        pthread_create(&table->philos[i].thread, NULL, philo_routine, &table->philos[i]);
        i++;
    }

    // ✅ Wait for the monitor thread first
    pthread_join(monitor, NULL);

    // ✅ Ensure all philosophers stop immediately
    pthread_mutex_lock(&table->death_lock);
    table->dead = 1;
    pthread_mutex_unlock(&table->death_lock);

    // ✅ Wait for all philosophers to finish properly
    i = 0;
    while (i < table->num_philos)
    {
        pthread_join(table->philos[i].thread, NULL);
        i++;
    }
}









