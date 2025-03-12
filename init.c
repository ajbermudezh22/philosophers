/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:43:34 by albermud          #+#    #+#             */
/*   Updated: 2025/03/08 15:43:36 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	parse_int(char *str)
{
	int	num = atoi(str);
	if (num <= 0)
	{
		printf("Invalid argument: %s\n", str);
		exit(EXIT_FAILURE);
	}
	return (num);
}

void	init_environment(t_environment *env, char **argv)
{
	int	i;

	env->num_philos = parse_int(argv[1]);
	env->simulation_running = 1;

	// Allocate memory
	env->forks = malloc(sizeof(t_fork) * env->num_philos);
	env->philosophers = malloc(sizeof(t_philosopher) * env->num_philos);
	if (!env->forks || !env->philosophers)
	{
		printf("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	pthread_mutex_init(&env->print_lock, NULL);
	pthread_mutex_init(&env->death_lock, NULL);

	// Initialize forks
	for (i = 0; i < env->num_philos; i++)
		pthread_mutex_init(&env->forks[i].mutex, NULL);

	// Initialize philosophers
	for (i = 0; i < env->num_philos; i++)
	{
		env->philosophers[i].id = i + 1;
		env->philosophers[i].meals_eaten = 0;
		env->philosophers[i].meals_required = (argv[5]) ? parse_int(argv[5]) : -1;
		env->philosophers[i].times.time_to_die = parse_int(argv[2]);
		env->philosophers[i].times.time_to_eat = parse_int(argv[3]);
		env->philosophers[i].times.time_to_sleep = parse_int(argv[4]);
		env->philosophers[i].times.last_meal = get_current_time();
		env->philosophers[i].times.start_time = get_current_time();
		env->philosophers[i].left_fork = &env->forks[i];
		env->philosophers[i].right_fork = &env->forks[(i + 1) % env->num_philos];
		env->philosophers[i].env = env;
	}
}
