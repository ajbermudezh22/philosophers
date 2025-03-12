/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:44:47 by albermud          #+#    #+#             */
/*   Updated: 2025/03/08 15:44:48 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_current_time(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	custom_usleep(size_t ms)
{
	size_t	start = get_current_time();
	while (get_current_time() - start < ms)
		usleep(500);
}

void	print_message(t_philosopher *philo, char *msg)
{
	t_environment *env = philo->env;

	pthread_mutex_lock(&env->print_lock);
	if (env->simulation_running)
		printf("%zu %d %s\n", get_current_time() - philo->times.start_time, philo->id, msg);
	pthread_mutex_unlock(&env->print_lock);
}
