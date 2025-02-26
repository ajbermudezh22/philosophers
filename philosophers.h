/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:20 by albbermu          #+#    #+#             */
/*   Updated: 2025/02/26 16:00:41 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSPHERS_H

# include "libft/libft.h"
# include <pthread.h>
#include <sys/time.h>

# define MAX_PHILOSOPHRERS 250

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
	pthread_mutex_t print_lock;
	pthread_mutex_t death_lock;
	t_philo			*philos;
} t_table;

// utils.c
size_t	get_time(void);
int		ft_usleep(size_t ms);
void	usage_error(char *s);
void	print_status(t_philo *philo, char *msg);
void	cleanup(t_table *table);

#endif