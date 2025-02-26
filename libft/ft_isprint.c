/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:09:57 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 15:00:45 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int main() 
{
    int test[] = {32, 126, 31, 127};  // Printable range and boundaries
    for (int i = 0; i < sizeof(test) / sizeof(int); i++) {
        printf("ft_isprint(%d) = %d (Expected: %d)\n", test[i], 
		ft_isprint(test[i]), isprint(test[i]));
    }
    return 0;
}
*/
