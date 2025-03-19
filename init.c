/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:24:05 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/15 15:57:15 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_args(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		return (printf("Usage: ./philo num_philos time_to_die time_to_eat"
				" time_to_sleep [num_times_to_eat]\n"), 1);
	table->num_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->must_eat_count = ft_atoi(argv[5]);
	else
		table->must_eat_count = -1;
	table->dead = 0;
	if (table->num_philos <= 0 || table->num_philos >= MAX_PHILOSOPHERS
		|| table->time_to_die <= 0 || table->time_to_eat <= 0
		|| table->time_to_sleep <= 0)
		return (printf("Invalid arguments\n"));
	return (0);
}

void	assign_forks(t_philo *philo)
{
	int				id;
	pthread_mutex_t	*temp;

	id = philo->id - 1;
	philo->left_fork = &philo->table->forks[id];
	philo->right_fork = &philo->table->forks[(id + 1)
		% philo->table->num_philos];
	if (id % 2 == 0)
	{
		temp = philo->left_fork;
		philo->left_fork = philo->right_fork;
		philo->right_fork = temp;
	}
}

void	init_table(t_table *table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->death_lock, NULL);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	table->start_time = get_time();
	if (!table->forks || !table->philos)
	{
		printf("Error: Memory allocation failed\n");
		exit(1);
	}
	table->start_time = get_time();
	while (i < table->num_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	init_philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = get_time();
		table->philos[i].table = table;
		assign_forks(&table->philos[i]);
		i++;
	}
}
