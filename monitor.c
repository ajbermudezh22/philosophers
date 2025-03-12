/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:44:29 by albermud          #+#    #+#             */
/*   Updated: 2025/03/08 15:52:58 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *monitor_routine(void *arg)
{
    t_environment *env = (t_environment *)arg;
    int i;

    while (env->simulation_running)
    {
        for (i = 0; i < env->num_philos; i++)
        {
            pthread_mutex_lock(&env->death_lock);
            if ((get_current_time() - env->philosophers[i].times.last_meal) > env->philosophers[i].times.time_to_die)
            {
                print_message(&env->philosophers[i], "died");
                env->simulation_running = 0;
                pthread_mutex_unlock(&env->death_lock);

                // ✅ Ensure all philosopher threads see the stop condition
                return NULL;
            }
            pthread_mutex_unlock(&env->death_lock);
        }
        usleep(1000);  // Prevent excessive CPU usage
    }
    return NULL;
}

