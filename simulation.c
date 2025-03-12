/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:44:15 by albermud          #+#    #+#             */
/*   Updated: 2025/03/08 15:53:18 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *philosopher_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;
    t_environment *env = philo->env;

    while (env->simulation_running)
    {
        pthread_mutex_lock(&env->death_lock);
        if (!env->simulation_running)
        {
            pthread_mutex_unlock(&env->death_lock);
            return NULL;
        }
        pthread_mutex_unlock(&env->death_lock);

        // Eating process
        pthread_mutex_lock(&philo->left_fork->mutex);
        print_message(philo, "has taken a fork");
        pthread_mutex_lock(&philo->right_fork->mutex);
        print_message(philo, "has taken a fork");

        print_message(philo, "is eating");
        pthread_mutex_lock(&env->death_lock);
        philo->times.last_meal = get_current_time();
        philo->meals_eaten++;
        pthread_mutex_unlock(&env->death_lock);
        custom_usleep(philo->times.time_to_eat);

        pthread_mutex_unlock(&philo->right_fork->mutex);
        pthread_mutex_unlock(&philo->left_fork->mutex);

        print_message(philo, "is sleeping");
        custom_usleep(philo->times.time_to_sleep);

        print_message(philo, "is thinking");
    }
    return NULL;
}

void start_simulation(t_environment *env)
{
    int i;
    pthread_t monitor;

    // ✅ Start the monitor thread
    pthread_create(&monitor, NULL, monitor_routine, env);

    // ✅ Start philosopher threads
    for (i = 0; i < env->num_philos; i++)
        pthread_create(&env->philosophers[i].thread, NULL, philosopher_routine, &env->philosophers[i]);

    // ✅ Wait for the monitor to detect a death and stop the simulation
    pthread_join(monitor, NULL);

    // ✅ Ensure all philosophers stop
    env->simulation_running = 0;

    // ✅ Wait for all philosopher threads to exit
    for (i = 0; i < env->num_philos; i++)
        pthread_join(env->philosophers[i].thread, NULL);

    printf("✅ Simulation ended, all threads finished.\n");
}


