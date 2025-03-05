/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:20 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/01 09:24:47 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft/libft.h"
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
} t_philo;

typedef struct s_table
{
	int				num_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				must_eat_count;
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	t_philo			*philos;
} t_table;

// init.c
int     parse_args(int argc, char **argv, t_table *table);
void    init_table(t_table *table);
void    init_philosophers(t_table *table);
void    assign_forks(t_philo *philo);  // New function added

// threads.c
void    start_thread(t_table *table);
void    *philo_routine(void *arg);

// routine.c
void    eat(t_philo *philo);
void    sleep_think(t_philo *philo);

// monitor.c
void    *monitor_routine(void *arg);
void    grim_reaper(t_table *table);  // New function added

// utils.c
size_t	get_time(void);
int		ft_usleep(size_t ms);
void	usage_error(char *s);
void	print_status(t_philo *philo, char *msg);
void	cleanup(t_table *table);

#endif
