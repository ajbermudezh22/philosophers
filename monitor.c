/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:06:13 by albbermu          #+#    #+#             */
/*   Updated: 2025/02/26 16:09:33 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int i;

	i = 0;
	table = (t_table *)arg;
	while (!table->dead)
	{
		while (i <= table->num_philos)
		{
			if ((get_time() - table->philos[i].last_meal) > table->time_to_die)
			{
				print_status(&table->philos[i], "died");
				table->dead = 1;
				return (NULL);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}
