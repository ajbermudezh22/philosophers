/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:06:13 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/01 09:23:18 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *monitor_routine(void *arg)
{
    t_table *table = (t_table *)arg;

    while (!table->dead)
    {
        grim_reaper(table); // Call grim_reaper function to check for philosopher deaths
        usleep(1000); // Small delay to prevent excessive CPU usage
    }
    return (NULL);
}


void grim_reaper(t_table *table)
{
    int i;

    i = 0;
    while (i < table->num_philos)
    {
        pthread_mutex_lock(&table->death_lock);
        if ((get_time() - table->philos[i].last_meal) > table->time_to_die)
        {
            print_status(&table->philos[i], "died");
            table->dead = 1;
            pthread_mutex_unlock(&table->death_lock);
            return;
        }
        pthread_mutex_unlock(&table->death_lock);
        i++;
    }
}

