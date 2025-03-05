/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:47:53 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/05 14:06:36 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	usage_error(char *s)
{
	ft_printf("Error\n%s\n", s);
	exit(EXIT_FAILURE);
}

size_t	get_time(void)
{
	struct	timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
	
}

int	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(500);
	return (0);
}

void print_status(t_philo *philo, char *msg)
{
	if (!philo || !philo->table || !msg)
	{
		printf("DEBUG: Null value in print_status()\n");
		return;
	}

	pthread_mutex_lock(&philo->table->print_lock);
	if (!philo->table->dead)
		printf("%zu %d %s\n", get_time() - philo->table->philos[0].last_meal, philo->id, msg);
	pthread_mutex_unlock(&philo->table->print_lock);
}





void cleanup(t_table *table)
{
    int i;

    if (!table || !table->forks || !table->philos)
        return;

    i = 0;
    while (i < table->num_philos)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }

    pthread_mutex_destroy(&table->print_lock);
    pthread_mutex_destroy(&table->death_lock);

    if (table->forks)
    {
        free(table->forks);
        table->forks = NULL;
    }
    if (table->philos)
    {
        free(table->philos);
        table->philos = NULL;
    }
}

