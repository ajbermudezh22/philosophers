/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:24:05 by albbermu          #+#    #+#             */
/*   Updated: 2025/02/26 15:50:27 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_args(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		return (ft_printf("Usage: ./philo num_philos time_to_die time_to_eat time_to_sleep [num_times_to_eat]\n"), 1);
	table->num_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->must_eat_count = ft_atoi(argv[5]);
	else
		table->must_eat_count = -1;
	table->dead = 0;

	if (table->num_philos <= 0 || table->num_philos >= MAX_PHILOSOPHRERS ||
		table->time_to_die <= 0 || table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		return (ft_printf("Invalid arguments/n"));
	return (0);
}

void	init_table(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->death_lock, NULL);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	while (i <= table->num_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	init_philosophers(t_table *table)
{
	int i;

	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = get_time();
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->num_philos];
		i++;
	}
}