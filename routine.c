/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:47 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/05 15:18:53 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void eat(t_philo *philo)
{
    if (!philo || !philo->table)  
        return;

    pthread_mutex_lock(philo->left_fork);
    print_status(philo, "has taken a fork");

    pthread_mutex_lock(philo->right_fork);
    print_status(philo, "has taken a fork");

    print_status(philo, "is eating");

    pthread_mutex_lock(&philo->table->death_lock);
    philo->last_meal = get_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->table->death_lock);

    // ✅ Ensure the philosopher doesn't continue eating after death
    size_t start_time = get_time();
    while ((get_time() - start_time) < philo->table->time_to_eat)
    {
        pthread_mutex_lock(&philo->table->death_lock);
        if (philo->table->dead)
        {
            pthread_mutex_unlock(&philo->table->death_lock);
            break;
        }
        pthread_mutex_unlock(&philo->table->death_lock);
        usleep(500);
    }

    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}


void sleep_think(t_philo *philo)
{
    print_status(philo, "is sleeping");

    // ✅ Ensure the philosopher doesn't continue sleeping after death
    size_t start_time = get_time();
    while ((get_time() - start_time) < philo->table->time_to_sleep)
    {
        pthread_mutex_lock(&philo->table->death_lock);
        if (philo->table->dead)
        {
            pthread_mutex_unlock(&philo->table->death_lock);
            return;
        }
        pthread_mutex_unlock(&philo->table->death_lock);
        usleep(500);
    }

    print_status(philo, "is thinking");
}
