/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:06:13 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/05 14:34:08 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *monitor_routine(void *arg)
{
    t_table *table = (t_table *)arg;
    int i;

    while (1)
    {
        i = 0;
        while (i < table->num_philos)
        {
            pthread_mutex_lock(&table->death_lock);
            if ((get_time() - table->philos[i].last_meal) > table->time_to_die)
            {
                print_status(&table->philos[i], "died");
                table->dead = 1;  // 🚨 Stop simulation
                pthread_mutex_unlock(&table->death_lock);
                return NULL; // ✅ Exit monitoring thread
            }
            pthread_mutex_unlock(&table->death_lock);
            i++;
        }

        // ✅ Stop simulation if all have eaten enough
        if (table->must_eat_count > 0 && is_all_eat(table->philos))
        {
            pthread_mutex_lock(&table->death_lock);
            table->dead = 1;
            pthread_mutex_unlock(&table->death_lock);
            return NULL; // ✅ Exit monitoring thread
        }

        usleep(1000); // Prevent CPU overuse
    }
    return NULL;
}




bool is_all_eat(t_philo *philos)
{
    int i;
    int finished = 0;

    if (philos[0].table->must_eat_count == -1) // No eating limit
        return false;

    for (i = 0; i < philos[0].table->num_philos; i++)
    {
        pthread_mutex_lock(&philos[i].table->death_lock);
        if (philos[i].meals_eaten >= philos[i].table->must_eat_count)
            finished++;
        pthread_mutex_unlock(&philos[i].table->death_lock);
    }

    return (finished == philos[0].table->num_philos);
}


void grim_reaper(t_table *table)
{
    int i;
    while (1) // Keep monitoring until someone dies
    {
        i = 0;
        while (i < table->num_philos)
        {
            pthread_mutex_lock(&table->death_lock);
            if ((get_time() - table->philos[i].last_meal) > table->time_to_die)
            {
                print_status(&table->philos[i], "died");
                table->dead = 1;  // 🚨 Stop simulation
                pthread_mutex_unlock(&table->death_lock);
                return; // Exit grim reaper thread
            }
            pthread_mutex_unlock(&table->death_lock);
            i++;
        }

        if (is_all_eat(table->philos)) // ✅ Check if all have eaten enough
            return;

        usleep(1000); // Prevent excessive CPU usage
    }
}




