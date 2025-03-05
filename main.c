/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:47:07 by albbermu          #+#    #+#             */
/*   Updated: 2025/03/05 14:34:44 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_table table;
    
    if (parse_args(argc, argv, &table))
        return (1);

    init_table(&table);
    init_philosophers(&table);
    start_thread(&table);
    cleanup(&table);

    // ✅ Debug message to confirm the program exits
    printf("✅ Simulation ended. Exiting program.\n");

    return (0);
}
