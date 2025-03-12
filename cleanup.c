/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:47:43 by albermud          #+#    #+#             */
/*   Updated: 2025/03/08 15:47:45 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void cleanup_environment(t_environment *env)
{
    int i;

    if (!env)
        return;

    // Destroy all fork mutexes
    for (i = 0; i < env->num_philos; i++)
        pthread_mutex_destroy(&env->forks[i].mutex);

    // Destroy other mutexes
    pthread_mutex_destroy(&env->print_lock);
    pthread_mutex_destroy(&env->death_lock);

    // Free allocated memory
    if (env->forks)
    {
        free(env->forks);
        env->forks = NULL;
    }

    if (env->philosophers)
    {
        free(env->philosophers);
        env->philosophers = NULL;
    }

    printf("✅ Cleanup completed. Resources freed successfully.\n");
}
