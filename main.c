/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:47:07 by albbermu          #+#    #+#             */
/*   Updated: 2025/02/26 20:10:44 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	t_table	table;
	
	if (parse_args(argc, argv, &table))
		return (1);
	init_table(&table);
	init_philosophers(&table);
	start_thread(&table);
	cleanup(&table);
	return (0);
}