/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:43:42 by albermud          #+#    #+#             */
/*   Updated: 2025/03/08 15:49:44 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_PHILOS 200

typedef struct s_fork
{
	pthread_mutex_t mutex;
}	t_fork;

typedef struct s_timing
{
	size_t	start_time;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	last_meal;
}	t_timing;

typedef struct s_philosopher
{
	int			id;
	int			meals_eaten;
	int			meals_required;
	t_timing	times;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread;
	struct s_environment *env;
}	t_philosopher;

typedef struct s_environment
{
	int				num_philos;
	int				simulation_running;
	t_fork			*forks;
	t_philosopher	*philosophers;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
}	t_environment;

// Function prototypes
void	init_environment(t_environment *env, char **argv);
void	start_simulation(t_environment *env);
void	*philosopher_routine(void *arg);
void	*monitor_routine(void *arg);
size_t	get_current_time(void);
void	custom_usleep(size_t ms);
void	print_message(t_philosopher *philo, char *msg);
void	cleanup_environment(t_environment *env);

#endif
