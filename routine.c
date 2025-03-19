/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:47 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/19 13:35:09 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_take_forks(t_philo *philo)
{
	if (!philo || !philo->table)
		return ;
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	if (philo->table->num_philos == 1)
	{
		ft_usleep(philo->table->time_to_die);
		print_status(philo, "died");
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(&philo->table->death_lock);
		philo->table->dead = 1;
		pthread_mutex_unlock(&philo->table->death_lock);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
}

void	update_meal_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->death_lock);
}

void	wait_for_eating(t_philo *philo)
{
	size_t	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < philo->table->time_to_eat)
	{
		pthread_mutex_lock(&philo->table->death_lock);
		if (philo->table->dead)
		{
			pthread_mutex_unlock(&philo->table->death_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->table->death_lock);
		usleep(500);
	}
}

void	philo_eat(t_philo *philo)
{
	philo_take_forks(philo);
	if (philo->table->num_philos == 1)
	{
		usleep(philo->table->time_to_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	print_status(philo, "is eating");
	update_meal_status(philo);
	wait_for_eating(philo);
	if (philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
	if (philo->left_fork)
		pthread_mutex_unlock(philo->left_fork);
}

void	sleep_think(t_philo *philo)
{
	size_t	start_time;

	start_time = get_time();
	print_status(philo, "is sleeping");
	while ((get_time() - start_time) < philo->table->time_to_sleep)
	{
		pthread_mutex_lock(&philo->table->death_lock);
		if (philo->table->dead)
		{
			pthread_mutex_unlock(&philo->table->death_lock);
			return ;
		}
		pthread_mutex_unlock(&philo->table->death_lock);
		usleep(500);
	}
	print_status(philo, "is thinking");
}
