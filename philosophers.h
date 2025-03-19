/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:20 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/15 15:52:37 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# define MAX_PHILOSOPHERS 250

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				num_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				must_eat_count;
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	t_philo			*philos;
}	t_table;

// init.c
int		parse_args(int argc, char **argv, t_table *table);
void	init_table(t_table *table);
void	init_philosophers(t_table *table);
void	assign_forks(t_philo *philo);

// threads.c
void	start_thread(t_table *table);
void	*philo_routine(void *arg);

// routine.c
void	philo_eat(t_philo *philo);
void	sleep_think(t_philo *philo);

// monitor.c
bool	is_all_eat(t_philo *philos);
void	grim_reaper(t_table *table);
void	*monitor_routine(void *arg);

// utils.c
size_t	get_time(void);
int		ft_usleep(size_t ms);
void	usage_error(char *s);
void	print_status(t_philo *philo, char *msg);
long	ft_atoi(const char *str);

// cleanup.c
void	cleanup(t_table *table);

#endif
