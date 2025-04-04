/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:20 by albbermu          #+#    #+#             */
/*   Updated: 2025/04/04 10:09:22 by albbermu         ###   ########.fr       */
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
# include <string.h>

# define MAX_PHILOSOPHERS 250

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	pthread_t		thread;
	pthread_mutex_t	meal_lock;
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
void	grim_reaper(t_table *table);
void	*monitor_routine(void *arg);

// monitor_utils.c
void	set_dead_and_print(t_table *table, t_philo *philo);
void	lock_unlock_meal_if_full(t_table *table, t_philo *philo, int *count);
bool	is_all_eat(t_philo *philos);

// utils.c
size_t	get_time(void);
int		ft_usleep(size_t ms);
void	usage_error(char *s);
void	print_status(t_philo *philo, char *msg);
long	ft_atoi(const char *str);

// utils_str.c
int		ft_strcmp(const char *s1, const char *s2);

// cleanup.c
void	cleanup(t_table *table);

#endif
