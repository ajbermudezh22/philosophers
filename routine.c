/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:47 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/01 09:26:23 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void eat(t_philo *philo)
{
    if (!philo || !philo->table)  // ✅ Prevent segmentation fault
        return;

    pthread_mutex_lock(philo->left_fork);
    if (philo->table)
        print_status(philo, "has taken a fork");

    pthread_mutex_lock(philo->right_fork);
    if (philo->table)
        print_status(philo, "has taken a fork");

    if (philo->table)
        print_status(philo, "is eating");

    philo->last_meal = get_time();
    philo->meals_eaten++;

    ft_usleep(philo->table->time_to_eat);

    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}




void	sleep_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
	print_status(philo, "is thinking");
}